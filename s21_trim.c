#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = s21_NULL;
  if (src && trim_chars) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t start = 0;
    s21_size_t end = src_len;
    start = s21_strspn(src, trim_chars);
    while (end > start && s21_strchr(trim_chars, src[end - 1])) {
      end--;
    }
    result = malloc(end - start + 1);
    if (result) {
      s21_memcpy(result, src + start, end - start);
      result[end - start] = '\0';
    }
  }
  return result;
}
