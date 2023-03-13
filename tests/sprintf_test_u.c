#include <check.h>

#include "tests.h"

START_TEST(u_1) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 45;
  char *input = "%u";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_2) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 45;
  char *input = "% 6.8u";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_3) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 697;
  char *input = "%+1.3u";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}

END_TEST

START_TEST(u_4) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 012;
  char *input = "%2.5u";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_5) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 462;
  char *input = "%.0u";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_6) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 45;
  char *input = "% 7.2u";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_7) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 024;
  char *input = "%+1.5u";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_8) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 0245, b = 4123, c = 076;
  char *input = "%+1.5d %+d %4.3d";
  ck_assert_int_eq(s21_sprintf(test1, input, a, b, c),
                   sprintf(test2, input, a, b, c));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_9) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 4;
  char *input = "%1.5hd";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_10) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  long unsigned int a = 0235235364;
  char *input = "%4.5ld";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_11) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  unsigned int a = 45, b = 43, c = 6;
  char *input = "%4u TES T %u %hu";
  ck_assert_int_eq(s21_sprintf(test1, input, a, b, c),
                   sprintf(test2, input, a, b, c));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_12) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  short unsigned int a = 2;
  char *input = "%hu";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(u_13) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  long unsigned int a = 2;
  char *input = "%lu";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

Suite *suite_sprintf_u(void) {
  Suite *s = suite_create("Checking sprintf...");
  TCase *tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, u_1);
  tcase_add_test(tc, u_2);
  tcase_add_test(tc, u_3);
  tcase_add_test(tc, u_4);
  tcase_add_test(tc, u_5);
  tcase_add_test(tc, u_6);
  tcase_add_test(tc, u_7);
  tcase_add_test(tc, u_8);
  tcase_add_test(tc, u_9);
  tcase_add_test(tc, u_10);
  tcase_add_test(tc, u_11);
  tcase_add_test(tc, u_12);
  tcase_add_test(tc, u_13);
  suite_add_tcase(s, tc);
  return s;
}
