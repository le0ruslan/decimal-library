#include "s21_decimal.h"

s21_decimal_last_bit* s21_get_info(s21_decimal* arr) {
  return (s21_decimal_last_bit*)(arr->bits + 3);
}

void s21_put_bit(s21_decimal* arr, int i, int sign) {
  if (!sign) {
    arr->bits[i / 32] &= ~(1u << i % 32);
  } else {
    arr->bits[i / 32] |= 1u << i % 32;
  }
}

int s21_get_bit(const s21_decimal* arr, int i) {
  uint32_t mask = 1u << (i % 32);
  return !!(arr->bits[i / 32] & mask);
}

int s21_last_bit(s21_decimal* arr) {
  int index = -1;
  for (int i = MAX_SIZE - 1; i >= 0 && index == -1; i--) {
    if (s21_get_bit(arr, i)) index = i;
  }
  return index;
}

bool s21_can_10_shift(const s21_decimal* arr) {
  return !(s21_get_bit(arr, MAX_SIZE - 1) || s21_get_bit(arr, MAX_SIZE - 2) ||
           s21_get_bit(arr, MAX_SIZE - 3) || s21_get_bit(arr, MAX_SIZE - 4));
}

int s21_shift_left(s21_decimal* arr, int shift) {
  int error = OK_R;
  int sign_idx = s21_last_bit(arr);

  if (sign_idx != -1 && sign_idx > MAX_SIZE - shift - 1) {
    error = OVERFLOW_R;
  }
  if (!error) {
    for (int i = MAX_SIZE - shift - 1; i >= 0; i--) {
      s21_put_bit(arr, i + shift, s21_get_bit(arr, i));
    }
    for (int i = 0; i < shift; ++i) {
      s21_put_bit(arr, i, 0);
    }
  }
  return error;
}

int s21_shift_10_left(s21_decimal* arr, int shift) {
  int error = OK_R;
  int flag = 0;
  for (int i = 0; i < shift && !error; i++) {
    flag = 0;
    s21_decimal n1 = *arr;
    s21_decimal n2 = *arr;
    error = s21_shift_left(&n1, 3);
    if (error) flag = 1;
    if (!flag) {
      s21_shift_left(&n2, 1);
      error = s21_sum(&n1, &n2, arr);
    }
  }
  if (error) error = OVERFLOW_R;
  return error;
}

void s21_shift_right(s21_decimal* arr, int shift) {
  for (int i = shift; i < MAX_SIZE; i++) {
    s21_put_bit(arr, i - shift, s21_get_bit(arr, i));
  }
}

s21_decimal s21_shift_10_right(s21_decimal* arr, int shift) {
  s21_decimal ten = {.bits = {10, 0, 0, 0}};
  s21_decimal mod = (s21_decimal){.bits = {0, 0, 0}};
  for (int i = 0; i < shift; ++i) {
    mod = s21_div_int(*arr, ten, arr);
  }

  return mod;
}

int s21_sum(s21_decimal* val1, s21_decimal* val2, s21_decimal* result) {
  int sign1 = 0;
  int sign2 = 0;
  int tmp = 0;
  for (int i = 0; i < MAX_SIZE; i++) {
    sign1 = s21_get_bit(val1, i);
    sign2 = s21_get_bit(val2, i);
    s21_put_bit(result, i, sign1 ^ sign2 ^ tmp);
    tmp = (sign1 && sign2) || ((sign1 || sign2) && tmp);
  }
  return tmp;
}

void s21_reverse(s21_decimal* arr) {
  for (int i = 0; i < 3; i++) {
    arr->bits[i] = ~(arr->bits[i]);
  }
}

void s21_reverse_to_pos(s21_decimal* arr) {
  s21_decimal max_size;
  s21_put_max(&max_size);
  s21_sum(arr, &max_size, arr);
  s21_reverse(arr);
}

void s21_reverse_to_neg(s21_decimal* arr) {
  s21_decimal min_size;
  s21_put_one(&min_size);
  s21_reverse(arr);
  s21_sum(arr, &min_size, arr);
}

bool s21_is_zero(s21_decimal* arr) {
  return arr->bits[0] == 0 && arr->bits[1] == 0 && arr->bits[2] == 0;
}

bool s21_is_max(s21_decimal* arr) {
  return arr->bits[0] == UINT32_MAX && arr->bits[1] == UINT32_MAX &&
         arr->bits[2] == UINT32_MAX;
}

void s21_put_zero(s21_decimal* arr) {
  for (int i = 0; i < 4; ++i) arr->bits[i] = 0;
}

void s21_put_one(s21_decimal* arr) {
  arr->bits[0] = 1;
  arr->bits[1] = 0;
  arr->bits[2] = 0;
  arr->bits[3] = 0;
}

void s21_put_max(s21_decimal* arr) {
  for (int i = 0; i < 4; i++) arr->bits[i] = UINT32_MAX;
  arr->bits[3] = 0;
}

int s21_equalize_scale(s21_decimal* value1, s21_decimal* value2, bool b_round) {
  int error = OK_R;
  s21_decimal_last_bit* last_bit1 = s21_get_info(value1);
  s21_decimal_last_bit* last_bit2 = s21_get_info(value2);
  int scale1 = last_bit1->scale;
  int scale2 = last_bit2->scale;
  int min_scale = scale1 < scale2 ? scale1 : scale2;
  int max_scale = scale1 < scale2 ? scale2 : scale1;
  s21_decimal* min_dec = min_scale == scale1 ? value1 : value2;
  s21_decimal* max_dec = max_scale == scale1 ? value1 : value2;
  s21_decimal_last_bit* min_last_bit =
      min_scale == scale1 ? last_bit1 : last_bit2;
  s21_decimal_last_bit* max_last_bit =
      max_scale == scale1 ? last_bit1 : last_bit2;

  if (min_scale != max_scale) {
    int scale_result = max_scale - min_scale;
    for (int i = 0; i < scale_result && s21_can_10_shift(min_dec); i++) {
      s21_shift_10_left(min_dec, 1);
      min_scale += 1;
      min_last_bit->scale = min_scale;
    }
  }
  if (min_scale != max_scale) {
    int scale_result = max_scale - min_scale;
    s21_shift_10_right(max_dec, scale_result);
    max_last_bit->scale = min_scale;
    if (b_round && s21_is_zero(max_dec)) {
      int sign = last_bit1->sign != last_bit2->sign;
      if (sign == SIGN_MINUS) {
        s21_put_bit(min_dec, 0, 0);
      } else {
        if (s21_is_max(min_dec)) {
          error = OVERFLOW_R;
        } else {
          if (s21_get_bit(min_dec, 0)) {
            s21_decimal one;
            s21_put_one(&one);
            s21_sum(min_dec, &one, min_dec);
          }
        }
      }
    }
  }

  return error;
}
