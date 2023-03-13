#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  s21_size_t len_1 = s21_strlen(str1), len_2 = s21_strlen(str2), i = 0;
  int out = 0;
  while (i != len_1 || i != len_2) {
    if (*(str1 + i) == *(str2 + i)) {
      i++;
    } else {
      if (*(str1 + i) > *(str2 + i)) {
        out = (int)(str1[i] - str2[i]);
      } else {
        out = (int)(str1[i] - str2[i]);
      }
      break;
    }
  }
  return out;
}