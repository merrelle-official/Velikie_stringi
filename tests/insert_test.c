#include <check.h>

#include "tests.h"

START_TEST(base) {
  char str[] = "aaaaa";
  char src[] = "bbbbb";
  s21_size_t num = 0;
  char result[] = "aaaaabbbbb";
  char *our = s21_insert(src, str, num);
  ck_assert_str_eq(result, our);
  free(our);
}
END_TEST

START_TEST(base2) {
  char str[] = "aaaaa";
  char src[] = "bbbbb";
  s21_size_t num = 3;
  char result[] = "bbbaaaaabb";
  char *our = s21_insert(src, str, num);
  ck_assert_str_eq(result, our);
  free(our);
}
END_TEST

START_TEST(base3) {
  char str[] = "aaaaa";
  char src[] = "bbbbb";
  s21_size_t num = 5;
  char result[] = "bbbbbaaaaa";
  char *our = s21_insert(src, str, num);
  ck_assert_str_eq(result, our);
  free(our);
}
END_TEST

START_TEST(base4) {
  char str[] = "aaaaa";
  char src[] = "bbbbb";
  s21_size_t num = 9;
  char result[] = "bbbbb";
  char *our = s21_insert(src, str, num);
  ck_assert_str_eq(result, our);
  free(our);
}
END_TEST

START_TEST(nulls) {
  char src[] = "bbbbb";
  s21_size_t num = 4;
  ck_assert_ptr_eq(s21_NULL, s21_insert(src, s21_NULL, num));
}
END_TEST

START_TEST(nulls2) {
  char str[] = "aaaaa";
  s21_size_t num = 4;
  ck_assert_ptr_eq(s21_NULL, s21_insert(s21_NULL, str, num));
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("Checking insert...");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, base2);
  tcase_add_test(tc, base3);
  tcase_add_test(tc, base4);
  tcase_add_test(tc, nulls);
  tcase_add_test(tc, nulls2);

  suite_add_tcase(s, tc);
  return s;
}
