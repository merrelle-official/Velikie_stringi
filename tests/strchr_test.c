#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_strchr(dst, 'e'), strchr(dst, 'e'));
}
END_TEST

START_TEST(no_char) {
  char dst[5] = "test";
  ck_assert_ptr_eq(s21_strchr(dst, 'd'), strchr(dst, 'd'));
}
END_TEST

START_TEST(several_chars) {
  char dst[5] = "test";
  ck_assert_ptr_eq(s21_strchr(dst, 't'), strchr(dst, 't'));
}
END_TEST

START_TEST(num) {
  char dst[5] = "1234";
  ck_assert_ptr_eq(s21_strchr(dst, '2'), strchr(dst, '2'));
}
END_TEST

START_TEST(no_num) {
  char dst[5] = "1234";
  ck_assert_ptr_eq(s21_strchr(dst, '6'), strchr(dst, '6'));
}
END_TEST

START_TEST(several_num) {
  char dst[5] = "1224";
  ck_assert_ptr_eq(s21_strchr(dst, '2'), strchr(dst, '2'));
}
END_TEST

START_TEST(base_register) {
  char dst[5] = "tEst";
  ck_assert_ptr_eq(s21_strchr(dst, 'E'), strchr(dst, 'E'));
}
END_TEST

START_TEST(no_base_register) {
  char dst[5] = "tEst";
  ck_assert_ptr_eq(s21_strchr(dst, 'L'), strchr(dst, 'L'));
}
END_TEST

START_TEST(several_register) {
  char dst[5] = "TEsT";
  ck_assert_ptr_eq(s21_strchr(dst, 'T'), strchr(dst, 'T'));
}
END_TEST

START_TEST(symb) {
  char dst[6] = "te!st";
  ck_assert_ptr_eq(s21_strchr(dst, '!'), strchr(dst, '!'));
}
END_TEST

START_TEST(no_symb) {
  char dst[6] = "te!st";
  ck_assert_ptr_eq(s21_strchr(dst, '-'), strchr(dst, '-'));
}
END_TEST

START_TEST(several_symb) {
  char dst[7] = "t!e!st";
  ck_assert_ptr_eq(s21_strchr(dst, '!'), strchr(dst, '!'));
}
END_TEST

START_TEST(all_at_once) {
  char dst[33] = "1234567890-=!@#$%^&*()_+abcdABCD";
  ck_assert_ptr_eq(s21_strchr(dst, '-'), strchr(dst, '-'));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s = suite_create("Checking strchr...");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, no_char);
  tcase_add_test(tc, several_chars);
  tcase_add_test(tc, num);
  tcase_add_test(tc, no_num);
  tcase_add_test(tc, several_num);
  tcase_add_test(tc, base_register);
  tcase_add_test(tc, no_base_register);
  tcase_add_test(tc, several_register);
  tcase_add_test(tc, symb);
  tcase_add_test(tc, no_symb);
  tcase_add_test(tc, several_symb);
  tcase_add_test(tc, all_at_once);

  suite_add_tcase(s, tc);
  return s;
}
