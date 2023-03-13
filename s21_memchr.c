#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *address = s21_NULL;
  char *arr = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (arr[i] == c) {
      address = &arr[i];
      break;
    }
  }
  return address;
}
