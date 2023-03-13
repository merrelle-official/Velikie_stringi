#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  void *temp = s21_NULL;
  if (dest && src) {
    temp = dest;
    char *arrDest = (char *)dest, *arrSrc = (char *)src;
    for (s21_size_t i = 0; i < n; i++) {
      arrDest[i] = arrSrc[i];
    }
  }
  return temp;
}
