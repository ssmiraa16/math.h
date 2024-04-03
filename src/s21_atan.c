#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (x == S21_INF_POS) {
    res = S21_PI / 2;
  } else if (x == S21_INF_NEG) {
    res = -S21_PI / 2;
  } else if (x != x) {
    res = x;
  } else if (x == 1) {
    res = S21_PI / 4;
  } else if (x == -1) {
    res = -S21_PI / 4;
  } else {
    int check = (x > -1 && x < 1);
    res = check ? x : 1.0 / x;
    for (int i = 1; i < 7000; i++) {
      double a = s21_pow(-1, i);
      double b = s21_pow(x, (1 + 2 * i) * (check ? 1 : -1));
      double n = 1 + 2 * i;
      res += a * b / n;
    }
    if (!check) {
      res = (S21_PI * s21_fabs(x) / (2 * x)) - res;
    }
  }
  return res;
}