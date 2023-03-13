#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  void *temp = s21_NULL;
  if (dest != s21_NULL && src != s21_NULL) {
    temp = dest;

    char *arrDest = (char *)dest, *arrSrc = (char *)src;
    char *cur = (char *)malloc(sizeof(char) * n);
    if (cur) {
      for (s21_size_t i = 0; i < n; i++) {
        cur[i] = arrSrc[i];
      }
      for (s21_size_t i = 0; i < n; i++) {
        arrDest[i] = cur[i];
      }
      free(cur);
    }
  }
  return temp;
}
