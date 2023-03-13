#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(base_num) {
  char dst[1024] = "12345";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(base_register) {
  char dst[1024] = "TeST";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(base_symb) {
  char dst[1024] = "!!#$^&%$#";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(base_all_at_once) {
  char dst[1024] = "1234ABCabc!#%^#";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(same_size) {
  char dst[5] = "test";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(same_size_num) {
  char dst[5] = "1234";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(same_size_symb) {
  char dst[5] = "!@#$";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(same_size_register) {
  char dst[5] = "TEST";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST
START_TEST(same_size_all_at_once) {
  char dst[15] = "1234%^&*$$ABcg";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(empty) {
  char dst[] = "";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(try1) {
  char dst[] = "\0";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(try2) {
  char dst[10] = "test\0test";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

START_TEST(try3) {
  char dst[10] = "\n";
  ck_assert_int_eq(s21_strlen(dst), strlen(dst));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s = suite_create("Checking strlen...");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, base_num);
  tcase_add_test(tc, base_register);
  tcase_add_test(tc, base_symb);
  tcase_add_test(tc, base_all_at_once);
  tcase_add_test(tc, same_size);
  tcase_add_test(tc, same_size_num);
  tcase_add_test(tc, same_size_symb);
  tcase_add_test(tc, same_size_all_at_once);
  tcase_add_test(tc, same_size_register);
  tcase_add_test(tc, empty);
  tcase_add_test(tc, try1);
  tcase_add_test(tc, try2);
  tcase_add_test(tc, try3);
  suite_add_tcase(s, tc);
  return s;
}
