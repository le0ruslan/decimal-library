#include "s21_decimal_test.h"

START_TEST(s21_from_float_to_decimal_test_1) {
  float num = 4298.3f;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)42983);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)65536);
}

START_TEST(s21_from_float_to_decimal_test_2) {
  float num = 4934.278f;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)4934278);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)196608);
}

START_TEST(s21_from_float_to_decimal_test_3) {
  float num = -13423.82f;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1342382);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147352576);
}

START_TEST(s21_from_float_to_decimal_test_4) {
  float num = -37348.28;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)3734828);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147352576);
}

START_TEST(s21_from_float_to_decimal_test_5) {
  float num = 423923;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)423923);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_float_to_decimal_test_6) {
  float num = -129312304;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)129312304);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_float_to_decimal_test_7) {
  float num = 23744.78;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)2374478);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)131072);
}

START_TEST(s21_from_float_to_decimal_test_8) {
  float num = -2393.823;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)2393823);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147287040);
}

START_TEST(s21_from_float_to_decimal_test_9) {
  float num = 912479.2;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)9124792);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)65536);
}

START_TEST(s21_from_float_to_decimal_test_10) {
  float num = -123234.7;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1232347);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147418112);
}

START_TEST(s21_from_float_to_decimal_test_11) {
  float num = 10121.7;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)101217);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)65536);
}

START_TEST(s21_from_float_to_decimal_test_12) {
  float num = -23748280;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)23748280);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147483648);
}

START_TEST(s21_from_float_to_decimal_test_13) {
  float num = 802000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)802000);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_float_to_decimal_test_14) {
  float num = 1.3331;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)13331);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)262144);
}

START_TEST(s21_from_float_to_decimal_test_15) {
  float num = -1.667283;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)1667283);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147090432);
}

START_TEST(s21_from_float_to_decimal_test_16) {
  float num = 0.5632482;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)5632482);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)458752);
}

START_TEST(s21_from_float_to_decimal_test_17) {
  float num = -0.6527385;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)6527385);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147024896);
}

START_TEST(s21_from_float_to_decimal_test_18) {
  float num = -4.294967;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)4294967);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)2147876864);
}

START_TEST(s21_from_float_to_decimal_test_19) {
  float num = 4.294967;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)4294967);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)393216);
}

START_TEST(s21_from_float_to_decimal_test_20) {
  float num = -8932.617;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)8932617);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)-2147287040);
}

START_TEST(s21_from_float_to_decimal_test_21) {
  float num = 79228162514264337593543950336.000000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 1);
}

START_TEST(s21_from_float_to_decimal_test_22) {
  float num = 0.000000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 0);
  ck_assert_uint_eq(res_bits.bits[0], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[1], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[2], (uint32_t)0);
  ck_assert_uint_eq(res_bits.bits[3], (uint32_t)0);
}

START_TEST(s21_from_float_to_decimal_test_23) {
  float num = 1.0e-30f;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 1);
}

START_TEST(s21_from_float_to_decimal_test_24) {
  float num = 1.0e30f;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 1);
}

START_TEST(s21_from_float_to_decimal_test_25) {
  float num = 79228162514264337593543950336.000000;
  s21_decimal res_bits = {{0, 0, 0, 0}};

  int res = s21_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(res, 1);
}

Suite *s21_from_float_to_decimal_suite(void) {
  Suite *s = suite_create("s21_from_float_to_decimal");
  TCase *o = tcase_create("from_float_to_decimal");

  tcase_add_test(o, s21_from_float_to_decimal_test_1);
  tcase_add_test(o, s21_from_float_to_decimal_test_2);
  tcase_add_test(o, s21_from_float_to_decimal_test_3);
  tcase_add_test(o, s21_from_float_to_decimal_test_4);
  tcase_add_test(o, s21_from_float_to_decimal_test_5);
  tcase_add_test(o, s21_from_float_to_decimal_test_6);
  tcase_add_test(o, s21_from_float_to_decimal_test_7);
  tcase_add_test(o, s21_from_float_to_decimal_test_8);
  tcase_add_test(o, s21_from_float_to_decimal_test_9);
  tcase_add_test(o, s21_from_float_to_decimal_test_10);
  tcase_add_test(o, s21_from_float_to_decimal_test_11);
  tcase_add_test(o, s21_from_float_to_decimal_test_12);
  tcase_add_test(o, s21_from_float_to_decimal_test_13);
  tcase_add_test(o, s21_from_float_to_decimal_test_14);
  tcase_add_test(o, s21_from_float_to_decimal_test_15);
  tcase_add_test(o, s21_from_float_to_decimal_test_16);
  tcase_add_test(o, s21_from_float_to_decimal_test_17);
  tcase_add_test(o, s21_from_float_to_decimal_test_18);
  tcase_add_test(o, s21_from_float_to_decimal_test_19);
  tcase_add_test(o, s21_from_float_to_decimal_test_20);
  tcase_add_test(o, s21_from_float_to_decimal_test_21);
  tcase_add_test(o, s21_from_float_to_decimal_test_22);
  tcase_add_test(o, s21_from_float_to_decimal_test_23);
  tcase_add_test(o, s21_from_float_to_decimal_test_24);
  tcase_add_test(o, s21_from_float_to_decimal_test_25);

  suite_add_tcase(s, o);
  return s;
}
