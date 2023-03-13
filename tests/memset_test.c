#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  ck_assert_ptr_eq(s21_memset(dst, 'e', 10), memset(dst, 'e', 10));
}
END_TEST

START_TEST(base_empty) {
  char dst1[10] = "";
  char dst2[10] = "";
  s21_memset(dst1, 'e', 5);
  memset(dst2, 'e', 5);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(base_full) {
  char dst1[] = "abcdefg";
  char dst2[] = "abcdefg";
  s21_memset(dst1, 'e', 5);
  memset(dst2, 'e', 5);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(base_empty_num) {
  char dst1[10] = "";
  char dst2[10] = "";
  s21_memset(dst1, '2', 5);
  memset(dst2, '2', 5);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST
START_TEST(base_full_num) {
  char dst1[] = "abcdefg";
  char dst2[] = "abcdefg";
  s21_memset(dst1, '2', 5);
  memset(dst2, '2', 5);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(base_empty_register) {
  char dst1[10] = "";
  char dst2[10] = "";
  s21_memset(dst1, 'B', 5);
  memset(dst2, 'B', 5);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(base_full_register) {
  char dst1[] = "abcdefg";
  char dst2[] = "abcdefg";
  s21_memset(dst1, 'B', 5);
  memset(dst2, 'B', 5);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(one_byte_full) {
  char dst1[] = "abcdefg";
  char dst2[] = "abcdefg";
  s21_memset(dst1, 'l', 1);
  memset(dst2, 'l', 1);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(one_byte_num_full) {
  char dst1[] = "abcdefg";
  char dst2[] = "abcdefg";
  s21_memset(dst1, '5', 1);
  memset(dst2, '5', 1);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

// START_TEST(empty_everything1) {
//   char dst1[] = "";
//   char dst2[] = "";
//   s21_memset(dst1, 'l', 0);
//   memset(dst2, 'l', 0);
//   ck_assert_str_eq(dst1, dst2);
// }
// END_TEST

// START_TEST(empty_everything2) {
//   char dst1[] = "";
//   char dst2[] = "";
//   s21_memset(dst1, '\0', 0);
//   memset(dst2, '\0', 0);
//   ck_assert_str_eq(dst1, dst2);
// }
// END_TEST

START_TEST(long_string) {
  char dst1[] =
      "DFHSFDHSFHShhhhhh gggggfgfgfgfgfg l ll l l l l l ll l l l l!!!!!! !!!!! "
      "wew";
  char dst2[] =
      "DFHSFDHSFHShhhhhh gggggfgfgfgfgfg l ll l l l l l ll l l l l!!!!!! !!!!! "
      "wew";
  s21_memset(dst1, 'f', 10);
  memset(dst2, 'f', 10);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(not_char) {
  int a = 1;
  char dst1[] = "12345";
  char dst2[] = "12345";
  s21_memset(dst1, a, 5);
  memset(dst2, a, 5);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s = suite_create("Checking memset...");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, base_empty);
  tcase_add_test(tc, base_full);
  tcase_add_test(tc, base_empty_num);
  tcase_add_test(tc, base_full_num);
  tcase_add_test(tc, base_empty_register);
  tcase_add_test(tc, base_full_register);
  tcase_add_test(tc, one_byte_num_full);
  tcase_add_test(tc, one_byte_full);
  // tcase_add_test(tc, empty_everything1);
  // tcase_add_test(tc, empty_everything2);
  tcase_add_test(tc, long_string);
  tcase_add_test(tc, not_char);

  suite_add_tcase(s, tc);
  return s;
}
