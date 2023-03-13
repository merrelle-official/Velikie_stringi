#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  char dst2[1024] = "test";
  ck_assert_str_eq(s21_strncpy(dst, "ratatatata", 2),
                   strncpy(dst2, "ratatatata", 2));
}
END_TEST

START_TEST(base_full) {
  char dst[1024] = "test";
  char dst2[1024] = "test";
  ck_assert_str_eq(s21_strncpy(dst, "ratatatata", 11),
                   strncpy(dst2, "ratatatata", 11));
}
END_TEST

START_TEST(empty1) {
  char dst[1024] = "";
  char dst2[1024] = "";
  ck_assert_str_eq(s21_strncpy(dst, "", 2), strncpy(dst2, "", 2));
}
END_TEST

START_TEST(empty2) {
  char dst[1024] = "test";
  char dst2[1024] = "test";
  ck_assert_str_eq(s21_strncpy(dst, "test", 0), strncpy(dst2, "test", 0));
}
END_TEST

START_TEST(base_1_byte) {
  char dst[10] = "test";
  char dst2[10] = "test";
  ck_assert_str_eq(s21_strncpy(dst, "ratatatata", 1),
                   strncpy(dst2, "ratatatata", 1));
}
END_TEST

START_TEST(base_num) {
  char dst[20] = "1234";
  char dst2[20] = "1234";
  ck_assert_str_eq(s21_strncpy(dst, "123456", 3), strncpy(dst2, "123456", 3));
}
END_TEST

START_TEST(base_num_full) {
  char dst[20] = "1234";
  char dst2[20] = "1234";
  ck_assert_str_eq(s21_strncpy(dst, "123456", 7), strncpy(dst2, "123456", 7));
}
END_TEST

START_TEST(base_num_1_byte) {
  char dst[10] = "1234";
  char dst2[10] = "1234";
  ck_assert_str_eq(s21_strncpy(dst, "123", 1), strncpy(dst2, "123", 1));
}
END_TEST

START_TEST(base_symb) {
  char dst[20] = "!@#$";
  char dst2[20] = "!@#$";
  ck_assert_str_eq(s21_strncpy(dst, "^^^^^", 3), strncpy(dst2, "^^^^^", 3));
}
END_TEST

START_TEST(base_symb_full) {
  char dst[20] = "!@#$";
  char dst2[20] = "!@#$";
  ck_assert_str_eq(s21_strncpy(dst, "******", 7), strncpy(dst2, "******", 7));
}
END_TEST

START_TEST(base_symb_1_byte) {
  char dst[10] = "!@#$";
  char dst2[10] = "!@#$";
  ck_assert_str_eq(s21_strncpy(dst, "$$$", 1), strncpy(dst2, "$$$", 1));
}
END_TEST

START_TEST(base_register) {
  char dst[20] = "ABCd";
  char dst2[20] = "ABCd";
  ck_assert_str_eq(s21_strncpy(dst, "AAAAA", 3), strncpy(dst2, "AAAAA", 3));
}
END_TEST

START_TEST(base_register_full) {
  char dst[20] = "ABCd";
  char dst2[20] = "ABCd";
  ck_assert_str_eq(s21_strncpy(dst, "AAAAAA", 7), strncpy(dst2, "AAAAAA", 7));
}
END_TEST

START_TEST(base_register_1_byte) {
  char dst[10] = "ABCDe";
  char dst2[10] = "ABCDe";
  ck_assert_str_eq(s21_strncpy(dst, "Fgf", 1), strncpy(dst2, "Fgf", 1));
}
END_TEST

START_TEST(base_all) {
  char dst[20] = "Ab4%";
  char dst2[20] = "Ab4%";
  ck_assert_str_eq(s21_strncpy(dst, "kK8^", 3), strncpy(dst2, "kK8^", 3));
}
END_TEST

START_TEST(base_all_full) {
  char dst[20] = "Ad*&&5";
  char dst2[20] = "Ad*&&5";
  ck_assert_str_eq(s21_strncpy(dst, "AAAAAA", 7), strncpy(dst2, "AAAAAA", 7));
}
END_TEST

START_TEST(base_all_1_byte) {
  char dst[10] = "Ad*&&5";
  char dst2[10] = "Ad*&&5";
  ck_assert_str_eq(s21_strncpy(dst, "Hk5%", 1), strncpy(dst2, "Hk5%", 1));
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s = suite_create("Checking strncpy...");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, base_full);
  tcase_add_test(tc, empty1);
  tcase_add_test(tc, empty2);
  tcase_add_test(tc, base_1_byte);
  tcase_add_test(tc, base_num);
  tcase_add_test(tc, base_num_full);
  tcase_add_test(tc, base_num_1_byte);
  tcase_add_test(tc, base_symb);
  tcase_add_test(tc, base_symb_full);
  tcase_add_test(tc, base_symb_1_byte);
  tcase_add_test(tc, base_register);
  tcase_add_test(tc, base_register_full);
  tcase_add_test(tc, base_register_1_byte);
  tcase_add_test(tc, base_all);
  tcase_add_test(tc, base_all_full);
  tcase_add_test(tc, base_all_1_byte);
  suite_add_tcase(s, tc);
  return s;
}
