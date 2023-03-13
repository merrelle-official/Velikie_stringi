#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_memchr(dst, 'e', 10), memchr(dst, 'e', 10));
}
END_TEST

START_TEST(changes) {
  /* checking whether the script
     changes our original string*/
  char dst1[1024] = "test";
  char dst2[1024] = "test";
  s21_memchr(dst1, 'e', 10);
  memchr(dst2, 'e', 10);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(no_memory) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_memchr(dst, 'e', 0), memchr(dst, 'e', 0));
}
END_TEST

START_TEST(no_symb) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_memchr(dst, 'x', 10), memchr(dst, 'x', 10));
}
END_TEST

START_TEST(find_zero) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_memchr(dst, '\0', 5), memchr(dst, '\0', 5));
}
END_TEST

START_TEST(in_the_beginning) {
  char dst[1024] = "It is a test";
  ck_assert_ptr_eq(s21_memchr(dst, 'I', 13), memchr(dst, 'I', 13));
}
END_TEST

START_TEST(in_the_end) {
  char dst[1024] = "It is a test mb";
  ck_assert_ptr_eq(s21_memchr(dst, 'b', 16), memchr(dst, 'b', 16));
}
END_TEST

START_TEST(several) {
  char dst[1024] = "abcdbbl";
  ck_assert_ptr_eq(s21_memchr(dst, 'b', 8), memchr(dst, 'b', 8));
}
END_TEST

START_TEST(find_int) {
  int dst[] = {1, 2, 4, 5, 9, 6, 8};

  ck_assert_ptr_eq(s21_memchr(dst, 9, sizeof(int) * 7 + 1),
                   memchr(dst, 9, sizeof(int) * 7 + 1));
}
END_TEST

START_TEST(empty_everything) {
  char dst[1024] = "";
  ck_assert_ptr_eq(s21_memchr(dst, '\0', 0), memchr(dst, '\0', 0));
}
END_TEST

START_TEST(int_in_char) {
  char dst[1024] = "abc3df";
  ck_assert_ptr_eq(s21_memchr(dst, 3, 7), memchr(dst, 3, 7));
}
END_TEST

START_TEST(questionable) {
  char dst[1024] = "abc\0df";
  ck_assert_ptr_eq(s21_memchr(dst, '\0', 10), memchr(dst, '\0', 10));
}
END_TEST

START_TEST(find_double) {
  double dst[1024] = {2.4, 5.6, 6.7, 9.7};
  double check = 2.4;
  ck_assert_ptr_eq(s21_memchr(dst, check, sizeof(double) * 4 + 1),
                   memchr(dst, check, sizeof(double) * 4 + 1));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("Checking memchr...");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, changes);
  tcase_add_test(tc, no_memory);
  tcase_add_test(tc, no_symb);
  tcase_add_test(tc, find_zero);
  tcase_add_test(tc, in_the_beginning);
  tcase_add_test(tc, in_the_end);
  tcase_add_test(tc, several);
  tcase_add_test(tc, find_int);
  tcase_add_test(tc, empty_everything);
  tcase_add_test(tc, int_in_char);
  tcase_add_test(tc, questionable);
  tcase_add_test(tc, find_double);

  suite_add_tcase(s, tc);
  return s;
}
