#include <check.h>

#include "tests.h"

START_TEST(base_beginning) {
  char dst[1024] = "testing";
  char target[] = "test";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_1_symb_dif) {
  char dst[1024] = "testing";
  char target[] = "testf";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_no) {
  char dst[1024] = "testing";
  char target[] = "ghg";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_middle) {
  char dst[1024] = "testing";
  char target[] = "est";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_end) {
  char dst[1024] = "testing";
  char target[] = "ing";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_num_beginning) {
  char dst[1024] = "123456";
  char target[] = "123";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_num_1_symb_dif) {
  char dst[1024] = "123456";
  char target[] = "1236";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_num_no) {
  char dst[1024] = "12345";
  char target[] = "678";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_num_middle) {
  char dst[1024] = "12345";
  char target[] = "34";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_num_end) {
  char dst[1024] = "12345";
  char target[] = "45";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_register_beginning) {
  char dst[1024] = "TESTing";
  char target[] = "TEST";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_register_1_symb_dif) {
  char dst[1024] = "TESTing";
  char target[] = "TESt";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_register_no) {
  char dst[1024] = "TESTING";
  char target[] = "test";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_register_middle) {
  char dst[1024] = "teSTing";
  char target[] = "eST";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_register_end) {
  char dst[1024] = "testING";
  char target[] = "ING";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_symb_beginning) {
  char dst[1024] = "!@#$%";
  char target[] = "!@";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_symb_1_symb_dif) {
  char dst[1024] = "!@#$%";
  char target[] = "!@)";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_symb_no) {
  char dst[1024] = "!@#$%";
  char target[] = "*(";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_symb_middle) {
  char dst[1024] = "!@#$%";
  char target[] = "@#";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_symb_end) {
  char dst[1024] = "!$%&*";
  char target[] = "&*";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_all_beginning) {
  char dst[1024] = "TesT1&*";
  char target[] = "Tes";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_all_1_symb_dif) {
  char dst[1024] = "TesT1&*";
  char target[] = "Test";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_all_no) {
  char dst[1024] = "TesT1&*";
  char target[] = "ghg";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_all_middle) {
  char dst[1024] = "TesT1&*";
  char target[] = "sT1";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

START_TEST(base_all_end) {
  char dst[1024] = "TesT1&*";
  char target[] = "1&*";
  ck_assert_int_eq(s21_strspn(dst, target), strspn(dst, target));
}
END_TEST

Suite *suite_strspn(void) {
  Suite *s = suite_create("Checking strspn...");
  TCase *tc = tcase_create("strspn_tc");

  tcase_add_test(tc, base_beginning);
  tcase_add_test(tc, base_1_symb_dif);
  tcase_add_test(tc, base_no);
  tcase_add_test(tc, base_middle);
  tcase_add_test(tc, base_end);
  tcase_add_test(tc, base_num_beginning);
  tcase_add_test(tc, base_num_1_symb_dif);
  tcase_add_test(tc, base_num_no);
  tcase_add_test(tc, base_num_middle);
  tcase_add_test(tc, base_num_end);
  tcase_add_test(tc, base_register_beginning);
  tcase_add_test(tc, base_register_1_symb_dif);
  tcase_add_test(tc, base_register_no);
  tcase_add_test(tc, base_register_middle);
  tcase_add_test(tc, base_register_end);
  tcase_add_test(tc, base_symb_beginning);
  tcase_add_test(tc, base_symb_1_symb_dif);
  tcase_add_test(tc, base_symb_no);
  tcase_add_test(tc, base_symb_middle);
  tcase_add_test(tc, base_symb_end);
  tcase_add_test(tc, base_all_beginning);
  tcase_add_test(tc, base_all_1_symb_dif);
  tcase_add_test(tc, base_all_no);
  tcase_add_test(tc, base_all_middle);
  tcase_add_test(tc, base_all_end);

  suite_add_tcase(s, tc);
  return s;
}
