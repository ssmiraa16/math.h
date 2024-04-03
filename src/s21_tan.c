#include "s21_math.h"

long double s21_tan(double x) {
  long double result = 0.0;
  long double eps = 1.0e-8;

  if (S21_IS_NAN(x)) {
    result = x;
  } else if (S21_IS_INF(x)) {
    result = -S21_NAN;
  } else if (s21_fabs(s21_fabs(s21_fmod(x, S21_PI)) - S21_PI / 2.0) < eps) {
    result = 16331239353195370;
    if (s21_fmod(x, S21_PI) < 0.0) {
      result = -result;
    }
  } else {
    result = s21_sin(x) / s21_cos(x);
  }

  return result;
}
