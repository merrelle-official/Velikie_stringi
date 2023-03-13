#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i = 0, len_1 = s21_strlen(str1), len_2 = s21_strlen(str2);
  int out = 0;
  while (i != len_1 + 1 && i != len_2 + 1 && i != n) {
    if (*(str1 + i) == *(str2 + i)) {
      i++;
    } else {
      if (*(str1 + i) > *(str2 + i)) {
        out = 1;
      } else {
        out = -1;
      }
      break;
    }
  }
  return out;
}
