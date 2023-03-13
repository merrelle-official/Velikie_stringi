#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  char dst1[1024] = "test";
  ck_assert_str_eq(s21_strcat(dst, " test"), strcat(dst1, " test"));
}
END_TEST

START_TEST(base_empty) {
  char dst1[6] = "";
  char dst2[6] = "";
  s21_strcat(dst1, " test");
  strcat(dst2, " test");

  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(base_empty_num) {
  char dst1[6] = "";
  char dst2[6] = "";
  s21_strcat(dst1, " 123");
  strcat(dst2, " 123");
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(base_num) {
  char dst1[9] = "test";
  char dst2[9] = "test";
  s21_strcat(dst1, " 123");
  strcat(dst2, " 123");
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(separated) {
  char dst1[10] = {'t', 'e', 's', 't'};
  char dst2[10] = {'t', 'e', 's', 't'};
  s21_strcat(dst1, " test");
  strcat(dst2, " test");

  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(base_register) {
  char dst1[11] = "test";
  char dst2[11] = "test";
  s21_strcat(dst1, " ABCDF");
  strcat(dst2, " ABCDF");
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(base_symb) {
  char dst1[16] = "test";
  char dst2[16] = "test";
  s21_strcat(dst1, " ()#$%#^@");
  strcat(dst2, " ()#$%#^@");
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(all_at_once) {
  char dst1[39] = "test";
  char dst2[39] = "test";
  s21_strcat(dst1, " 1234567890-=!@#$%^&*()_+ABCDabcf");
  strcat(dst2, " 1234567890-=!@#$%^&*()_+ABCDabcf");
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

Suite *suite_strcat(void) {
  Suite *s = suite_create("Checking strcat...");
  TCase *tc = tcase_create("strcat_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, base_empty);
  tcase_add_test(tc, base_symb);
  tcase_add_test(tc, base_num);
  tcase_add_test(tc, base_empty_num);
  tcase_add_test(tc, base_register);
  tcase_add_test(tc, all_at_once);
  tcase_add_test(tc, separated);
  suite_add_tcase(s, tc);
  return s;
}
