#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if (S21_IS_NAN(x)) {
    result = x;
  } else if (S21_IS_NAN(y)) {
    result = y;
  } else if (S21_IS_INF(x)) {
    result = -S21_NAN;
  } else if (S21_IS_INF(y)) {
    result = x;
  } else if (y == 0.0) {
    result = S21_NAN;
  } else if (x == 0.0) {
    result = x;
  } else {
    result = (x - s21_trunc(x / y) * y);
  }
  return result;
}
