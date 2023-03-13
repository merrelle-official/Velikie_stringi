#include <check.h>

#include "tests.h"

START_TEST(base) {
  char needed[1024] = "tesst";
  char str[1024] = "TeSst";
  char *our = s21_to_lower(str);
  ck_assert_str_eq(needed, our);
  free(our);
}
END_TEST

START_TEST(base2) {
  char needed[1024] = "test";
  char str[1024] = "TEST";
  char *our = s21_to_lower(str);
  ck_assert_str_eq(needed, our);
  free(our);
}
END_TEST

START_TEST(base3) {
  char needed[1024] = "test";
  char str[1024] = "tesT";
  char *our = s21_to_lower(str);
  ck_assert_str_eq(needed, our);
  free(our);
}
END_TEST

START_TEST(base4) {
  char needed[1024] = "te!#1st";
  char str[1024] = "TE!#1st";
  char *our = s21_to_lower(str);
  ck_assert_str_eq(needed, our);
  free(our);
}
END_TEST

START_TEST(base5) {
  char needed[1024] = "test";
  char str[1024] = "test";
  char *our = s21_to_lower(str);
  ck_assert_str_eq(needed, our);
  free(our);
}
END_TEST

START_TEST(base6) {
  char needed[1024] = "testtest";
  char str[1024] = "testTEST";
  char *our = s21_to_lower(str);
  ck_assert_str_eq(needed, our);
  free(our);
}
END_TEST

START_TEST(base7) {
  char needed[1024] = "";
  char str[1024] = "";
  char *our = s21_to_lower(str);
  ck_assert_str_eq(needed, our);
  free(our);
}
END_TEST

START_TEST(base8) { ck_assert_ptr_eq(s21_NULL, s21_to_lower(s21_NULL)); }
END_TEST

Suite *suite_to_lower(void) {
  Suite *s = suite_create("Checking to_lower...");
  TCase *tc = tcase_create("to_lower_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, base2);
  tcase_add_test(tc, base3);
  tcase_add_test(tc, base4);
  tcase_add_test(tc, base5);
  tcase_add_test(tc, base6);
  tcase_add_test(tc, base7);
  tcase_add_test(tc, base8);

  suite_add_tcase(s, tc);
  return s;
}
