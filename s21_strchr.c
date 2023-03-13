#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  s21_size_t i = 0;
  char *out = s21_NULL;
  while (*(str + i) != '\0') {
    if (*(str + i) == c) {
      out = (char *)(str + i);
      break;
    }
    i++;
  }
  if (*(str + i) == c) {
    out = (char *)(str + i);
  }
  return out;
}
