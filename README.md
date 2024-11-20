# s21_decimal

## Project Description

**s21_decimal** is a static library implemented in the C programming language. It introduces the `decimal` data type, which is not available in the standard C data types. This type ensures high-precision calculations, making it essential for financial operations and other fields where minimal calculation errors are critical.

### Features and Capabilities

- **Precision and Range:**  
  The `decimal` type supports values in the range from -79,228,162,514,264,337,593,543,950,335 to +79,228,162,514,264,337,593,543,950,335.

- **Binary Representation:**  
  A `decimal` number is represented as an array of four 32-bit integers:
   - `bits[0]`, `bits[1]`, `bits[2]` – the 96-bit integer value.
   - `bits[3]` – contains the sign, scaling factor, and reserved bits.

- **Arithmetic Operations:**  
  The library provides support for addition, subtraction, multiplication, division, and modulus operations.

- **Comparison Operators:**  
  Includes functionality to compare values using operators such as less than, greater than, equal to, and others.

- **Conversion Functions:**  
  Allows conversion between `decimal` and standard data types such as `int` and `float`.

- **Additional Utilities:**  
  Functions for rounding, truncation, negation, and flooring are also included.

---

## Binary Representation

A `decimal` number is represented as:
- A 96-bit integer (stored across `bits[0]`, `bits[1]`, `bits[2]`).
- A scaling factor (10^0 to 10^28) that specifies the position of the decimal point.
- A sign bit in `bits[3]` (0 for positive, 1 for negative).

### Example Structure:
```c
typedef struct {
    int bits[4];
} s21_decimal;
```

---

## Library Functions

### Arithmetic Operators

| Operator name | Operators  | Function                                                                           | 
| ------ | ------ |------------------------------------------------------------------------------------|
| Addition | + | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Subtraction | - | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Multiplication | * | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) | 
| Division | / | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

The functions return the error code:
- 0 - OK
- 1 - the number is too large or equal to infinity
- 2 - the number is too small or equal to negative infinity
- 3 - division by 0

*Note on the numbers that do not fit into the mantissa:*
- *When getting numbers that do not fit into the mantissa during arithmetic operations, use bank rounding (for example, 79,228,162,514,264,337,593,543,950,335 - 0.6 = 79,228,162,514,264,337,593,543,950,334)*

### Comparison Operators

| Operator name | Operators  | Function | 
| ------ | ------ | ------ |
| Less than | < | int s21_is_less(s21_decimal, s21_decimal) |
| Less than or equal to | <= | int s21_is_less_or_equal(s21_decimal, s21_decimal) | 
| Greater than | > |  int s21_is_greater(s21_decimal, s21_decimal) |
| Greater than or equal to | >= | int s21_is_greater_or_equal(s21_decimal, s21_decimal) | 
| Equal to | == |  int s21_is_equal(s21_decimal, s21_decimal) |
| Not equal to | != |  int s21_is_not_equal(s21_decimal, s21_decimal) |

Return value:
- 0 - FALSE
- 1 - TRUE

### Convertors and parsers

| Convertor/parser | Function | 
| ------ | ------ |
| From int  | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| From float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| To int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| To float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Return value - code error:
- 0 - OK
- 1 - convertation error

*Note on the conversion of a float type number:*
- *If the numbers are too small (0 < |x| < 1e-28), return an error and value equal to 0*
- *If the numbers are too large (|x| > 79,228,162,514,264,337,593,543,950,335) or are equal to infinity, return an error*
- *When processing a number with the float type, convert all the significant decimal digits contained in it. If there are more than 7 such digits, the number is rounded to the closest one that does not have more than 7 significant decimal digits.*

*Note on the conversion from decimal type to int:*
- *If there is a fractional part in a decimal number, it should be discarded (for example, 0.9 is converted to 0)*


### Another functions

| Description | Function                                                         | 
| ------ |------------------------------------------------------------------|
| Rounds a specified Decimal number to the closest integer toward negative infinity. | int s21_floor(s21_decimal value, s21_decimal *result)            |	
| Rounds a decimal value to the nearest integer. | int s21_round(s21_decimal value, s21_decimal *result)    |
| Returns the integral digits of the specified Decimal; any fractional digits are discarded, including trailing zeroes. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Returns the result of multiplying the specified Decimal value by negative one. | int s21_negate(s21_decimal value, s21_decimal *result)   |

Return value - code error:
- 0 - OK
- 1 - calculation error
---

## Library Functions

* The library is implemented in C (C11 standard) and compiled with gcc.
* It adheres to Google C++ Style Guide.
* Functions are covered by unit tests using the Check library with 80% or more code coverage.
* A Makefile is included with targets:
  - all: Builds the library and tests.
  - clean: Cleans build artifacts.
  - test: Runs unit tests.
  - gcov_report: Generates a code coverage report in HTML format.
* The library is distributed as a static library s21_decimal.a with the header file s21_decimal.h.
