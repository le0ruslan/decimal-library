#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int err = (dst == NULL) ? 1 : 0;

  if (!err) {
    s21_put_zero(dst);
    s21_decimal_last_bit *dec_info = s21_get_info(dst);

    if (src < 0) {
      dec_info->sign = 1;
      src *= -1;
    }
    dst->bits[0] = src;
  }

  return err;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  s21_truncate(src, &src);

  s21_decimal_last_bit *src_info = s21_get_info(&src);

  int err = s21_last_bit(&src) >= 31 || dst == NULL;

  if (!err) {
    *dst = src.bits[0];
    if (src_info->sign) {
      *dst *= -1;
    }
  }

  return err;
}

int s21_read_exp(float src) {
  int nsrc = *(uint32_t *)&src;

  int mask = 0b11111111u << 23;
  int expo = nsrc & mask;
  expo >>= 23;

  return expo - 127;
}

uint32_t s21_ftou(float num) { return *(uint32_t *)&num; }

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int err = (dst == NULL) ? 1 : 0;
  if (!err && src == 0) {
    s21_put_zero(dst);
    dst->bits[0] = src;
  } else if (!err) {
    s21_put_zero(dst);
    s21_decimal_last_bit *dst_info = s21_get_info(dst);
    int fexp = s21_read_exp(src);
    if (fexp > 95 || fexp < -95) {
      err = 1;
    } else {
      if (src < 0) {
        src = -src;
        dst_info->sign = 1;
      }
      float srct = src;
      float mul = 1.0f;
      while ((int)srct == 0) {
        dst_info->scale += 1;
        srct *= 10;
        mul *= 10;
      }
      while (srct < 10000000 && srct != (int)srct) {
        dst_info->scale += 1;
        srct *= 10;
        mul *= 10;
      }
      if (mul != 1.0f && fmodf(src * mul, 10.0f) == 0) {
        mul = mul / 10;
        dst_info->scale -= 1;
      }
      if (mul != 1.0f) {
        src *= mul;
      }
      fexp = s21_read_exp(src);
      uint32_t usrc = s21_ftou(src);
      s21_put_bit(dst, fexp, 1);
      fexp -= 1;
      int mask = 0x400000;
      while (mask > 0 && fexp >= 0) {
        int bit = !!(mask & usrc);
        s21_put_bit(dst, fexp, bit);
        mask >>= 1;
        fexp -= 1;
      }
    }
  }
  return err;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int err = (dst == NULL) ? 1 : 0;

  if (!err) {
    float res = 0.0f;
    s21_decimal_last_bit *src_info = s21_get_info(&src);

    for (int i = 0; i < MAX_SIZE; ++i) {
      if (s21_get_bit(&src, i)) {
        res += powf(2.0f, (float)i);
      }
    }

    float delim = 1.0f;
    for (int i = 0; i < src_info->scale; ++i) {
      delim = delim * 10.0f;
    }

    if (delim != 1.0f) {
      res = res / delim;
    }

    if (src_info->sign) {
      res *= -1;
    }

    *dst = res;
  }

  return err;
}