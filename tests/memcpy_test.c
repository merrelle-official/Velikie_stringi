#include <check.h>

#include "tests.h"

START_TEST(pointers) {
  /*check if functions return the same value*/
  char dst[1024];
  char src[1024] = "prikol";
  ck_assert_ptr_eq(s21_memcpy(dst, src, 10), memcpy(dst, src, 10));
}
END_TEST

START_TEST(copying) {
  /*check if copying occurs*/
  char dst1[1024];
  char dst2[1024];
  char src[1024] = "prikol";
  s21_memcpy(dst1, src, 10);
  memcpy(dst2, src, 10);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(integrity) {
  /*check if source string stays the same*/
  char dst[1024];
  char src[1024] = "prikol";
  char src_copy[1024];
  strcpy(src_copy, src);
  s21_memcpy(dst, src, 10);
  memcpy(dst, src, 10);
  ck_assert_str_eq(src_copy, src);
}
END_TEST

START_TEST(string_is_zero) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "";
  s21_memcpy(dst1, src, 0);
  memcpy(dst2, src, 0);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 0);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(nums_copying_all) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "12345";

  s21_memcpy(dst1, src, 6);
  memcpy(dst2, src, 6);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 6);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(string_with_register) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "Hello WORLD!";
  s21_memcpy(dst1, src, 13);
  memcpy(dst2, src, 13);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 13);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(nums_copying_part) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "12345";
  s21_memcpy(dst1, src, 4);
  memcpy(dst2, src, 4);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 4);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(string_with_register_part) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "Hello WORLD!";
  s21_memcpy(dst1, src, 10);
  memcpy(dst2, src, 10);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 10);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(one_byte_nums) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "12345";
  s21_memcpy(dst1, src, 1);
  memcpy(dst2, src, 1);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 1);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(one_byte_register) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "Hello world!";
  s21_memcpy(dst1, src, 1);
  memcpy(dst2, src, 1);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 1);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(one_byte_basic) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "test";
  s21_memcpy(dst1, src, 1);
  memcpy(dst2, src, 1);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 1);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(long_string_all) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] =
      "ABCDWOFWOFWOFWOFWFWFWFWFWFWFDFDFGDFdfgdfgdfg  gggggggg dddddd s s s s s "
      "ddddddddddd";
  s21_memcpy(dst1, src, 84);
  memcpy(dst2, src, 84);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 84);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(long_string_part) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] =
      "ABCDWOFWOFWOFWOFWFWFWFWFWFWFDFDFGDFdfgdfgdfg  gggggggg dddddd s s s s s "
      "ddddddddddd";
  s21_memcpy(dst1, src, 80);
  memcpy(dst2, src, 80);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 80);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(all_at_once) {
  char dst1[1024] = {0};
  char dst2[1024] = {0};
  char src[1024] = "Abcd1234!!!!";
  s21_memcpy(dst1, src, 13);
  memcpy(dst2, src, 13);
#if __APPLE__
  ck_assert_mem_eq(dst1, dst2, 13);
#endif
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s = suite_create("Checking memcpy...");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, pointers);
  tcase_add_test(tc, copying);
  tcase_add_test(tc, integrity);
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
  suite_add_tcase(s, tc);
  return s;
}
