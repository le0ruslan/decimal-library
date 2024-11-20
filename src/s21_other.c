#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal* result) {
  int error = ERROR_R;
  if (result != NULL) {
    error = OK_R;
    s21_decimal_last_bit* last_bit = s21_get_info(&value);
    s21_put_zero(result);
    bool has_scale = last_bit->scale > 0;
    if (has_scale) {
      s21_truncate(value, &value);
    }
    if (last_bit->sign == SIGN_MINUS && has_scale) {
      s21_decimal number_one;
      s21_put_one(&number_one);
      s21_sum(&value, &number_one, &value);
    }
    if (!error) {
      *result = value;
    }
  }
  return error;
}

int s21_round(s21_decimal value, s21_decimal* result) {
  int error = ERROR_R;
  if (result != NULL) {
    error = OK_R;
    s21_put_zero(result);
    s21_decimal_last_bit* last_bit = s21_get_info(&value);
    s21_decimal mod = s21_shift_10_right(&value, last_bit->scale);
    last_bit->scale = 0;
    if (mod.bits[0] >= 5) {
      s21_decimal one;
      s21_put_one(&one);
      s21_sum(&value, &one, &value);
    }
    if (!error) {
      *result = value;
    }
  }
  return error;
}

int s21_truncate(s21_decimal value, s21_decimal* result) {
  int error = ERROR_R;
  if (result != NULL) {
    error = OK_R;
    s21_decimal_last_bit* last_bit = s21_get_info(&value);
    s21_shift_10_right(&value, last_bit->scale);
    last_bit->scale = 0;
    *result = value;
  }
  return error;
}

int s21_negate(s21_decimal value, s21_decimal* result) {
  int error = ERROR_R;
  if (result != NULL) {
    error = OK_R;
    *result = value;
    s21_get_info(result)->sign = !(s21_get_info(&value)->sign);
  }
  return error;
}
