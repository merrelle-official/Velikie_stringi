#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = s21_NULL;
  if (src && str) {
    if (start_index <= s21_strlen(src)) {
      s21_size_t src_len = s21_strlen(src);
      s21_size_t str_len = s21_strlen(str);
      result = (char *)malloc(sizeof(char) * (src_len + str_len + 1));
      if (result) {
        s21_strncpy(result, src, start_index);
        s21_strncpy(result + start_index, str, str_len);
        s21_strncpy(result + start_index + str_len, src + start_index,
                    src_len - start_index);
        result[src_len + str_len] = '\0';
      }
    } else {
      s21_size_t src_len = s21_strlen(src);
      result = (char *)malloc(sizeof(char) * (src_len + 1));
      s21_strcpy(result, src);
    }
  }

  return result;
}
