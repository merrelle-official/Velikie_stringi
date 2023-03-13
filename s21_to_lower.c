#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *result = NULL;
  if (str != NULL) {
    int len = s21_strlen(str);
    result = (char *)malloc(len + 1);
    if (result != NULL) {
      for (int i = 0; i < len; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
          result[i] = str[i] + 32;
        } else {
          result[i] = str[i];
        }
      }

      result[len] = '\0';
    }
  }
  return result;
}
