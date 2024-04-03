#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result;
  long double fractpart;
  long double eps = 1.0e-16;

  if (exp == 0.0) {
    result = 1.0;
  } else if (S21_IS_NAN(base)) {
    if (s21_fabs(s21_fabs(exp) - 1.0) < eps) {
      result = S21_NAN;
    } else {
      result = base;
    }
  } else if (s21_fabs(exp - 1.0) < eps) {
    result = base;
  } else if (s21_fabs(exp + 1.0) < eps) {
    result = 1.0 / base;
  } else if (S21_IS_NAN(exp)) {
    if (s21_fabs(base - 1.0) < eps) {
      result = 1.0;
    } else {
      result = exp;
    }
  } else if (S21_IS_INF(base)) {
    if (S21_IS_INF(exp)) {
      if (exp > 0.0) {
        result = S21_INF_POS;
      } else {
        result = 0.0;
      }
    } else if (exp < 0.0) {
      if (s21_fabs(s21_trunc(exp) - exp) < eps) {
        result = base > 0.0 ? 0.0 : -0.0;
      } else {
        result = 0.0;
      }
    } else if (s21_fabs(s21_fmod(exp, 2.0) - 1.0) < eps) {
      result = base;
    } else {
      result = S21_INF_POS;
    }
  } else if (S21_IS_INF(exp)) {
    if (s21_fabs(s21_fabs(base) - 1.0) < eps) {
      result = 1.0;
    } else if (s21_fabs(base) < eps) {
      result = exp > 0.0 ? 0.0 : S21_INF_POS;
    } else if (s21_fabs(base) < 1.0) {
      result = exp > 0.0 ? 0.0 : S21_INF_POS;
    } else {
      result = exp > 0.0 ? S21_INF_POS : 0.0;
    }
  } else if (s21_fabs(base) < eps) {
    if (exp < 0.0) {
      result = S21_INF_POS;
    } else {
      result = 0.0;
    }
  } else if (base < 0) {
    fractpart = s21_trunc(exp) - exp;
    if (s21_fabs(fractpart) > S21_E)
      result = -S21_NAN;
    else {
      result = s21_integer_pow(base, exp);
    }
  } else {
    fractpart = exp - s21_trunc(exp);
    result = s21_integer_pow(base, exp);
    if (s21_fabs(fractpart) > eps) {
      result *= s21_exp(fractpart * s21_log(base));
    }
  }

  return (result);
}
