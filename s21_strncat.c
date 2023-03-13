#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0, len_1 = s21_strlen(dest);
  while (*(src + i) != '\0' && i != n) {
    *(dest + len_1 + i) = *(src + i);
    i++;
  }
  *(dest + len_1 + i) = '\0';
  return dest;
}
