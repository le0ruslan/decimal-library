#ifndef __S21_DECIMAL__
#define __S21_DECIMAL__

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define LOWER -1
#define EQUALS 0
#define GREATER 1

#define MAX_SIZE 96
#define SIGN_PLUS 0
#define SIGN_MINUS 1

#define OK_R 0
#define ERROR_R 1
#define INF_POSITIVE 1
#define INF_NEGATIVE 2
#define OVERFLOW_R 4

typedef struct {
  uint32_t bits[4];
} s21_decimal;

typedef struct {
  uint32_t useless_bits_1 : 16;
  uint32_t scale : 8;
  uint32_t useless_bits_2 : 7;
  uint32_t sign : 1;
} s21_decimal_last_bit;

// Arithmetic - start
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
s21_decimal s21_div_int(s21_decimal val1, s21_decimal val2,
                        s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
// Arithemtic - end

// Compare - start
int s21_is_greater_int(s21_decimal* val1, s21_decimal* val2);
int s21_is_lower_int(s21_decimal* val1, s21_decimal* val2);
int s21_is_equals_int(s21_decimal* val1, s21_decimal* val2);
int s21_is_less(s21_decimal val1, s21_decimal val2);
int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_greater(s21_decimal val1, s21_decimal val2);
int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_equal(s21_decimal val1, s21_decimal val2);
int s21_is_not_equal(s21_decimal val1, s21_decimal val2);
// Compare - end

// Converter - start
int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);
// Converter - end

// Other - start
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);
int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
// Other - end

// additional_functions - start
s21_decimal_last_bit* s21_get_info(s21_decimal* arr);
void s21_put_bit(s21_decimal* arr, int i, int sign);
int s21_get_bit(const s21_decimal* arr, int i);
int s21_last_bit(s21_decimal* arr);
bool s21_can_10_shift(const s21_decimal* arr);
int s21_shift_left(s21_decimal* arr, int shift);
int s21_shift_10_left(s21_decimal* arr, int shift);
void s21_shift_right(s21_decimal* arr, int shift);
s21_decimal s21_shift_10_right(s21_decimal* arr, int shift);
int s21_sum(s21_decimal* val1, s21_decimal* val2, s21_decimal* result);
void s21_reverse(s21_decimal* arr);
void s21_reverse_to_pos(s21_decimal* arr);
void s21_reverse_to_neg(s21_decimal* arr);
bool s21_is_zero(s21_decimal* arr);
bool s21_is_max(s21_decimal* arr);
void s21_put_zero(s21_decimal* arr);
void s21_put_one(s21_decimal* arr);
void s21_put_max(s21_decimal* arr);
int s21_equalize_scale(s21_decimal* value1, s21_decimal* value2, bool b_round);
// additional_function - end

#endif  // __S21_DECIMAL__