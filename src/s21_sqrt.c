#include "s21_math.h"

long double s21_sqrt(double x) {
  double eps = 1.0e-16;
  union {
    double x;
    uint64_t ix;
  } un = {x};
  int sign = un.ix >> 63;
  double result;
  double fx;

  if (S21_IS_NAN(x)) {
    errno = EDOM;
    result = x;
  } else if ((S21_IS_INF(x) && !sign) || x == 0.0) {
    result = x;
  } else if (sign) {
    errno = EDOM;
    result = -S21_NAN;
  } else {
    un.ix = ((((un.ix >> 52) + 0x3FF) >> 1) << 52) | (un.ix & 0xFFFFFFFFFFFFFL);
    result = un.x;
    do {
      fx = result;
      result = (fx + x / fx) / 2.0;
    } while (s21_fabs(fx - result) > eps);
  }

  return (result);
}
