#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  s21_size_t i = 0;
  int flag = 0;
  if (str1 && str2 && *str1 != '\0' && *str2 != '\0') {
    s21_size_t len_str1 = s21_strlen(str1);
    s21_size_t len_str2 = s21_strlen(str2);
    for (; i < len_str1; i++) {
      for (s21_size_t j = 0; j < len_str2; j++) {
        if (str1[i] == str2[j]) {
          result = (char *)str1;
          flag = 1;
          break;
        }
      }
      if (flag == 1) {
        break;
      }
    }
  }

  if (flag == 0) {
    i = 0;
  }

  return result + i;
}
