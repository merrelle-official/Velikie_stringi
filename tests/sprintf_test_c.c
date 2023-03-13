#include <check.h>

#include "tests.h"

START_TEST(char_1) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%c";
  ck_assert_int_eq(s21_sprintf(test1, input, 'a'), sprintf(test2, input, 'a'));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_2) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%c %c %c";
  ck_assert_int_eq(s21_sprintf(test1, input, 'a', 'b', 'c'),
                   sprintf(test2, input, 'a', 'b', 'c'));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_3) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a[200] = "privet katyusha";
  char *input = "%lc";
  ck_assert_int_eq(s21_sprintf(test1, input, a[5]),
                   sprintf(test2, input, a[5]));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_4) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 's';
  char *input = "%hc";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_5) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 's';
  char *input = "%5.4c";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_6) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 's';
  char *input = "% 5.4c";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_7) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 'e';
  char *input = "%+5.4c";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_8) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 's';
  char *input = "%-5.2c";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_9) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 's';
  char *input = "% 9.1c";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_10) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 's';
  char *input = "%10c";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_11) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 's';
  char *input = "%10lc";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_12) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char a = 's';
  char *input = "%1.3hc";
  ck_assert_int_eq(s21_sprintf(test1, input, a), sprintf(test2, input, a));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(char_13) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *input = "%%";
  ck_assert_int_eq(s21_sprintf(test1, input), sprintf(test2, input));
  ck_assert_str_eq(test1, test2);
}
END_TEST

Suite *suite_sprintf_c(void) {
  Suite *s = suite_create("Checking sprintf...");
  TCase *tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, char_1);
  tcase_add_test(tc, char_2);
  tcase_add_test(tc, char_3);
  tcase_add_test(tc, char_4);
  tcase_add_test(tc, char_5);
  tcase_add_test(tc, char_6);
  tcase_add_test(tc, char_7);
  tcase_add_test(tc, char_8);
  tcase_add_test(tc, char_9);
  tcase_add_test(tc, char_10);
  tcase_add_test(tc, char_11);
  tcase_add_test(tc, char_12);
  tcase_add_test(tc, char_13);
  suite_add_tcase(s, tc);
  return s;
}
