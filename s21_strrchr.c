#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  char rchr = c;
  if (str) {
    s21_size_t len_str = s21_strlen(str);
    for (s21_size_t i = 0; i < len_str; i++) {
      if (str[i] == rchr) {
        result = (char *)str + i;
      }
    }
  }

  return result;
}
