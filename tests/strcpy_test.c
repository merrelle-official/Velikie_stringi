#include <check.h>

#include "tests.h"

START_TEST(empty) {
  char src[1024] = "";
  char dst_ori[1024] = "test";
  char dst_test[1024] = "test";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(smaller) {
  char src[1024] = "test";
  char dst_ori[1024] = "";
  char dst_test[1024] = "";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(bigger) {
  char src[1024] = "test";
  char dst_ori[1024] = "aaaaaaaaaaa";
  char dst_test[1024] = "aaaaaaaaaaa";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(num_base) {
  char src[] = "12345";
  char dst_ori[16] = "88888";
  char dst_test[16] = "88888";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(num_empty) {
  char src[] = "12345";
  char dst_ori[10] = "";
  char dst_test[10] = "";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(num_bigger) {
  char src[] = "12345";
  char dst_ori[16] = "123456789";
  char dst_test[16] = "123456789";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(register_base) {
  char src[] = "ABCDe";
  char dst_ori[16] = "AAAAA";
  char dst_test[16] = "AAAAA";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(register_empty) {
  char src[] = "ABCDe";
  char dst_ori[10] = "";
  char dst_test[10] = "";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(register_bigger) {
  char src[] = "ABCDe";
  char dst_ori[20] = "AVGHRFGKS";
  char dst_test[20] = "AVGHRFGKS";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(symb_base) {
  char src[] = "!@#$%";
  char dst_ori[16] = "*****";
  char dst_test[16] = "*****";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(symb_empty) {
  char src[] = "!@#$%";
  char dst_ori[10] = "";
  char dst_test[10] = "";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(symb_bigger) {
  char src[] = "***";
  char dst_ori[15] = "*()#&^^";
  char dst_test[15] = "*()#&^^";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(all_at_once_base) {
  char src[] = "1bA!@";
  char dst_ori[16] = "^^hH4";
  char dst_test[16] = "^^hH4";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(all_at_once_empty) {
  char src[] = "1bA!5";
  char dst_ori[10] = "";
  char dst_test[10] = "";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

START_TEST(all_at_once_bigger) {
  char src[] = "aB4(";
  char dst_ori[15] = "AA1()f4!";
  char dst_test[15] = "AA1()f4!";
  ck_assert_str_eq(s21_strcpy(dst_test, src), strcpy(dst_ori, src));
}
END_TEST

Suite *suite_strcpy(void) {
  Suite *s = suite_create("Checking strcpy...");
  TCase *tc = tcase_create("strcpy_tc");

  tcase_add_test(tc, empty);
  tcase_add_test(tc, smaller);
  tcase_add_test(tc, bigger);
  tcase_add_test(tc, num_base);
  tcase_add_test(tc, num_empty);
  tcase_add_test(tc, num_bigger);
  tcase_add_test(tc, symb_base);
  tcase_add_test(tc, symb_empty);
  tcase_add_test(tc, symb_bigger);
  tcase_add_test(tc, register_base);
  tcase_add_test(tc, register_empty);
  tcase_add_test(tc, register_bigger);
  tcase_add_test(tc, all_at_once_base);
  tcase_add_test(tc, all_at_once_empty);
  tcase_add_test(tc, all_at_once_bigger);

  suite_add_tcase(s, tc);
  return s;
}
