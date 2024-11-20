#include "s21_decimal_test.h"

START_TEST(s21_from_int_to_decimal_test_1) {
  int num = INT_MAX;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)INT_MAX);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_2) {
  int num = INT_MIN;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)INT_MIN);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_3) {
  int num = -1;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_4) {
  int num = -72342934;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)72342934);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_5) {
  int num = 82000000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)82000000);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_6) {
  int num = 734892824;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)734892824);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_7) {
  int num = -9174892;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)9174892);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_8) {
  int num = -23478432;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)23478432);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_9) {
  int num = -283434;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)283434);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_10) {
  int num = 2347;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)2347);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_11) {
  int num = 28823;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)28823);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_12) {
  int num = 199000000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)199000000);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_13) {
  int num = -2340000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)2340000);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_14) {
  int num = 3456789;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)3456789);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_15) {
  int num = 912384;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)912384);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_16) {
  int num = -23849234;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)23849234);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_17) {
  int num = 1;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_18) {
  int num = 0;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_int_to_decimal_test_19) {
  int num = -27234;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)27234);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_int_to_decimal_test_20) {
  int num = -811231;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_int_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)811231);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

Suite *s21_from_int_to_decimal_suite(void) {
  Suite *s = suite_create("s21_from_int_to_decimal");
  TCase *o = tcase_create("from_int_to_decimal");

  tcase_add_test(o, s21_from_int_to_decimal_test_1);
  tcase_add_test(o, s21_from_int_to_decimal_test_2);
  tcase_add_test(o, s21_from_int_to_decimal_test_3);
  tcase_add_test(o, s21_from_int_to_decimal_test_4);
  tcase_add_test(o, s21_from_int_to_decimal_test_5);
  tcase_add_test(o, s21_from_int_to_decimal_test_6);
  tcase_add_test(o, s21_from_int_to_decimal_test_7);
  tcase_add_test(o, s21_from_int_to_decimal_test_8);
  tcase_add_test(o, s21_from_int_to_decimal_test_9);
  tcase_add_test(o, s21_from_int_to_decimal_test_10);
  tcase_add_test(o, s21_from_int_to_decimal_test_11);
  tcase_add_test(o, s21_from_int_to_decimal_test_12);
  tcase_add_test(o, s21_from_int_to_decimal_test_13);
  tcase_add_test(o, s21_from_int_to_decimal_test_14);
  tcase_add_test(o, s21_from_int_to_decimal_test_15);
  tcase_add_test(o, s21_from_int_to_decimal_test_16);
  tcase_add_test(o, s21_from_int_to_decimal_test_17);
  tcase_add_test(o, s21_from_int_to_decimal_test_18);
  tcase_add_test(o, s21_from_int_to_decimal_test_19);
  tcase_add_test(o, s21_from_int_to_decimal_test_20);

  suite_add_tcase(s, o);
  return s;
}
