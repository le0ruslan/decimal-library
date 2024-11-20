#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int error = OK_R;
  s21_put_zero(result);
  s21_decimal_last_bit* last_bit1 = s21_get_info(&value_1);
  s21_decimal_last_bit* last_bit2 = s21_get_info(&value_2);
  s21_decimal_last_bit* res_last_bit = s21_get_info(result);
  if (!s21_is_zero(&value_1) && !s21_is_zero(&value_2)) {
    error = s21_equalize_scale(&value_1, &value_2, true);
  }
  if (s21_is_zero(&value_1) && !error) last_bit1->sign = 0;
  if (s21_is_zero(&value_2) && !error) last_bit2->sign = 0;
  int sign1 = last_bit1->sign;
  int sign2 = last_bit2->sign;
  bool sign_difference = sign1 != sign2;
  int sign = SIGN_PLUS;
  if (sign1 == SIGN_MINUS && sign2 == SIGN_MINUS) sign = SIGN_MINUS;
  if (sign_difference) {
    if (sign1 == SIGN_MINUS) s21_reverse_to_neg(&value_1);
    if (sign2 == SIGN_MINUS) s21_reverse_to_neg(&value_2);
  }
  if (!error) {
    int tmp = s21_sum(&value_1, &value_2, result);
    if ((sign1 == SIGN_MINUS || sign2 == SIGN_MINUS) && sign_difference) {
      sign = sign1 ^ sign2 ^ tmp;
    } else if (tmp) {
      error = OVERFLOW_R;
    }
  }
  if (!error) {
    if (sign == SIGN_MINUS && sign_difference) {
      s21_reverse_to_pos(result);
    }
    res_last_bit->sign = sign;
    res_last_bit->scale = last_bit1->scale;
  } else {
    s21_put_zero(result);
  }
  if (error == OVERFLOW_R) {
    error = sign == SIGN_PLUS ? INF_POSITIVE : INF_NEGATIVE;
  }
  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_decimal_last_bit* last_bit2 = s21_get_info(&value_2);
  last_bit2->sign ^= 1;
  return s21_add(value_1, value_2, result);
}

s21_decimal s21_div_int(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal* result) {
  for (int i = 0; i < 3; i++) {
    result->bits[i] = 0;
  }
  int len1 = 0;
  int len2 = s21_last_bit(&value_2);
  int len3 = 0;
  s21_decimal v2_container = value_2;
  while (s21_is_equals_int(&value_1, &value_2) ||
         s21_is_greater_int(&value_1, &value_2)) {
    len1 = s21_last_bit(&value_1);
    len3 = len1 - len2;
    s21_shift_left(&value_2, len3);
    if (s21_is_greater_int(&value_2, &value_1)) {
      s21_shift_right(&value_2, 1);
      len3 -= 1;
    }
    s21_reverse_to_neg(&value_2);
    s21_sum(&value_1, &value_2, &value_1);
    s21_decimal res;
    s21_put_one(&res);
    s21_shift_left(&res, len3);
    s21_sum(result, &res, result);
    value_2 = v2_container;
  }
  s21_decimal mod = value_1;
  return mod;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_put_one(&value_1);
  s21_put_one(&value_2);
  for (int i = 0; i < 3; i++) {
    result->bits[i] = 0;
  }
  s21_sum(&value_1, &value_2, result);
  return 0;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  s21_put_one(&value_1);
  s21_put_one(&value_2);
  for (int i = 0; i < 3; i++) {
    result->bits[i] = 0;
  }
  s21_sum(&value_1, &value_2, result);
  return 0;
}
