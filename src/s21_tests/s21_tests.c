#include "s21_tests_main.h"

START_TEST(abs_test) {
  // ck_assert_int_eq(s21_abs((int)(1.0/0.0)), abs((int)(1.0/0.0)));
  // ck_assert_int_eq(s21_abs((int)(-1.0/0.0)), abs((int)(-1.0/0.0)));
  // ck_assert_int_eq(s21_abs((int)(0.0/0.0)), abs((int)(0.0/0.0)));
  ck_assert_int_eq(s21_abs(-10), abs(-10));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
}
END_TEST

START_TEST(cos_test) {
  ck_assert_ldouble_nan(s21_cos(S21_INF_NEG));
  ck_assert_ldouble_nan(s21_cos(S21_INF_POS));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1.1), cos(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(5.123456789123), cos(5.123456789123), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(0.00000004564897), cos(0.00000004564897),
                           1e-15);
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 17) {
      ck_assert_double_eq_tol(cos(k + R * S21_PI), s21_cos(k + R * S21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(exp_test_1) {
  for (double k = -21; k < 21; k += 1) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_2) {
  for (double k = -15; k < 15; k += 0.123) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_3) {
  for (double k = -5; k < 5; k += 0.00573) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_4) {
  ck_assert_double_nan(s21_exp(S21_NAN));
  ck_assert_double_eq(exp(INFINITY), s21_exp(S21_INF_POS));
  ck_assert_double_eq(exp(-INFINITY), s21_exp(S21_INF_NEG));
  ck_assert_double_eq(exp(0), s21_exp(0));
  ck_assert_double_eq(exp(1), s21_exp(1));
}
END_TEST

START_TEST(asin_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = s21_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-7);
}
END_TEST

START_TEST(asin_test_2) {
  for (float k = -1; k <= 1; k += 0.0771) {
    double a = s21_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(asin_test) {
  ck_assert_ldouble_nan(s21_asin(S21_INF_NEG));
  ck_assert_ldouble_nan(s21_asin(S21_INF_POS));
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asin(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_asin(-0.5), asin(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-15);
  ck_assert_ldouble_nan(s21_asin(1.1));
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(-0), asin(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_asin(0.00000004564897), asin(0.00000004564897),
                           1e-15);
}
END_TEST

START_TEST(acos_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(acos_test_2) {
  for (float k = -1; k <= 1; k += 0.0305) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(acos_test) {
  ck_assert_ldouble_nan(s21_acos(S21_INF_NEG));
  ck_assert_ldouble_nan(s21_acos(S21_INF_POS));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-15);
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(0.00000004564897), acos(0.00000004564897),
                           1e-15);
}
END_TEST

START_TEST(atan_test_1) {
  for (float k = -10; k <= 10; k += 4) {
    double a = s21_atan(k);
    double b = atan(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(atan_test_2) {
  double a = 12;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 0.4;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = -0.333;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 55;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 13.54;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
}
END_TEST

START_TEST(atan_test) {
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF_NEG), atan(S21_INF_NEG), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF_POS), atan(S21_INF_POS), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atan(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-0.5), atan(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(-2.1), atan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_atan(-0), atan(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_atan(5.123456789123), atan(5.123456789123),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_atan(0.00000004564897), atan(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_atan(170000000000000.1), atan(170000000000000.1),
                           1e-15);
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_double_eq(fabs(INFINITY), s21_fabs(S21_INF_POS));
  ck_assert_double_eq(fabs(-INFINITY), s21_fabs(S21_INF_NEG));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_nan(s21_fabs(S21_NAN));
  ck_assert_double_eq(fabs(-7.0), s21_fabs(-7.0));
  ck_assert_double_eq(fabs(-98.1), s21_fabs(-98.1));
  ck_assert_double_eq(fabs(123.02), s21_fabs(123.02));
  ck_assert_double_eq(fabs(10009.0), s21_fabs(10009.0));
  ck_assert_double_eq(fabs(-10009.555), s21_fabs(-10009.555));
  ck_assert_double_eq(fabs(-0.10009), s21_fabs(-0.10009));
  ck_assert_double_eq(fabs(-1e23), s21_fabs(-1e23));
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_double_eq(ceil(INFINITY), s21_ceil(S21_INF_POS));
  ck_assert_double_eq(ceil(-INFINITY), s21_ceil(S21_INF_NEG));
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(s21_ceil(S21_NAN));
  ck_assert_double_eq(ceil(-7.0), s21_ceil(-7.0));
  ck_assert_double_eq(ceil(-98.1), s21_ceil(-98.1));
  ck_assert_double_eq(ceil(123.02), s21_ceil(123.02));
  ck_assert_double_eq(ceil(10009.00123), s21_ceil(10009.00123));
  ck_assert_double_eq(ceil(-10009.555), s21_ceil(-10009.555));
  ck_assert_double_eq(ceil(-0.10009), s21_ceil(-0.10009));
  ck_assert_double_eq(ceil(-1e-23), s21_ceil(-1e-23));
}
END_TEST

START_TEST(pow_test_1) {
  for (double k = -9; k <= 9; k += 1.7) {
    for (double g = -5; g < 5; g += 1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!S21_IS_NAN(a) && !isnan(b)) &&
          !(a == S21_INF_POS && b == S21_INF_POS) &&
          !(a == S21_INF_NEG && b == S21_INF_NEG)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!S21_IS_NAN(a) && !isnan(b)) &&
          !(a == S21_INF_POS && b == S21_INF_POS) &&
          !(a == S21_INF_NEG && b == S21_INF_NEG)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(pow_test_2) {
  for (double k = -1e-1; k <= 1; k += 1.1e-1) {
    for (double g = -2.55; g < 2; g += 1.1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!S21_IS_NAN(a) && !isnan(b)) &&
          !(a == S21_INF_POS && b == S21_INF_POS) &&
          !(a == S21_INF_NEG && b == S21_INF_NEG)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!S21_IS_NAN(a) && !isnan(b)) &&
          !(a == S21_INF_POS && b == S21_INF_POS) &&
          !(a == S21_INF_NEG && b == S21_INF_NEG)) {
        ck_assert_double_eq_tol(a, b, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(pow_test_3) {
  ck_assert_double_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_double_eq(pow(-1, 3), s21_pow(-1, 3));
  ck_assert_double_eq(pow(-1, 4), s21_pow(-1, 4));
  ck_assert_double_eq(pow(0, 0), s21_pow(0, 0));
  // ck_assert_double_eq(pow(0, -1), s21_pow(0, -1));
  ck_assert_double_eq(pow(0, 1), s21_pow(0, 1));
  ck_assert_double_eq(pow(INFINITY, 0), s21_pow(S21_INF_POS, 0));
  ck_assert_double_eq(pow(INFINITY, -1), s21_pow(S21_INF_POS, -1));
  ck_assert_double_eq(pow(-1, -INFINITY), s21_pow(-1, S21_INF_NEG));
  ck_assert_double_eq(pow(0, INFINITY), s21_pow(0, S21_INF_POS));
  ck_assert_double_nan(s21_pow(0, S21_NAN));
  ck_assert_double_eq(pow(NAN, 0), s21_pow(S21_NAN, 0));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_double_eq(pow(INFINITY, INFINITY),
                      s21_pow(S21_INF_POS, S21_INF_POS));
  ck_assert_double_eq(pow(INFINITY, -INFINITY),
                      s21_pow(S21_INF_POS, S21_INF_NEG));
  ck_assert_double_eq(pow(-INFINITY, INFINITY),
                      s21_pow(S21_INF_NEG, S21_INF_POS));
  ck_assert_double_eq(pow(-INFINITY, -INFINITY),
                      s21_pow(S21_INF_NEG, S21_INF_NEG));
  ck_assert_double_eq(pow(1, -INFINITY), s21_pow(1, S21_INF_NEG));
  ck_assert_double_eq(pow(1, NAN), s21_pow(1, S21_NAN));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_INF_POS));
  ck_assert_double_nan(s21_pow(S21_INF_POS, S21_NAN));
  ck_assert_double_nan(s21_pow(S21_NAN, S21_INF_NEG));
  ck_assert_double_nan(s21_pow(S21_INF_NEG, S21_NAN));
  ck_assert_double_eq(pow(2, INFINITY), s21_pow(2, S21_INF_POS));
  ck_assert_double_eq(pow(0.5, INFINITY), s21_pow(0.5, S21_INF_POS));
  ck_assert_double_eq(pow(-2, INFINITY), s21_pow(-2, S21_INF_POS));
  ck_assert_double_eq(pow(2, -INFINITY), s21_pow(2, S21_INF_NEG));
  ck_assert_double_eq(pow(0.5, -INFINITY), s21_pow(0.5, S21_INF_NEG));
  ck_assert_double_eq(pow(-2, -INFINITY), s21_pow(-2, S21_INF_NEG));
}
END_TEST

START_TEST(log_test_1) {
  for (double k = 1; k < 100; k += 13.2) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_2) {
  for (double k = 0.1; k < 4; k += 0.24) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_3) {
  for (double k = 0.1; k < 10000; k += 123) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_4) {
  for (double k = 0.000005; k < 1; k *= 5) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_5) {
  ck_assert_double_nan(s21_log(S21_NAN));
  // ck_assert_double_eq(log(0), s21_log(0));
  ck_assert_double_nan(s21_log(-3));
  ck_assert_double_eq(log(INFINITY), s21_log(S21_INF_POS));
  ck_assert_double_nan(s21_log(S21_INF_NEG));
  ck_assert_double_eq(log(1), s21_log(1));
  ck_assert_double_eq(log(S21_E), s21_log(S21_E));
  ck_assert_double_eq_tol(log(2), s21_log(2), 1e-6);
}
END_TEST

START_TEST(sqrt_test_1) {
  for (double k = 0; k < 21; k += 3) {
    double a = s21_sqrt(k);
    double b = sqrt(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(sqrt_test_2) {
  ck_assert_double_nan(s21_sqrt(S21_NAN));
  ck_assert_double_nan(sqrt(NAN));
  ck_assert_double_eq(s21_sqrt(S21_INF_POS), sqrt(INFINITY));
  ck_assert_double_nan(s21_sqrt(S21_INF_NEG));
  ck_assert_double_nan(sqrt(-INFINITY));
  ck_assert_double_nan(s21_sqrt(-5));
  // ck_assert_double_nan(sqrt(-5));
  ck_assert_double_eq_tol(s21_sqrt(1000), sqrt(1000), 1e-7);
}
END_TEST

START_TEST(floor_test) {
  ck_assert_double_eq(floor(INFINITY), s21_floor(S21_INF_POS));
  ck_assert_double_eq(floor(-INFINITY), s21_floor(S21_INF_NEG));
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_nan(s21_floor(S21_NAN));
  ck_assert_double_eq(floor(-7.0), s21_floor(-7.0));
  ck_assert_double_eq(floor(-98.1), s21_floor(-98.1));
  ck_assert_double_eq(floor(123.02), s21_floor(123.02));
  ck_assert_double_eq(floor(10009.00123), s21_floor(10009.00123));
  ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
  ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
  ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23));
  ck_assert_double_eq(floor(100091234.5), s21_floor(100091234.5));
}
END_TEST

START_TEST(fmod_test_1) {
  // ck_assert_double_nan(fmod(1, 0));
  ck_assert_double_nan(s21_fmod(1, 0));
  ck_assert_double_eq(fmod(0, -1), s21_fmod(0, -1));
  ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
  ck_assert_double_nan(fmod(INFINITY, -1));
  ck_assert_double_nan(s21_fmod(INFINITY, -1));
  ck_assert_double_eq(fmod(-1, -INFINITY), s21_fmod(-1, S21_INF_NEG));
  ck_assert_double_eq(fmod(0, INFINITY), s21_fmod(0, S21_INF_POS));
  ck_assert_double_nan(s21_fmod(0, S21_NAN));
  ck_assert_double_nan(fmod(0, NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_INF_POS));
  ck_assert_double_nan(s21_fmod(S21_INF_POS, S21_NAN));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_INF_NEG));
  ck_assert_double_nan(s21_fmod(S21_INF_NEG, S21_NAN));
  ck_assert_double_nan(fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, NAN));
  ck_assert_double_nan(fmod(NAN, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(fmod_test_2) {
  for (double a = -1500; a < 1500; a += 123) {
    for (double b = -12; b < 12; b += 1.25) {
      ck_assert_double_eq(fmod(a, b), s21_fmod(a, b));
      ck_assert_double_eq(fmod(b, a), s21_fmod(b, a));
    }
  }
}
END_TEST

START_TEST(tan_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 9) {
      ck_assert_double_eq_tol(tan(k + R * S21_PI), s21_tan(k + R * S21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(tan_test) {
  ck_assert_double_nan(s21_tan(S21_NAN));
  ck_assert_double_nan(s21_tan(S21_INF_POS));
  ck_assert_double_nan(s21_tan(S21_INF_NEG));
  ck_assert_double_eq_tol(tan(S21_PI / 2), s21_tan(S21_PI / 2), 1e-7);
  ck_assert_double_eq_tol(tan(S21_PI / 2), s21_tan(S21_PI / 2), 1e-7);
}
END_TEST

START_TEST(pow_test) {
  ck_assert_ldouble_eq(s21_pow(S21_INF_POS, S21_INF_POS),
                       pow(S21_INF_POS, S21_INF_POS));
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_NEG, S21_INF_NEG),
                           pow(S21_INF_POS, S21_INF_NEG), 1e-8);
  ck_assert_ldouble_nan(s21_pow(S21_INF_POS, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_INF_POS, S21_NAN));

  ck_assert_ldouble_eq_tol(s21_pow(0, 2.4), pow(0, 2.4), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-0, 2.4), pow(-0, 2.4), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 0), pow(2.4, 0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -0), pow(2.4, -0), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 0.5), pow(2.4, 0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -0.5), pow(2.4, -0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-2.4, 2), pow(-2.4, 2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 2), pow(2.4, 2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(-2.4, -1), pow(-2.4, -1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 1), pow(2.4, 1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, 3), pow(2.4, 3), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(2.4, -3), pow(2.4, -3), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(666666.4, 1.5), pow(666666.4, 1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(666666.4, -1.5), pow(666666.4, -1.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, 13.2), pow(3.3, 13.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(3.3, -24.2), pow(3.3, -24.2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(0.0000000005543, 24.2),
                           pow(0.0000000005543, 24.2), 1e-8);
  ck_assert_ldouble_eq_tol(s21_pow(0.0000000005543, 0.00000003),
                           pow(0.0000000005543, 0.00000003), 1e-8);
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite;

  suite = suite_create("s21_math");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, exp_test_1);
  tcase_add_test(tcase_core, exp_test_2);
  tcase_add_test(tcase_core, exp_test_3);
  tcase_add_test(tcase_core, exp_test_4);
  tcase_add_test(tcase_core, asin_test_1);
  tcase_add_test(tcase_core, asin_test_2);
  tcase_add_test(tcase_core, acos_test_1);
  tcase_add_test(tcase_core, acos_test_2);
  tcase_add_test(tcase_core, atan_test_1);
  tcase_add_test(tcase_core, atan_test_2);
  tcase_add_test(tcase_core, ceil_test);
  tcase_add_test(tcase_core, fabs_test);
  tcase_add_test(tcase_core, cos_test);
  tcase_add_test(tcase_core, abs_test);
  tcase_add_test(tcase_core, asin_test);
  tcase_add_test(tcase_core, acos_test);
  tcase_add_test(tcase_core, atan_test);
  tcase_add_test(tcase_core, pow_test_1);
  tcase_add_test(tcase_core, pow_test_2);
  tcase_add_test(tcase_core, pow_test_3);
  tcase_add_test(tcase_core, log_test_1);
  tcase_add_test(tcase_core, log_test_2);
  tcase_add_test(tcase_core, log_test_3);
  tcase_add_test(tcase_core, log_test_4);
  tcase_add_test(tcase_core, log_test_5);
  tcase_add_test(tcase_core, sqrt_test_1);
  tcase_add_test(tcase_core, sqrt_test_2);
  tcase_add_test(tcase_core, floor_test);
  tcase_add_test(tcase_core, fmod_test_1);
  tcase_add_test(tcase_core, fmod_test_2);
  tcase_add_test(tcase_core, tan_test);
  tcase_add_test(tcase_core, tan_test_1);
  tcase_add_test(tcase_core, pow_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
