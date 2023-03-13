#include <check.h>

#include "tests.h"

START_TEST(base) {
  for (int i = -100; i < 107; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s = suite_create("Checking strerror...");
  TCase *tc = tcase_create("strerror_tc");

  tcase_add_test(tc, base);

  suite_add_tcase(s, tc);
  return s;
}
