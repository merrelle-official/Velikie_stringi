#include "tests.h"

Suite *make_master_suite(void) {
  Suite *s;
  s = suite_create("Start testing...");
  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  runner = srunner_create(make_master_suite());
  srunner_add_suite(runner, suite_memchr());

  srunner_add_suite(runner, suite_memcmp());
  srunner_add_suite(runner, suite_memcpy());
  srunner_add_suite(runner, suite_memmove());
  srunner_add_suite(runner, suite_memset());
  srunner_add_suite(runner, suite_strcat());
  srunner_add_suite(runner, suite_strchr());
  srunner_add_suite(runner, suite_strcmp());
  srunner_add_suite(runner, suite_strcpy());
  srunner_add_suite(runner, suite_strcspn());
  srunner_add_suite(runner, suite_strerror());
  srunner_add_suite(runner, suite_strlen());
  srunner_add_suite(runner, suite_strncat());
  srunner_add_suite(runner, suite_strncmp());
  srunner_add_suite(runner, suite_strncpy());
  srunner_add_suite(runner, suite_strpbrk());
  srunner_add_suite(runner, suite_strrchr());
  srunner_add_suite(runner, suite_strspn());
  srunner_add_suite(runner, suite_strstr());
  srunner_add_suite(runner, suite_strtok());
  srunner_add_suite(runner, suite_sprintf_d_i());
  srunner_add_suite(runner, suite_sprintf_c());
  srunner_add_suite(runner, suite_sprintf_f());
  srunner_add_suite(runner, suite_sprintf_u());
  srunner_add_suite(runner, suite_sprintf_s());
  srunner_add_suite(runner, suite_to_lower());
  srunner_add_suite(runner, suite_to_upper());
  srunner_add_suite(runner, suite_insert());
  srunner_add_suite(runner, suite_trim());
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
  return 0;
}
