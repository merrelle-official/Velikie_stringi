#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[] = "test";
  ck_assert_int_eq(s21_strcspn(dst, "e"), strcspn(dst, "e"));
}
END_TEST

START_TEST(base_empty_1) {
  char dst[] = "test";
  ck_assert_int_eq(s21_strcspn(dst, ""), strcspn(dst, ""));
}
END_TEST

START_TEST(base_empty_2) {
  char dst[] = "";
  ck_assert_int_eq(s21_strcspn(dst, "abc"), strcspn(dst, "abc"));
}
END_TEST

START_TEST(long_string) {
  char dst[] = "test";
  ck_assert_int_eq(s21_strcspn(dst, "est"), strcspn(dst, "est"));
}
END_TEST

START_TEST(no_string) {
  char dst[] = "test";
  ck_assert_int_eq(s21_strcspn(dst, "x"), strcspn(dst, "x"));
}
END_TEST

START_TEST(num_base) {
  char dst[] = "12345677";
  ck_assert_int_eq(s21_strcspn(dst, "5"), strcspn(dst, "5"));
}
END_TEST

START_TEST(num_long_string) {
  char dst[] = "12345678";
  ck_assert_int_eq(s21_strcspn(dst, "345"), strcspn(dst, "345"));
}
END_TEST

START_TEST(num_no_string) {
  char dst[] = "156732";
  ck_assert_int_eq(s21_strcspn(dst, "0"), strcspn(dst, "0"));
}
END_TEST

START_TEST(num_several) {
  char dst[] = "15676362";
  ck_assert_int_eq(s21_strcspn(dst, "6"), strcspn(dst, "6"));
}
END_TEST

START_TEST(symb_base) {
  char dst[] = "!@#$%^&";
  ck_assert_int_eq(s21_strcspn(dst, "@"), strcspn(dst, "@"));
}
END_TEST

START_TEST(symb_long_string) {
  char dst[] = "!$%^&*(";
  ck_assert_int_eq(s21_strcspn(dst, "^&"), strcspn(dst, "^&"));
}
END_TEST

START_TEST(symb_no_string) {
  char dst[] = "!@#!#!@#!@#";
  ck_assert_int_eq(s21_strcspn(dst, "^"), strcspn(dst, "^"));
}
END_TEST

START_TEST(symb_several) {
  char dst[] = "!@#!#!@#!@#";
  ck_assert_int_eq(s21_strcspn(dst, "#"), strcspn(dst, "#"));
}
END_TEST

START_TEST(register_base) {
  char dst[] = "ABVCadgjb";
  ck_assert_int_eq(s21_strcspn(dst, "V"), strcspn(dst, "V"));
}
END_TEST

START_TEST(register_long_string) {
  char dst[] = "KffggABVGadgdVCaJRE";
  ck_assert_int_eq(s21_strcspn(dst, "VCa"), strcspn(dst, "VCa"));
}
END_TEST

START_TEST(register_no_string) {
  char dst[] = "ABCC";
  ck_assert_int_eq(s21_strcspn(dst, "F"), strcspn(dst, "F"));
}
END_TEST

START_TEST(register_several) {
  char dst[] = "ABFABFFDDDGRD";
  ck_assert_int_eq(s21_strcspn(dst, "F"), strcspn(dst, "F"));
}
END_TEST

START_TEST(same_letter_dif_reg) {
  char dst[] = "ASDFHHSAA";
  ck_assert_int_eq(s21_strcspn(dst, "a"), strcspn(dst, "a"));
}
END_TEST

START_TEST(all_at_once_base) {
  char dst[] = "ABCdf346$$%";
  ck_assert_int_eq(s21_strcspn(dst, "f"), strcspn(dst, "f"));
}
END_TEST

START_TEST(all_at_once_long_string) {
  char dst[] = "SDFGgg44566@#%%aaa";
  ck_assert_int_eq(s21_strcspn(dst, "Sg5f!*"), strcspn(dst, "Sgf5!*"));
}
END_TEST

START_TEST(all_at_once_no_string) {
  char dst[] = ";sAA!23";
  ck_assert_int_eq(s21_strcspn(dst, "Sgf!1*"), strcspn(dst, "Sgf!1*"));
}
END_TEST

START_TEST(all_at_once_several) {
  char dst[] = "!@#!#!@#!@#";
  ck_assert_int_eq(s21_strcspn(dst, "#"), strcspn(dst, "#"));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s = suite_create("Checking strcspn...");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, long_string);
  tcase_add_test(tc, no_string);
  tcase_add_test(tc, base_empty_1);
  tcase_add_test(tc, base_empty_2);
  tcase_add_test(tc, long_string);
  tcase_add_test(tc, no_string);
  tcase_add_test(tc, symb_base);
  tcase_add_test(tc, symb_long_string);
  tcase_add_test(tc, symb_no_string);
  tcase_add_test(tc, symb_several);
  tcase_add_test(tc, num_base);
  tcase_add_test(tc, num_no_string);
  tcase_add_test(tc, num_long_string);
  tcase_add_test(tc, num_several);
  tcase_add_test(tc, register_base);
  tcase_add_test(tc, register_long_string);
  tcase_add_test(tc, register_no_string);
  tcase_add_test(tc, register_several);
  tcase_add_test(tc, same_letter_dif_reg);
  tcase_add_test(tc, all_at_once_base);
  tcase_add_test(tc, all_at_once_no_string);
  tcase_add_test(tc, all_at_once_long_string);
  tcase_add_test(tc, all_at_once_several);

  suite_add_tcase(s, tc);
  return s;
}
