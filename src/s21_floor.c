#include "s21_math.h"

long double s21_floor(double num) {
  long double result;
  if (num >= LLONG_MAX || num <= LLONG_MIN || num != num) {
    result = num;
  } else {
    long long n = (long long)num;
    long double fractpart = num - n;
    long double d = (long double)n;
    if (fractpart == 0) {
      result = d;
    } else {
      result = num >= 0 ? d : d - 1;
    }
  }
  return result;
}
