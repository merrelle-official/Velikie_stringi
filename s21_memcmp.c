#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *buffer1 = (char *)str1;
  char *buffer2 = (char *)str2;
  int result = 0;

  if (str1 != s21_NULL && str2 != s21_NULL) {
    for (s21_size_t i = 0; i < n; ++i) {
      if (buffer1[i] != buffer2[i]) {
        result = buffer1[i] - buffer2[i];
        i = n;
      }
    }
  }
  return result;
}
