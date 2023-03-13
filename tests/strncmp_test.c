#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  ck_assert_int_eq(s21_strncmp(dst, "testststs", 2),
                   strncmp(dst, "testststs", 2));
}
END_TEST

START_TEST(diff) {
  char dst[1024] = "test";
  ck_assert_int_eq(s21_strncmp(dst, "a", 2), strncmp(dst, "a", 2));
}
END_TEST

START_TEST(same) {
  char dst[1024] = "test";
  ck_assert_int_eq(s21_strncmp(dst, "test", 2), strncmp(dst, "test", 2));
}
END_TEST

START_TEST(smaller_char) {
  char dst[5] = "test";
  ck_assert_int_eq(s21_strncmp(dst, "trt", 5), strncmp(dst, "trt", 5));
}
END_TEST

START_TEST(same_char) {
  char dst[5] = "test";
  ck_assert_int_eq(s21_strncmp(dst, "test", 5), strncmp(dst, "test", 5));
}
END_TEST

START_TEST(bigger_char) {
  char dst[1024] = "test";
  ck_assert_int_eq(s21_strncmp(dst, "trttt", 6), strncmp(dst, "trttt", 6));
}
END_TEST

START_TEST(smaller_num) {
  char dst[5] = "1234";
  ck_assert_int_eq(s21_strncmp(dst, "455", 5), strncmp(dst, "455", 5));
}
END_TEST

START_TEST(same_num) {
  char dst[5] = "1234";
  ck_assert_int_eq(s21_strncmp(dst, "1234", 5), strncmp(dst, "1234", 5));
}
END_TEST

START_TEST(bigger_num) {
  char dst[1024] = "1234";
  ck_assert_int_eq(s21_strncmp(dst, "55555", 6), strncmp(dst, "55555", 6));
}
END_TEST

START_TEST(smaller_symb) {
  char dst[5] = "!@#$";
  ck_assert_int_eq(s21_strncmp(dst, "##", 5), strncmp(dst, "##", 5));
}
END_TEST

START_TEST(same_symb) {
  char dst[5] = "!@#$";
  ck_assert_int_eq(s21_strncmp(dst, "!@#$", 5), strncmp(dst, "!@#$", 5));
}
END_TEST

START_TEST(bigger_symb) {
  char dst[1024] = "!@#$";
  ck_assert_int_eq(s21_strncmp(dst, "%$#@!", 6), strncmp(dst, "%$#@!", 6));
}
END_TEST

START_TEST(smaller_all) {
  char dst[10] = "Ab2$F$%9v";
  ck_assert_int_eq(s21_strncmp(dst, "aB1!", 10), strncmp(dst, "aB1!", 10));
}
END_TEST

START_TEST(same_all) {
  char dst[10] = "Ab2$F$%9v";
  ck_assert_int_eq(s21_strncmp(dst, "Ab2$F$%9v", 10),
                   strncmp(dst, "Ab2$F$%9v", 10));
}
END_TEST

START_TEST(bigger_all) {
  char dst[1024] = "!@#$";
  ck_assert_int_eq(s21_strncmp(dst, "%$#@!", 6), strncmp(dst, "%$#@!", 6));
}
END_TEST

START_TEST(empty) {
  char dst[1024] = "!@#$";
  ck_assert_int_eq(s21_strncmp(dst, "%$#@!", 0), strncmp(dst, "%$#@!", 0));
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s = suite_create("Checking strncmp...");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, diff);
  tcase_add_test(tc, same);
  tcase_add_test(tc, smaller_char);
  tcase_add_test(tc, same_char);
  tcase_add_test(tc, bigger_char);
  tcase_add_test(tc, smaller_num);
  tcase_add_test(tc, same_num);
  tcase_add_test(tc, bigger_num);
  tcase_add_test(tc, smaller_symb);
  tcase_add_test(tc, same_symb);
  tcase_add_test(tc, bigger_symb);
  tcase_add_test(tc, smaller_all);
  tcase_add_test(tc, same_all);
  tcase_add_test(tc, bigger_all);
  tcase_add_test(tc, empty);

  suite_add_tcase(s, tc);
  return s;
}
