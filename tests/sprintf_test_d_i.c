#include <check.h>

#include "tests.h"

START_TEST(int_1) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 55;
  char *input = "%d";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_2) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 55;
  char *input = "% 6.8d";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_3) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 55;
  char *input = "%-6.3d";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}

END_TEST

START_TEST(int_4) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 55;
  char *input = "%-.5d";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_5) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = -45;
  char *input = "%.0d";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_6) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 45;
  char *input = "% 7.2d";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_7) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 45;
  char *input = "%+1.5d";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_8) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 45, b = 43, c = -76;
  char *input = "%+1.5d %+d %d";
  ck_assert_int_eq(s21_sprintf(test1, input, a, b, c),
                   sprintf(test2, input, a, b, c));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_9) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 45;
  char *input = "%1.5hd";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_10) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  long int a = 235235364;
  char *input = "%4.5ld";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_11) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  int a = 45, b = 43, c = -76;
  char *input = "%d %i %i";
  ck_assert_int_eq(s21_sprintf(test1, input, a, b, c),
                   sprintf(test2, input, a, b, c));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(int_12) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  short int a = 2;
  char *input = "%hd";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

Suite *suite_sprintf_d_i(void) {
  Suite *s = suite_create("Checking sprintf...");
  TCase *tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, int_1);
  tcase_add_test(tc, int_2);
  tcase_add_test(tc, int_3);
  tcase_add_test(tc, int_4);
  tcase_add_test(tc, int_5);
  tcase_add_test(tc, int_6);
  tcase_add_test(tc, int_7);
  tcase_add_test(tc, int_8);
  tcase_add_test(tc, int_9);
  tcase_add_test(tc, int_10);
  tcase_add_test(tc, int_11);
  tcase_add_test(tc, int_12);

  suite_add_tcase(s, tc);
  return s;
}
