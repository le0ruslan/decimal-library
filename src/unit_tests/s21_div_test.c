#include "s21_decimal_test.h"

START_TEST(s21_div_test_1) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_div(a, b, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)2);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}
END_TEST

Suite *s21_div_suite(void) {
  Suite *s = suite_create("s21_div");
  TCase *o = tcase_create("div");

  tcase_add_test(o, s21_div_test_1);

  suite_add_tcase(s, o);
  return s;
}
