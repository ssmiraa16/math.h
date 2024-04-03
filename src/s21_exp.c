#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1;
  if (x == S21_INF_NEG) {
    res = 0;
  } else if (x != x) {
    res = S21_NAN;
  } else {
    int n = 1;
    long double a = x, sum = 1;
    if (x < 0.0) {
      a = -x;
    }
    for (int i = 0; i < 1600; i++) {
      sum *= a / n;
      n++;
      res += sum;
    }
    if (x < 0.0) {
      res = 1 / res;
    }
  }
  return res;
}