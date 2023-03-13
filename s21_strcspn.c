#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  if (str1 && str2) {
    s21_size_t len_str1 = s21_strlen(str1);
    s21_size_t len_str2 = s21_strlen(str2);

    for (s21_size_t i = 0; i < len_str1; i++) {
      for (s21_size_t j = 0; j < len_str2; j++) {
        if (str1[i] == str2[j]) {
          result = i;
          len_str1 = i;
          break;
        }
        if (i == len_str1 - 1 && str1[i] != str2[j]) {
          result = len_str1;
        }
      }
    }
    if (*str2 == '\0') {
      result = len_str1;
    }
  }

  return result;
}
