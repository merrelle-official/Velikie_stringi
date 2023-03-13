#include <check.h>

#include "tests.h"

START_TEST(float_0) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%f";
  double a = 45;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_1) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%f";
  double a = 45.543;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_2) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%f %f %f";
  double a = 45, b = 32.865, c = 11.204532;
  ck_assert_int_eq(s21_sprintf(test1, input, a, b, c),
                   sprintf(test2, input, a, b, c));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_3) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%2.3f %f %.3f";
  double a = 45, b = 32.865, c = 11.204532;
  ck_assert_int_eq(s21_sprintf(test1, input, a, b, c),
                   sprintf(test2, input, a, b, c));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_4) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%lf";
  double a = 34.532563422356;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_5) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "% 5.6lf";
  double a = 34.532356;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_6) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%2.5f";
  double a = 34.532;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_7) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%+6.1f";
  double a = 534.2;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_8) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%+6.5f";
  double a = -534.2;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
  // free(input);
}
END_TEST

START_TEST(float_9) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "% 6.5f";
  double a = -534.2049;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_10) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%3.4f % 6.2f %+2.1f";
  double a = -534.4445;
  double b = -4.444;
  double c = 3.1;

  ck_assert_int_eq(s21_sprintf(test1, input, a, b, c),
                   sprintf(test2, input, a, b, c));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_11) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%.4f";
  double a = 0.00007;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(float_12) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%-10f";
  double a = 3.1428;
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

Suite *suite_sprintf_f(void) {
  Suite *s = suite_create("Checking sprintf...");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, float_0);
  tcase_add_test(tc, float_1);
  tcase_add_test(tc, float_2);
  tcase_add_test(tc, float_3);
  tcase_add_test(tc, float_4);
  tcase_add_test(tc, float_5);
  tcase_add_test(tc, float_6);
  tcase_add_test(tc, float_7);
  tcase_add_test(tc, float_8);
  tcase_add_test(tc, float_9);
  tcase_add_test(tc, float_10);
  tcase_add_test(tc, float_11);
  tcase_add_test(tc, float_12);

  suite_add_tcase(s, tc);
  return s;
}
