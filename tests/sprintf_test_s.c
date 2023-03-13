#include <check.h>

#include "tests.h"

START_TEST(string_1) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *stroka = "barkbark";
  char *input = "%s";
  ck_assert_int_eq(s21_sprintf(test1, input, stroka),
                   sprintf(test2, input, stroka));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(string_2) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *stroka = "barkbark";
  char *input = "%25.5s";
  ck_assert_int_eq(s21_sprintf(test1, input, stroka),
                   sprintf(test2, input, stroka));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(string_3) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *stroka1 = "barkbark";
  char *stroka2 = "barkbaFSD GA457rk";
  char *stroka3 = "dfga";
  char *input = "%23.5s test %.2s TEST %+1s ";
  ck_assert_int_eq(s21_sprintf(test1, input, stroka1, stroka2, stroka3),
                   sprintf(test2, input, stroka1, stroka2, stroka3));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(string_4) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *stroka = "barkbark";
  char *input = "%-19.5s";
  ck_assert_int_eq(s21_sprintf(test1, input, stroka),
                   sprintf(test2, input, stroka));
  ck_assert_str_eq(test1, test2);
}
END_TEST

START_TEST(string_5) {
  char test1[1000] = {
      0,
  };
  char test2[1000] = {
      0,
  };
  char *stroka1 = "fck";
  char *stroka2 = "aaaaaa";
  char *stroka3 = "loh";
  char *input = "%2.5s %2.2s %1.1s";
  ck_assert_int_eq(s21_sprintf(test1, input, stroka1, stroka2, stroka3),
                   sprintf(test2, input, stroka1, stroka2, stroka3));
  ck_assert_str_eq(test1, test2);
}
END_TEST

Suite *suite_sprintf_s(void) {
  Suite *s = suite_create("Checking sprintf...");
  TCase *tc = tcase_create("sprintf_tc");
  tcase_add_test(tc, string_1);
  tcase_add_test(tc, string_2);
  tcase_add_test(tc, string_3);
  tcase_add_test(tc, string_4);
  tcase_add_test(tc, string_5);

  suite_add_tcase(s, tc);

  return s;
}
