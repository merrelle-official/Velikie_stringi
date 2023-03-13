#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst1[1024] = "test";
  char dst2[1024] = "test";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 10), memcmp(dst1, dst2, 10));
}
END_TEST

START_TEST(different) {
  char dst1[1024] = "test";
  char dst2[1024] = "loh";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 10), memcmp(dst1, dst2, 10));
}
END_TEST

START_TEST(size_is_zero) {
  char dst1[1024] = "test";
  char dst2[1024] = "test";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 0), memcmp(dst1, dst2, 0));
}
END_TEST

START_TEST(strings_are_zero) {
  char dst1[10] = "";
  char dst2[10] = "";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 10), memcmp(dst1, dst2, 10));
}
END_TEST

START_TEST(everything_is_zero) {
  char dst1[] = "";
  char dst2[] = "";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 0), memcmp(dst1, dst2, 0));
}
END_TEST

START_TEST(char_and_int) {
  int dst1[1024] = {1, 2, 3};
  char dst2[1024] = "1 2 3";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 30), memcmp(dst1, dst2, 30));
}
END_TEST

START_TEST(int_and_double_same) {
  int dst1[1024] = {1, 2, 3};
  double dst2[1024] = {1, 2, 3};
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 30), memcmp(dst1, dst2, 30));
}
END_TEST

START_TEST(int_and_double) {
  int dst1[1024] = {1, 2};
  double dst2[1024] = {1};
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 10), memcmp(dst1, dst2, 10));
}
END_TEST

START_TEST(register_check) {
  char dst1[1024] = "Hello world!";
  char dst2[1024] = "hello world!";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 20), memcmp(dst1, dst2, 20));
}
END_TEST

START_TEST(long_strings_eq) {
  char dst1[1024] =
      "AAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBABABABABABABABABABABABABB "
      "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL "
      "MMMMEMEMEMEMEMEMEMEMEMEMEMEMEMEMW "
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! LLLLL llllll";
  char dst2[1024] =
      "AAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBABABABABABABABABABABABABB "
      "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL "
      "MMMMEMEMEMEMEMEMEMEMEMEMEMEMEMEMW "
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! LLLLL llllll";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 250), memcmp(dst1, dst2, 250));
}
END_TEST

START_TEST(long_strings_dif) {
  char dst1[1024] =
      "AAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBABABABABABABABABABABABABB "
      "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL "
      "MMMMEMEMEMEMEMEMEMEMEMEMEMEMEMEMW "
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! LLLLL llllll";
  char dst2[1024] =
      "AAAAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBABABABABABABABABABABABABB "
      "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL "
      "MMMMEMEMEMEMEMEMEMEMEMEMEMEMEMEMW "
      "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! LLLLL llllll !!";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 250), memcmp(dst1, dst2, 250));
}
END_TEST

START_TEST(nulls) {
  char dst1[1024] = "\0";
  char dst2[1024] = "";
  ck_assert_int_eq(s21_memcmp(dst1, dst2, 5), memcmp(dst1, dst2, 5));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s = suite_create("Checking memcmp...");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, different);
  tcase_add_test(tc, size_is_zero);
  tcase_add_test(tc, everything_is_zero);
  tcase_add_test(tc, char_and_int);
  tcase_add_test(tc, int_and_double);
  tcase_add_test(tc, int_and_double_same);
  tcase_add_test(tc, register_check);
  tcase_add_test(tc, strings_are_zero);
  tcase_add_test(tc, long_strings_eq);
  tcase_add_test(tc, long_strings_dif);
  tcase_add_test(tc, nulls);
  suite_add_tcase(s, tc);
  return s;
}
