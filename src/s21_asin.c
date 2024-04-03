#include "s21_math.h"

long double s21_asin(double x) {
  long double res = S21_NAN;
  if (x == 1 || x == -1) {
    res = S21_PI / (2 * x);
  } else if (x == 0) {
    res = 0;
  } else if (x > -1 && x < 1) {
    res = S21_PI / 2 - s21_acos(x);
  }
  return res;
}