#include <check.h>

#include "tests.h"

START_TEST(base) {
  char dst[1024] = "testTESTTesttestTEstteSt";
  char dst1[1024] = "testTESTTesttestTEstteSt";
  char delim[] = "eE";

  char *res = s21_strtok(dst, delim);
  char *res1 = strtok(dst1, delim);

  while (res && res1) {
    ck_assert_str_eq(res, res1);
    res = s21_strtok(NULL, delim);
    res1 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(start_delim) {
  char dst[1024] = "testTESTTesttestTEstteSt";
  char dst1[1024] = "testTESTTesttestTEstteSt";
  char delim[] = "t";

  char *res = s21_strtok(dst, delim);
  char *res1 = strtok(dst1, delim);

  while (res && res1) {
    ck_assert_str_eq(res, res1);
    res = s21_strtok(NULL, delim);
    res1 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(no_delim) {
  char dst[1024] = "testTESTTesttestTEstteSt";
  char dst1[1024] = "testTESTTesttestTEstteSt";
  char delim[] = "5";

  char *res = s21_strtok(dst, delim);
  char *res1 = strtok(dst1, delim);

  while (res && res1) {
    ck_assert_str_eq(res, res1);
    res = s21_strtok(NULL, delim);
    res1 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(num) {
  char dst[1024] = "12356785345254";
  char dst1[1024] = "12356785345254";
  char delim[] = "5";

  char *res = s21_strtok(dst, delim);
  char *res1 = strtok(dst1, delim);

  while (res && res1) {
    ck_assert_str_eq(res, res1);
    res = s21_strtok(NULL, delim);
    res1 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(symb) {
  char dst[1024] = "Hello!!!Wold!!!";
  char dst1[1024] = "Hello!!!Wold!!!";
  char delim[] = "!!!";

  char *res = s21_strtok(dst, delim);
  char *res1 = strtok(dst1, delim);

  while (res && res1) {
    ck_assert_str_eq(res, res1);
    res = s21_strtok(NULL, delim);
    res1 = strtok(NULL, delim);
  }
}
END_TEST

START_TEST(all) {
  char dst[1024] = "Hell o!!12 3!Wol 2d! !!";
  char dst1[1024] = "Hell o!!12 3!Wol 2d! !!";
  char delim[] = " ";

  char *res = s21_strtok(dst, delim);
  char *res1 = strtok(dst1, delim);

  while (res && res1) {
    ck_assert_str_eq(res, res1);
    res = s21_strtok(NULL, delim);
    res1 = strtok(NULL, delim);
  }
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s = suite_create("Checking strtok...");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, base);
  tcase_add_test(tc, start_delim);
  tcase_add_test(tc, no_delim);
  tcase_add_test(tc, num);
  tcase_add_test(tc, symb);
  tcase_add_test(tc, all);

  suite_add_tcase(s, tc);
  return s;
}
