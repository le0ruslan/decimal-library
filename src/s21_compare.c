#include "s21_decimal.h"

int s21_check_num(uint32_t n1, uint32_t n2) {
  int result = EQUALS;
  if (n1 > n2)
    result = GREATER;
  else if (n1 < n2)
    result = LOWER;
  return result;
}

int s21_is_greater_int(s21_decimal* val1, s21_decimal* val2) {
  int result = s21_check_num(val1->bits[2], val2->bits[2]);
  if (!result) {
    result = s21_check_num(val1->bits[1], val2->bits[1]);
  }
  if (!result) {
    result = s21_check_num(val1->bits[0], val2->bits[0]);
  }
  result = result == GREATER;
  return result;
}

int s21_is_lower_int(s21_decimal* val1, s21_decimal* val2) {
  int res = s21_check_num(val1->bits[2], val2->bits[2]);
  if (!res) {
    res = s21_check_num(val1->bits[1], val2->bits[1]);
  }
  if (!res) {
    res = s21_check_num(val1->bits[0], val2->bits[0]);
  }
  res = res == LOWER;
  return res;
}

int s21_is_equals_int(s21_decimal* val1, s21_decimal* val2) {
  return val1->bits[0] == val2->bits[0] && val1->bits[1] == val2->bits[1] &&
         val1->bits[2] == val2->bits[2];
}

int s21_is_equal(s21_decimal val1, s21_decimal val2) {
  s21_decimal_last_bit* v1_info = s21_get_info(&val1);
  s21_decimal_last_bit* v2_info = s21_get_info(&val2);

  int res = s21_is_equals_int(&val1, &val2);

  if (v1_info->scale != v2_info->scale) {
    res = 0;
  }

  if (v1_info->sign != v2_info->sign) {  // проверка знака
    res = 0;
  }

  return res;
}

int s21_is_not_equal(s21_decimal val1, s21_decimal val2) {
  return !s21_is_equal(val1, val2);
}

int s21_is_less(s21_decimal val1, s21_decimal val2) {
  s21_decimal_last_bit* info1 = s21_get_info(&val1);
  s21_decimal_last_bit* info2 = s21_get_info(&val2);

  s21_equalize_scale(&val1, &val2,
                     0);  // нормализация коэффициентов масштабирования
  int res = 0;

  if (info1->sign == SIGN_PLUS && info2->sign == SIGN_PLUS) {
    res = s21_is_lower_int(&val1, &val2);
  } else if (info1->sign == SIGN_MINUS && info2->sign == SIGN_MINUS) {
    res = s21_is_greater_int(&val1, &val2);
  } else {
    res = !(info2->sign);
  }

  return res;
}

int s21_is_greater(s21_decimal val1, s21_decimal val2) {
  s21_decimal_last_bit* info1 = s21_get_info(&val1);
  s21_decimal_last_bit* info2 = s21_get_info(&val2);

  s21_equalize_scale(&val1, &val2, 0);
  int res = 0;

  if (info1->sign == SIGN_PLUS && info2->sign == SIGN_PLUS) {
    res = s21_is_greater_int(&val1, &val2);
  } else if (info1->sign == SIGN_MINUS && info2->sign == SIGN_MINUS) {
    res = s21_is_lower_int(&val1, &val2);
  } else {
    res = !(info1->sign);
  }
  return res;
}

int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2) {
  s21_equalize_scale(&val1, &val2, 0);
  int res = s21_is_less(val1, val2) == 1 || s21_is_equal(val1, val2) == 1;
  return res;
}

int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2) {
  s21_equalize_scale(&val1, &val2, 0);
  int res = s21_is_greater(val1, val2) == 1 || s21_is_equal(val1, val2) == 1;
  return res;
}