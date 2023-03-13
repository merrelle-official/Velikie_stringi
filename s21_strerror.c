#include "s21_string.h"

char *int_to_char2(long int num, char *str);

char *s21_strerror(int errnum) {
  char *result = s21_NULL;
  char *errors[] = ERR_LIST;
  char *tests = (char *)malloc(sizeof(char) * 1024);
  char *unerror = tests;
  for (int i = 0; i < 1024; i++) {
    unerror[i] = 0;
  }
  if (errnum >= 0 && errnum < N) {
    result = errors[errnum];
    free(tests);
  } else {
    char message[8192] = "Unknown error: ";

    unerror = int_to_char2(errnum, unerror);

    result = s21_strcat(message, unerror);
    free(tests);
  }

  return result;
}

char *int_to_char2(long int num, char *str) {
  int digit = 0;
  long int temp = num;
  int isNegative = 0;

  while (temp != 0) {
    temp /= 10;
    digit++;
  }
  temp = num;
  if (temp < 0) {
    temp *= -1;
    isNegative = 1;
    digit++;
    str[0] = '-';
  }

  for (int i = digit - 1; i >= isNegative; i--) {
    str[i] = '0' + temp % 10;
    temp /= 10;
  }

  return str;
}