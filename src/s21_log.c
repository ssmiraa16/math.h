#include <errno.h>

#include "s21_math.h"

long double s21_log(double x) {
  double result = 0.0;
  double z = x;
  double t = 1.0;
  double eps = 1.0e-16;

  if (S21_IS_NAN(x)) {
    errno = EDOM;
    result = x;
  } else if (x < 0.0) {
    errno = EDOM;
    result = -S21_NAN;
  } else if (S21_IS_INF(x)) {
    result = x;
  } else if (x == 0.0) {
    errno = ERANGE;
    result = -1.0 / 0.0;
  } else {
    /* INVARIANT: e^result * z^t = x */
    /* BEGIN: result = 0, z = x, t = 1.0. END: z^t == 1.0 => e^result == y */
    while (z < 1.0 / S21_E || z > S21_E || t < -eps || t > eps) {
      if (z < 1.0 / S21_E) {
        z *= S21_E;
        result -= t;
      } else if (z > S21_E) {
        z /= S21_E;
        result += t;
      } else {
        t /= 2.0;
        z *= z;
      }
    }
  }

  return (result);
}
