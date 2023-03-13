#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024];
  char src[1024] = "prikol";
  ck_assert_ptr_eq(s21_memmove(dst, src, 10), memmove(dst, src, 10));
}
END_TEST

START_TEST(dst_empty) {
  char dst1[1024];
  char dst2[1024];
  char src[1024] = "prikol";
  s21_memmove(dst1, src, 10);
  memmove(dst2, src, 10);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 10);
#endif
}
END_TEST

START_TEST(dst_not_empty) {
  char dst1[1024] = "111";
  char dst2[1024] = "111";
  char src[1024] = "prikol";
  s21_memmove(dst1, src, 10);
  memmove(dst2, src, 10);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 10);
#endif
}
END_TEST

START_TEST(dst_not_empty_copying_part) {
  char dst1[1024] = "111";
  char dst2[1024] = "111";
  char src[1024] = "prikol";
  s21_memmove(dst1, src, 4);
  memmove(dst2, src, 4);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 4);
#endif
}
END_TEST

START_TEST(string_is_zero) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "";
  s21_memmove(dst1, src, 0);
  memmove(dst2, src, 0);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 0);
#endif
}
END_TEST

START_TEST(nums_copying_all) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "12345";

  s21_memmove(dst1, src, 6);
  memmove(dst2, src, 6);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 6);
#endif
}
END_TEST

START_TEST(string_with_register) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "Hello WORLD!";
  s21_memmove(dst1, src, 13);
  memmove(dst2, src, 13);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 13);
#endif
}
END_TEST

START_TEST(nums_copying_part) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "12345";
  s21_memmove(dst1, src, 4);
  memmove(dst2, src, 4);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 4);
#endif
}
END_TEST

START_TEST(string_with_register_part) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "Hello WORLD!";
  s21_memmove(dst1, src, 10);
  memmove(dst2, src, 10);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 10);
#endif
}
END_TEST

START_TEST(one_byte_nums) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "12345";
  s21_memmove(dst1, src, 1);
  memmove(dst2, src, 1);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 1);
#endif
}
END_TEST

START_TEST(one_byte_register) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "Hello world!";
  s21_memmove(dst1, src, 1);
  memmove(dst2, src, 1);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 1);
#endif
}
END_TEST

START_TEST(one_byte_basic) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "test";
  s21_memmove(dst1, src, 1);
  memmove(dst2, src, 1);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 1);
#endif
}
END_TEST

START_TEST(long_string_all) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] =
      "ABCDWOFWOFWOFWOFWFWFWFWFWFWFDFDFGDFdfgdfgdfg  gggggggg dddddd s s s s s "
      "ddddddddddd";
  s21_memmove(dst1, src, 84);
  memmove(dst2, src, 84);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 84);
#endif
}
END_TEST

START_TEST(long_string_part) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] =
      "ABCDWOFWOFWOFWOFWFWFWFWFWFWFDFDFGDFdfgdfgdfg  gggggggg dddddd s s s s s "
      "ddddddddddd";
  s21_memmove(dst1, src, 80);
  memmove(dst2, src, 80);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 80);
#endif
}
END_TEST

START_TEST(all_at_once) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "Abcd1234!!!!";
  s21_memmove(dst1, src, 13);
  memmove(dst2, src, 13);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 13);
#endif
}
END_TEST

START_TEST(ints) {
  int dst1[1024] = {0};
  int dst2[1024] = {0};
  int src[1024] = {5};
  s21_memmove(dst1, src, 4);
  memmove(dst2, src, 4);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 4);
#endif
}
END_TEST

START_TEST(overlap_chars) {
  char dst1[] = "1234567890";
  char dst2[] = "1234567890";
  s21_memmove(&dst1[4], &dst1[3], 3);
  memmove(&dst2[4], &dst2[3], 3);
  ck_assert_str_eq(dst1, dst2);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 3);
#endif
}
END_TEST

Suite *suite_memmove(void) {
  Suite *s = suite_create("Checking memmove...");
  TCase *tc = tcase_create("memmove_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, dst_empty);
  tcase_add_test(tc, dst_not_empty);
  tcase_add_test(tc, dst_not_empty_copying_part);
  tcase_add_test(tc, string_is_zero);
  tcase_add_test(tc, nums_copying_all);
  tcase_add_test(tc, nums_copying_part);
  tcase_add_test(tc, string_with_register);
  tcase_add_test(tc, string_with_register_part);
  tcase_add_test(tc, one_byte_nums);
  tcase_add_test(tc, one_byte_register);
  tcase_add_test(tc, one_byte_basic);
  tcase_add_test(tc, long_string_all);
  tcase_add_test(tc, long_string_part);
  tcase_add_test(tc, all_at_once);
  tcase_add_test(tc, ints);
  tcase_add_test(tc, overlap_chars);
  suite_add_tcase(s, tc);
  return s;
}
