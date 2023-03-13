#include <check.h>

#include "tests.h"

START_TEST(base_1) {
  char dst[1024] = "test";
  char target[] = "es";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_no) {
  char dst[1024] = "test";
  char target[] = "mm";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_empty) {
  char dst[1024] = "test";
  char target[] = "";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_2) {
  char dst[1024] = "test";
  char target[] = "t";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_3) {
  char dst[1024] = "aatestabctest";
  char target[] = "test";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_1_num) {
  char dst[10] = "12345";
  char target[] = "45";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_2_num) {
  char dst[10] = "12345";
  char target[] = "3";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_3_num) {
  char dst[30] = "17610564710";
  char target[] = "10";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_no_num) {
  char dst[10] = "12345";
  char target[] = "76";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_1_register) {
  char dst[10] = "TEST";
  char target[] = "ES";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_2_register) {
  char dst[10] = "TEST";
  char target[] = "E";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_3_register) {
  char dst[30] = "TSESTTEST";
  char target[] = "ES";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_no_register) {
  char dst[10] = "TEST";
  char target[] = "MeM";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_1_symb) {
  char dst[10] = "!%$^&";
  char target[] = "%$";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_2_symb) {
  char dst[10] = "!@#$%";
  char target[] = "@";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_3_symb) {
  char dst[30] = "$#*&^@#)$#*(";
  char target[] = "$#";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_no_symb) {
  char dst[10] = "!@#$%";
  char target[] = "&(";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_1_all) {
  char dst[10] = "Ad87%$";
  char target[] = "d8";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_2_all) {
  char dst[10] = "Ad87%$";
  char target[] = "7";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_3_all) {
  char dst[30] = "Ad8%$@d8$%AB(";
  char target[] = "d8";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

START_TEST(base_no_all) {
  char dst[10] = "Ad87%$";
  char target[] = "l0l";
  ck_assert_ptr_eq(s21_strpbrk(dst, target), strpbrk(dst, target));
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s = suite_create("Checking strpbrk...");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, base_1);
  tcase_add_test(tc, base_2);
  tcase_add_test(tc, base_3);
  tcase_add_test(tc, base_no);
  tcase_add_test(tc, base_empty);
  tcase_add_test(tc, base_1_num);
  tcase_add_test(tc, base_2_num);
  tcase_add_test(tc, base_3_num);
  tcase_add_test(tc, base_no_num);
  tcase_add_test(tc, base_1_register);
  tcase_add_test(tc, base_2_register);
  tcase_add_test(tc, base_3_register);
  tcase_add_test(tc, base_no_register);
  tcase_add_test(tc, base_1_symb);
  tcase_add_test(tc, base_2_symb);
  tcase_add_test(tc, base_3_symb);
  tcase_add_test(tc, base_no_symb);
  tcase_add_test(tc, base_1_all);
  tcase_add_test(tc, base_2_all);
  tcase_add_test(tc, base_3_all);
  tcase_add_test(tc, base_no_all);

  suite_add_tcase(s, tc);
  return s;
}
