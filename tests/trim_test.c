#include <check.h>

#include "tests.h"

START_TEST(base0) {
  char str[] = "!!! HELLO WORLD! !!!";
  char trim_chars[] = "!";
  char expected[] = " HELLO WORLD! ";
  char *our = s21_trim(str, trim_chars);
  ck_assert_str_eq(expected, our);
  free(our);
}
END_TEST

START_TEST(base1) {
  char str[] = "!!! HELLO !!! WORLD !!!";
  char trim_chars[] = "! ";
  char expected[] = "HELLO !!! WORLD";
  char *our = s21_trim(str, trim_chars);
  ck_assert_str_eq(expected, our);
  free(our);
}
END_TEST

START_TEST(base2) {
  char str[] = "";
  char trim_chars[] = "";
  char expected[] = "";
  char *our = s21_trim(str, trim_chars);
  ck_assert_str_eq(expected, our);
  free(our);
}
END_TEST

START_TEST(base3) {
  char str[] = "1+& HELLO WORLD 1&";
  char trim_chars[] = "1+&";
  char expected[] = " HELLO WORLD ";
  char *our = s21_trim(str, trim_chars);
  ck_assert_str_eq(expected, our);
  free(our);
}
END_TEST

START_TEST(base4) {
  char str[] = "    f v      ";
  char trim_chars[] = " ";
  char expected[] = "f v";
  char *our = s21_trim(str, trim_chars);
  ck_assert_str_eq(expected, our);
  free(our);
}
END_TEST

START_TEST(base5) {
  char str[] = "HELLO WORLD";
  ck_assert_ptr_eq(s21_NULL, s21_trim(str, s21_NULL));
}
END_TEST

START_TEST(base6) { ck_assert_ptr_eq(s21_NULL, s21_trim(s21_NULL, "!a")); }
END_TEST

START_TEST(base7) {
  char str[] = "HELLO WORLD!!!";
  char trim_chars[] = "56";
  char expected[] = "HELLO WORLD!!!";
  char *our = s21_trim(str, trim_chars);
  ck_assert_str_eq(expected, our);
  free(our);
}
END_TEST

Suite *suite_trim(void) {
  Suite *s = suite_create("Checking trim...");
  TCase *tc = tcase_create("trim_tc");

  tcase_add_test(tc, base0);
  tcase_add_test(tc, base1);
  tcase_add_test(tc, base2);
  tcase_add_test(tc, base3);
  tcase_add_test(tc, base4);
  tcase_add_test(tc, base5);
  tcase_add_test(tc, base6);
  tcase_add_test(tc, base7);

  suite_add_tcase(s, tc);
  return s;
}
