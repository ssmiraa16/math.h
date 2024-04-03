#include "s21_math.h"

long double s21_integer_pow(double base, double e) {
  long double k;
  long double b;
  long double result;
  k = s21_trunc(e);
  b = base;
  result = 1.0;
  /* INVARIANT: b^k * result = base^e */
  while (s21_fabs(k) > 0.1) {
    if (k > 0.0) {
      if (s21_fabs(s21_fmod(k, 2.0)) < 0.1) {
        b *= b;
        k /= 2.0;
      } else {
        k -= 1.0;
        result *= b;
      }
    } else {
      if (s21_fabs(s21_fmod(k, 2.0)) < 0.1) {
        b *= b;
        k /= 2.0;
      } else {
        k += 1.0;
        result /= b;
      }
    }
  }
  return ((double)result);
}
