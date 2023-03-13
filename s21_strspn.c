#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);
  int flag = 0;
  for (s21_size_t i = 0; i < len_str1; i++) {
    for (s21_size_t j = 0; j < len_str2; j++) {
      if (str1[i] == str2[j]) {
        result++;
        break;
      }
      if (j == len_str2 - 1 && str1[i] != str2[j]) {
        flag = 1;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  return result;
}