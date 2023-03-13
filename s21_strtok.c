#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last_tok = s21_NULL;
  s21_size_t count = 0;
  char *result = s21_NULL;
  int flag = 0;

  if (str) {
    last_tok = str;
  }

  if (last_tok[0] != '\0') {
    if (s21_strlen(last_tok) == s21_strcspn(last_tok, delim)) {
      flag = 1;
    }
    last_tok += s21_strspn(last_tok, delim);
    count += (s21_strcspn(last_tok, delim));

    last_tok[s21_strcspn(last_tok, delim)] = '\0';
    result = last_tok;
    if (flag == 1) {
      last_tok += count;
    } else {
      last_tok += count + 1;
    }

  } else {
    result = s21_NULL;
  }

  return result;
}