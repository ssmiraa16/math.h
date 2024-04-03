#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = 0;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    res = x;
  } else {
    int integer = (int)x;
    integer += (x > 0 && (x - integer));
    res = integer;
    if (res == 0 && x < 0) {
      res = -res;
    }
  }
  return res;
}