#include <check.h>

#include "tests.h"

START_TEST(base_1) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_strrchr(dst, 'e'), strrchr(dst, 'e'));
}
END_TEST

START_TEST(base_2) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_strrchr(dst, 't'), strrchr(dst, 't'));
}
END_TEST

START_TEST(base_no) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_strrchr(dst, 'k'), strrchr(dst, 'k'));
}
END_TEST

START_TEST(base_1_num) {
  char dst[1024] = "12345";
  ck_assert_ptr_eq(s21_strrchr(dst, '2'), strrchr(dst, '2'));
}
END_TEST

START_TEST(base_2_num) {
  char dst[1024] = "12336432";
  ck_assert_ptr_eq(s21_strrchr(dst, '3'), strrchr(dst, '3'));
}
END_TEST

START_TEST(base_no_num) {
  char dst[1024] = "14567";
  ck_assert_ptr_eq(s21_strrchr(dst, '0'), strrchr(dst, '0'));
}
END_TEST

START_TEST(base_1_symb) {
  char dst[1024] = "!@#$%";
  ck_assert_ptr_eq(s21_strrchr(dst, '@'), strrchr(dst, '@'));
}
END_TEST

START_TEST(base_2_symb) {
  char dst[1024] = "!@#$%%#@!&%@";
  ck_assert_ptr_eq(s21_strrchr(dst, '%'), strrchr(dst, '%'));
}
END_TEST

START_TEST(base_no_symb) {
  char dst[1024] = "!%$#@%$!";
  ck_assert_ptr_eq(s21_strrchr(dst, '&'), strrchr(dst, '&'));
}
END_TEST

START_TEST(base_1_register) {
  char dst[1024] = "abcfAg";
  ck_assert_ptr_eq(s21_strrchr(dst, 'A'), strrchr(dst, 'A'));
}
END_TEST

START_TEST(base_2_register) {
  char dst[1024] = "ABcaaAaJGA";
  ck_assert_ptr_eq(s21_strrchr(dst, 'A'), strrchr(dst, 'A'));
}
END_TEST

START_TEST(base_no_register) {
  char dst[1024] = "ABCdg";
  ck_assert_ptr_eq(s21_strrchr(dst, 'G'), strrchr(dst, 'G'));
}
END_TEST

START_TEST(base_1_all) {
  char dst[1024] = "!A674kds";
  ck_assert_ptr_eq(s21_strrchr(dst, '7'), strrchr(dst, '7'));
}
END_TEST

START_TEST(base_2_all) {
  char dst[1024] = "Fv^%#134fFd";
  ck_assert_ptr_eq(s21_strrchr(dst, 'F'), strrchr(dst, 'F'));
}
END_TEST

START_TEST(base_no_all) {
  char dst[1024] = "Ac1@#";
  ck_assert_ptr_eq(s21_strrchr(dst, '&'), strrchr(dst, '&'));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s = suite_create("Checking strrchr...");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, base_1);
  tcase_add_test(tc, base_2);
  tcase_add_test(tc, base_no);
  tcase_add_test(tc, base_1_num);
  tcase_add_test(tc, base_2_num);
  tcase_add_test(tc, base_no_num);
  tcase_add_test(tc, base_1_symb);
  tcase_add_test(tc, base_2_symb);
  tcase_add_test(tc, base_no_symb);
  tcase_add_test(tc, base_1_register);
  tcase_add_test(tc, base_2_register);
  tcase_add_test(tc, base_no_register);
  tcase_add_test(tc, base_1_all);
  tcase_add_test(tc, base_2_all);
  tcase_add_test(tc, base_no_all);
  suite_add_tcase(s, tc);
  return s;
}
