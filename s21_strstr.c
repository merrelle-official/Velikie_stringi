#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  s21_size_t len_haystack = s21_strlen(haystack);
  s21_size_t len_needle = s21_strlen(needle);
  int flag = 0;
  for (s21_size_t i = 0; i < len_haystack; i++) {
    if (haystack[i] == needle[0]) {
      result = (char *)haystack + i;
      for (s21_size_t j = 0; j < len_needle; j++) {
        if (haystack[i + j] != needle[j]) {
          result = s21_NULL;
          break;
        }
        if (j == len_needle - 1) {
          flag = 1;
        }
      }
    }
    if (flag == 1) {
      break;
    }
  }
  return result;
}