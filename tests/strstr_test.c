#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  char source[] = "es";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(longer) {
  char dst[1024] = "test";
  char source[] = "testing";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(no) {
  char dst[1024] = "testing";
  char source[] = "bark";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(num) {
  char dst[1024] = "12345678";
  char source[] = "3456";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(symb) {
  char dst[1024] = "test!ng";
  char source[] = "!ng";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(with_register_1) {
  char dst[1024] = "TESTing";
  char source[] = "test";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(with_register_2) {
  char dst[1024] = "TESTing";
  char source[] = "TEST";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(all) {
  char dst[1024] = "TESTing12389";
  char source[] = "ing";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(beginning) {
  char dst[1024] = "Hello Wold!";
  char source[] = "Hello ";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(middle) {
  char dst[1024] = "Hello Wold!";
  char source[] = "llo W";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

START_TEST(end) {
  char dst[1024] = "Hello Wold!";
  char source[] = "old!";
  ck_assert_ptr_eq(s21_strstr(dst, source), strstr(dst, source));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s = suite_create("Checking strstr...");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, longer);
  tcase_add_test(tc, no);
  tcase_add_test(tc, num);
  tcase_add_test(tc, symb);
  tcase_add_test(tc, with_register_1);
  tcase_add_test(tc, with_register_2);
  tcase_add_test(tc, all);
  tcase_add_test(tc, beginning);
  tcase_add_test(tc, middle);
  tcase_add_test(tc, end);

  suite_add_tcase(s, tc);
  return s;
}
