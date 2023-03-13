#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "test";
  char dst2[1024] = "test";
  ck_assert_str_eq(s21_strncat(dst, "haha", 10), strncat(dst2, "haha", 10));
}
END_TEST

START_TEST(empty1) {
  char dst[10] = "";
  char dst2[10] = "";
  ck_assert_str_eq(s21_strncat(dst, "", 0), strncat(dst2, "", 0));
}
END_TEST

START_TEST(empty2) {
  char dst[10] = "";
  char dst2[10] = "";
  ck_assert_str_eq(s21_strncat(dst, "", 1), strncat(dst2, "", 1));
}
END_TEST

START_TEST(empty3) {
  char dst[10] = "";
  char dst2[10] = "";
  ck_assert_str_eq(s21_strncat(dst, "", 5), strncat(dst2, "", 5));
}
END_TEST

START_TEST(base1) {
  char dst[10] = "test";
  char dst2[10] = "test";
  ck_assert_str_eq(s21_strncat(dst, "test", 1), strncat(dst2, "test", 1));
}
END_TEST

START_TEST(base2) {
  char dst[10] = "test";
  char dst2[10] = "test";
  ck_assert_str_eq(s21_strncat(dst, "test", 3), strncat(dst2, "test", 3));
}
END_TEST

START_TEST(num1) {
  char dst[10] = "1234";
  char dst2[10] = "1234";
  ck_assert_str_eq(s21_strncat(dst, "123", 5), strncat(dst2, "123", 5));
}
END_TEST

START_TEST(num2) {
  char dst[10] = "1234";
  char dst2[10] = "1234";
  ck_assert_str_eq(s21_strncat(dst, "1234", 2), strncat(dst2, "1234", 2));
}
END_TEST

START_TEST(num3) {
  char dst[10] = "1234";
  char dst2[10] = "1234";
  ck_assert_str_eq(s21_strncat(dst, "1234", 1), strncat(dst2, "1234", 1));
}
END_TEST

START_TEST(symb1) {
  char dst[10] = "!@#$";
  char dst2[10] = "!@#$";
  ck_assert_str_eq(s21_strncat(dst, "****", 5), strncat(dst2, "****", 5));
}
END_TEST

START_TEST(symb2) {
  char dst[10] = "!@#$";
  char dst2[10] = "!@#$";
  ck_assert_str_eq(s21_strncat(dst, "****", 2), strncat(dst2, "***", 2));
}
END_TEST

START_TEST(symb3) {
  char dst[10] = "!@#$";
  char dst2[10] = "!@#$";
  ck_assert_str_eq(s21_strncat(dst, "****", 1), strncat(dst2, "***", 1));
}
END_TEST

START_TEST(all1) {
  char dst[15] = "ABC1%a";
  char dst2[15] = "ABC1%a";
  ck_assert_str_eq(s21_strncat(dst, "AB3!a", 5), strncat(dst2, "AB3!a", 5));
}
END_TEST

START_TEST(all2) {
  char dst[15] = "ABC1%a";
  char dst2[15] = "ABC1%a";
  ck_assert_str_eq(s21_strncat(dst, "AB3!a", 2), strncat(dst2, "AB3!a", 2));
}
END_TEST

START_TEST(all3) {
  char dst[15] = "ABC1%a";
  char dst2[15] = "ABC1%a";
  ck_assert_str_eq(s21_strncat(dst, "AB3!a", 1), strncat(dst2, "AB3!a", 1));
}
END_TEST

START_TEST(huge1) {
  char dst[160] =
      "HELLO WORLD huge huge !!!!! #$^$^#$^ DDDDD fffhss "
      "gkfgyjdktymlkadmglkamerla ()";
  char dst2[160] =
      "HELLO WORLD huge huge !!!!! #$^$^#$^ DDDDD fffhss "
      "gkfgyjdktymlkadmglkamerla ()";
  ck_assert_str_eq(s21_strncat(dst,
                               "HDFDFG!!!! dfgsdfhs GGGGG DDSKKLJLH !!!! "
                               "DKRGSEKLRGNSELKR 134645(%&^(%@",
                               72),
                   strncat(dst2,
                           "HDFDFG!!!! dfgsdfhs GGGGG DDSKKLJLH !!!! "
                           "DKRGSEKLRGNSELKR 134645(%&^(%@",
                           72));
}
END_TEST

START_TEST(huge2) {
  char dst[160] =
      "HELLO WORLD huge huge !!!!! #$^$^#$^ DDDDD fffhss "
      "gkfgyjdktymlkadmglkamerla ()";
  char dst2[160] =
      "HELLO WORLD huge huge !!!!! #$^$^#$^ DDDDD fffhss "
      "gkfgyjdktymlkadmglkamerla ()";
  ck_assert_str_eq(s21_strncat(dst,
                               "HDFDFG!!!! dfgsdfhs GGGGG DDSKKLJLH !!!! "
                               "DKRGSEKLRGNSELKR 134645(%&^(%@",
                               45),
                   strncat(dst2,
                           "HDFDFG!!!! dfgsdfhs GGGGG DDSKKLJLH !!!! "
                           "DKRGSEKLRGNSELKR 134645(%&^(%@",
                           45));
}
END_TEST

START_TEST(huge3) {
  char dst[160] =
      "HELLO WORLD huge huge !!!!! #$^$^#$^ DDDDD fffhss "
      "gkfgyjdktymlkadmglkamerla ()";
  char dst2[160] =
      "HELLO WORLD huge huge !!!!! #$^$^#$^ DDDDD fffhss "
      "gkfgyjdktymlkadmglkamerla ()";
  ck_assert_str_eq(s21_strncat(dst,
                               "HDFDFG!!!! dfgsdfhs GGGGG DDSKKLJLH !!!! "
                               "DKRGSEKLRGNSELKR 134645(%&^(%@",
                               1),
                   strncat(dst2,
                           "HDFDFG!!!! dfgsdfhs GGGGG DDSKKLJLH !!!! "
                           "DKRGSEKLRGNSELKR 134645(%&^(%@",
                           1));
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s = suite_create("Checking strncat...");
  TCase *tc = tcase_create("strncat_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, base1);
  tcase_add_test(tc, base2);
  tcase_add_test(tc, empty1);
  tcase_add_test(tc, empty2);
  tcase_add_test(tc, empty3);
  tcase_add_test(tc, num1);
  tcase_add_test(tc, num2);
  tcase_add_test(tc, num3);
  tcase_add_test(tc, symb1);
  tcase_add_test(tc, symb2);
  tcase_add_test(tc, symb3);
  tcase_add_test(tc, all1);
  tcase_add_test(tc, all2);
  tcase_add_test(tc, all3);
  tcase_add_test(tc, huge1);
  tcase_add_test(tc, huge2);
  tcase_add_test(tc, huge3);
  suite_add_tcase(s, tc);
  return s;
}
