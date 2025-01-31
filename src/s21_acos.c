#include "s21_math.h"

long double s21_acos(double x) {
  long double res = S21_NAN;
  if (x == -1) {
    res = S21_PI;
  } else if (x == 1) {
    res = 0;
  } else if (x < 1 && x > 0) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x < 0 && x > -1) {
    res = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x == 0) {
    res = S21_PI / 2;
  }
  return res;
}