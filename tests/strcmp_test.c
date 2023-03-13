#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  char src[1024] = "test";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(different) {
  char dst[1024] = "test";
  char src[1024] = "loh";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(base_diff_1_char) {
  char dst[5] = "test";
  char src[5] = "teet";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(nums_same) {
  char dst[5] = "1234";
  char src[5] = "1234";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(nums_diff) {
  char dst[5] = "1234";
  char src[5] = "1221";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(nums_diff_1_char) {
  char dst[5] = "1234";
  char src[5] = "1233";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(register_same) {
  char dst[5] = "TEst";
  char src[5] = "TEst";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(register_diff) {
  char dst[5] = "TEST";
  char src[5] = "LOHH";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(register_diff_1_char) {
  char dst[5] = "TeST";
  char src[5] = "DeST";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(register_diff_2) {
  char dst[5] = "TEST";
  char src[5] = "test";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(symb_same) {
  char dst[5] = "!!!!";
  char src[5] = "!!!!";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(symb_diff) {
  char dst[5] = "!!!!";
  char src[5] = "@@@@";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(symb_diff_1_char) {
  char dst[5] = "!!!#";
  char src[5] = "!!!&";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(all_at_once_same) {
  char dst[33] = "1234567890-=!@#$%^&*()_+abcdABCD";
  char src[33] = "1234567890-=!@#$%^&*()_+abcdABCD";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(all_at_once_diff) {
  char dst[33] = "1234567890-=!@#$%^&*()_+abcdABCD";
  char src[15] = "1234%^&*$$ABcg";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(all_at_once_diff_2) {
  char dst[15] = "1234%^&*$$ABcg";
  char src[33] = "1234567890-=!@#$%^&*()_+abcdABCD";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(all_at_once_diff_1_char) {
  char dst[15] = "1234%^&*$$ABcg";
  char src[15] = "1234%^&*$$ABch";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

START_TEST(same_but_size) {
  char dst[15] = "1234%^&*$$ABcg";
  char src[18] = "1234%^&*$$ABcg";
  ck_assert_int_eq(s21_strcmp(dst, src), strcmp(dst, src));
}
END_TEST

Suite *suite_strcmp(void) {
  Suite *s = suite_create("Checking strcmp...");
  TCase *tc = tcase_create("strcmp_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, different);
  tcase_add_test(tc, base_diff_1_char);
  tcase_add_test(tc, nums_same);
  tcase_add_test(tc, nums_diff);
  tcase_add_test(tc, nums_diff_1_char);
  tcase_add_test(tc, register_same);
  tcase_add_test(tc, register_diff);
  tcase_add_test(tc, register_diff_1_char);
  tcase_add_test(tc, register_diff_2);
  tcase_add_test(tc, symb_same);
  tcase_add_test(tc, symb_diff);
  tcase_add_test(tc, symb_diff_1_char);
  tcase_add_test(tc, all_at_once_same);
  tcase_add_test(tc, all_at_once_diff);
  tcase_add_test(tc, all_at_once_diff_2);
  tcase_add_test(tc, all_at_once_diff_1_char);
  tcase_add_test(tc, same_but_size);

  suite_add_tcase(s, tc);
  return s;
}
