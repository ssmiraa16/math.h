#include "s21_math.h"

long double s21_sin(double x) {
  long double result;
  long double k;
  long double a;
  long double eps = 1.0e-16;

  if (S21_IS_NAN(x)) {
    result = x;
  } else if (S21_IS_INF(x)) {
    result = -S21_NAN;
  } else {
    x = s21_fmod(x, 2.0 * S21_PI);
    if (x > S21_PI) {
      x -= 2.0 * S21_PI;
    } else if (x < -S21_PI) {
      x += 2.0 * S21_PI;
    }
    a = x;
    k = 1.0;
    result = 0.0;
    while (s21_fabs(a) > eps) {
      result += a;
      a = ((-a) * x * x) / ((k + 1.0) * (k + 2.0));
      k += 2.0;
    }
  }

  return (result);
}
