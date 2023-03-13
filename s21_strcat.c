#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  if (dest && src) {
    s21_size_t dest_len = s21_strlen(dest);
    s21_size_t src_len = s21_strlen(src);
    for (s21_size_t i = 0; i < src_len; i++) {
      dest[i + dest_len] = src[i];
    }
    dest[dest_len + src_len] = '\0';
  }

  return dest;
}