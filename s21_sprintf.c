#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *result = str;
  char *spec_list = "cdifsu%", *flag_list = " -+", *length_list = "hl";
  arg argu = {0};
  va_list value;
  va_start(value, format);
  while (*format != '\0') {
    if (*format != '%') {
      *str = *format;
      ++str;
      ++format;
    } else {
      char buffer_result[1024] = {
          0,
      };
      char *buffer_of_spec = s21_NULL;
      char *tests = s21_NULL;
      tests = (char *)malloc(1024 * sizeof(char));
      buffer_of_spec = tests;

      if (tests) {
        ++format;
        buffer_of_spec = spec_parser(format, buffer_of_spec, spec_list, &argu);

        format += (int)s21_strlen(buffer_of_spec);
        buffer_of_spec = read_flag(buffer_of_spec, flag_list, &argu);

        if (*buffer_of_spec != '.') {
          if (*buffer_of_spec >= '0' && *buffer_of_spec <= '9') {
            buffer_of_spec = read_width(buffer_of_spec, &argu);
          }
        }
        if (*buffer_of_spec == '.') {
          buffer_of_spec++;
          if (*buffer_of_spec >= '0' && *buffer_of_spec <= '9') {
            buffer_of_spec = read_acc(buffer_of_spec, &argu);
          }
        } else {
          argu.acc = -1;
        }
        buffer_of_spec = read_length(buffer_of_spec, &argu, length_list);
        fill_result(buffer_result, &argu, &value);
        s21_size_t len_buff = s21_strlen(buffer_result);
        for (s21_size_t i = 0; i < len_buff; i++) {
          *str = buffer_result[i];
          ++str;
        }

        s21_memset(&argu, 0, sizeof(argu));

        free(tests);
      }
    }
  }
  return str - result;
}

char *spec_parser(const char *format, char *buffer_of_spec, char *spec_list,
                  arg *argu) {
  s21_size_t len_spec = s21_strcspn(format, spec_list);
  for (s21_size_t i = 0; i <= len_spec; i++) {
    buffer_of_spec[i] = format[i];
  }
  buffer_of_spec[len_spec + 1] = '\0';
  argu->spec = buffer_of_spec[len_spec];
  return buffer_of_spec;
}

char *read_flag(char *buffer_of_spec, char *flag_list, arg *argu) {
  s21_size_t len_flags = s21_strspn(buffer_of_spec, flag_list);
  for (s21_size_t i = 0; i < len_flags; i++) {
    if (buffer_of_spec[i] == ' ') {
      argu->space = 1;
    } else if (buffer_of_spec[i] == '-') {
      argu->minus = 1;
    } else if (buffer_of_spec[i] == '+') {
      argu->plus = 1;
    }
  }
  buffer_of_spec += len_flags;
  return buffer_of_spec;
}

char *read_width(char *buffer_of_spec, arg *argu) {
  int result = 0;
  s21_size_t len_result = s21_strspn(buffer_of_spec, "0123456789");
  for (s21_size_t i = 0; i < len_result; i++) {
    result = result * 10 + (buffer_of_spec[i] - '0');
  }
  argu->width = result;
  buffer_of_spec += len_result;
  return buffer_of_spec;
}

char *read_acc(char *buffer_of_spec, arg *argu) {
  int result = 0;
  s21_size_t len_result = s21_strspn(buffer_of_spec, "0123456789");
  for (s21_size_t i = 0; i < len_result; i++) {
    result = result * 10 + (buffer_of_spec[i] - '0');
  }
  argu->acc = result;
  buffer_of_spec += len_result;
  return buffer_of_spec;
}

char *read_length(char *buffer_of_spec, arg *argu, char *length_list) {
  int len_length = s21_strspn(buffer_of_spec, length_list);
  if (buffer_of_spec[0] == 'h') {
    argu->lenght = buffer_of_spec[0];
  } else if (buffer_of_spec[0] == 'l') {
    argu->lenght = buffer_of_spec[0];
  }
  buffer_of_spec += len_length;
  return buffer_of_spec;
}

void fill_result(char *buffer_result, arg *argu, va_list *value) {
  switch (argu->spec) {
    case 'c':
      if (argu->minus) {
        fill_char(buffer_result, argu, value);
        for (int i = 1; i <= argu->width - 1; i++) {
          buffer_result[i] = ' ';
        }
      } else {
        if (argu->width) {
          argu->width--;
        }

        for (int i = 0; i < argu->width; i++) {
          buffer_result[i] = ' ';
        }
        fill_char(buffer_result + argu->width, argu, value);
      }
      break;
    case 'd':
      fill_integer(buffer_result, argu, value);
      break;
    case 'i':
      fill_integer(buffer_result, argu, value);
      break;
    case 'f':
      double_to_str(value, buffer_result, argu);
      break;
    case 's':
      fill_string(buffer_result, argu, value);
      break;
    case 'u':
      fill_unsigned(buffer_result, argu, value);
      break;
    case '%':
      buffer_result[0] = '%';
      break;
  }
}

void fill_char(char *buffer_result, arg *argu, va_list *value) {
  if (argu->lenght != 'l') {
    char result = (char)va_arg(*value, int);
    buffer_result[0] = result;
  } else {
    wchar_t result = va_arg(*value, wchar_t);
    wcstombs(buffer_result, &result, 1023);
  }
}

void fill_integer(char *buffer_result, arg *argu, va_list *value) {
  long int result = va_arg(*value, long int), IsNeative = 0, counter = 0;
  switch (argu->lenght) {
    case 'h':
      result = (short)result;
      break;
    case 'l':
      result = (long int)result;
      break;
    default:
      result = (int)result;
      break;
  }

  if (result < 0) {
    result *= -1;
    IsNeative = 1;
  }

  if (argu->acc < digits(result)) {
    argu->acc = 0;
  }

  if (!argu->acc) {
    if (argu->width >= digits(result)) {
      argu->width -= digits(result);
    } else {
      argu->width = 0;
    }
  }

  if (argu->width >= argu->acc) {
    argu->width -= argu->acc;
  } else {
    argu->width = 0;
  }

  if (argu->space && !argu->plus && !IsNeative) {
    buffer_result[counter] = ' ';
    argu->width--;
    counter++;
  }
  if (!argu->minus) {
    if (IsNeative) {
      argu->width--;
    }
    for (int i = 0; i < argu->width; i++) {
      buffer_result[counter] = ' ';
      counter++;
    }
  }
  if (argu->plus && !IsNeative) {
    buffer_result[counter] = '+';
    counter++;
  }
  if (IsNeative) {
    buffer_result[counter] = '-';

    counter++;
  }

  counter += int_to_char(result, buffer_result + counter, argu);

  if (argu->minus) {
    if (IsNeative) {
      argu->width--;
    }
    for (int i = 0; i < argu->width; i++) {
      buffer_result[counter + i] = ' ';
    }
  }
}

int int_to_char(long int num, char *str, arg *argu) {
  int digit = 0;
  long int temp = num;
  while (temp != 0) {
    temp /= 10;
    digit++;
  }
  if (argu->acc > digit) {
    digit = argu->acc;
  }
  temp = num;
  for (int i = digit - 1; i >= 0; i--) {
    str[i] = '0' + temp % 10;
    temp /= 10;
  }
  return digit;
}

int digits(long int num) {
  int digit = 0;
  while (num != 0) {
    num /= 10;
    digit++;
  }
  return digit;
}

void fill_unsigned(char *buffer_result, arg *argu, va_list *value) {
  long unsigned result = va_arg(*value, long unsigned), counter = 0;
  switch (argu->lenght) {
    case 'h':
      result = (short unsigned)result;
      break;
    case 'l':
      result = (long unsigned)result;
      break;
    default:
      result = (unsigned)result;
      break;
  }

  if (argu->acc < digits_un(result)) {
    argu->acc = 0;
  }

  if (!argu->acc) {
    if (argu->width >= digits_un(result)) {
      argu->width -= digits_un(result);
    } else {
      argu->width = 0;
    }
  }

  if (argu->width >= argu->acc) {
    argu->width -= argu->acc;
  } else {
    argu->width = 0;
  }
  if (!argu->minus) {
    for (int i = 0; i < argu->width; i++) {
      buffer_result[counter] = ' ';
      counter++;
    }
  }
  counter += unsigned_to_char(result, buffer_result + counter, argu);
  if (argu->minus) {
    for (int i = 0; i < argu->width; i++) {
      buffer_result[counter + i] = ' ';
    }
  }
}

int unsigned_to_char(long unsigned num, char *str, arg *argu) {
  int digit = 0;
  long unsigned temp = num;
  while (temp != 0) {
    temp /= 10;
    digit++;
  }
  if (argu->acc > digit) {
    digit = argu->acc;
  }
  temp = num;
  for (int i = digit - 1; i >= 0; i--) {
    str[i] = '0' + temp % 10;
    temp /= 10;
  }
  return digit;
}

int digits_un(long unsigned num) {
  int digit = 0;
  while (num != 0) {
    num /= 10;
    digit++;
  }
  return digit;
}

void fill_string(char *buffer_result, arg *argu, va_list *value) {
  if (argu->lenght != 'l') {
    just_string(buffer_result, argu, value);
  } else {
    wchar_t *n = va_arg(*value, wchar_t *);
    wcstombs(buffer_result, n, 1023);
  }
}

void just_string(char *buffer_result, arg *argu, va_list *value) {
  char *n = va_arg(*value, char *);
  s21_size_t len = s21_strlen(n);
  if (argu->acc != -1) {
    argu->width -= argu->acc;
  } else {
    argu->width -= (int)len;
  }

  int count = 0;

  if (!argu->minus) {
    for (int i = 0; i < argu->width; i++) {
      buffer_result[i] = ' ';
      count++;
    }
  }
  if (argu->acc != -1) {
    s21_strncpy(buffer_result + count, n, argu->acc);
  } else {
    s21_strcpy(buffer_result + count, n);
  }
  len = s21_strlen(buffer_result);
  count = (int)len;
  if (argu->minus) {
    for (int i = count; i < argu->width + count; i++) {
      buffer_result[i] = ' ';
    }
  }
}

void double_to_str(va_list *value, char *mas, arg *argu) {
  double num = va_arg(*value, double);
  int x = num, y = 0, flag = 0, h = 0, flag_0 = 0, check_0 = 0, check_num = 0,
      check_num_2 = 0, check_space = 0, x2 = 0, check_plus = 0;
  s21_size_t j = 1, g = 0;
  if (x >= 1 || x <= -1) {
    while (x / 10 != 0) {
      x /= 10;
      j++;
    }
    if (num >= 0) {
      check_num_2++;
    }
  } else {
    check_num++;
    flag_0++;
    check_0++;
  }
  if (argu->space == 1 || argu->plus == 1) {
    check_space++;
  }
  if (num < 0) {
    flag++;
  }
  if (argu->acc == -1) {
    j += 6;
  } else {
    j += argu->acc;
  }
  char *mas_2 = ecvt(num, j, &x, &y);
  j = s21_strlen(mas_2) + flag + 1;
  g = argu->width;
  if (g > j && argu->minus == 0) {
    x2 = j - flag - check_space;
    for (h = 0;
         h < argu->width - x2 - flag - check_0 - check_space - check_num_2;
         h++) {
      *(mas + h) = ' ';
    }
    x2 = 0;
  }
  if (flag) {
    *(mas + h) = '-';
    h++;
  } else {
    if (argu->plus == 1) {
      if (argu->acc > 1 || argu->acc == -1) {
        check_plus++;
      }
      *(mas + h) = '+';
      h++;
    } else {
      if (argu->space == 1) {
        *(mas + h) = ' ';
        h++;
      }
    }
  }
  if (check_num) {
    *(mas + h) = '0';
    h++;
    y = 1;
    int v = 0;
    for (; v < argu->acc; v++) {
      y *= 10;
      g = num * y;
      if (g == 0) {
        x2 = 0 - argu->acc;
        check_0++;
        *(mas + h) = '0';
        h++;
        if (v == argu->acc - 1 && *mas_2 > '4') {
          *(mas + h - 1) = *(mas + h - 1) + 1;
        }
      } else {
        x2 = x;
        break;
      }
    }
    v = argu->acc;
    if (v == -1) {
      v = 6;
    }
    if (check_0 > 0 && *(mas_2 + v) > '4') {
      while (v != 0) {
        if (*(mas_2 + v - 1) != '9') {
          *(mas_2 + v - 1) = *(mas_2 + v - 1) + 1;
          break;
        } else {
          *(mas_2 + v - 1) = '0';
          v--;
          if (v == 0) {
            *(mas + s21_strlen(mas) - argu->acc) =
                *(mas + s21_strlen(mas) - argu->acc) + 1;
          }
        }
      }
    }
    x = x2;
  }
  for (j = 0; j < s21_strlen(mas_2) - check_0; h++, j++) {
    *(mas + h) = *(mas_2 + j);
  }
  char check;
  y = s21_strlen(mas);
  int i = y - 1 + flag + check_0;
  y = s21_strlen(mas_2);
  if (argu->width <= y) {
    y = 0;
  } else {
    if (argu->minus == 0) {
      y = argu->width - y - 1 - flag;
    } else {
      y = 0;
    }
  }
  if (argu->acc < 2 && argu->acc != -1) {
    i++;
  }
  if (argu->acc != 0) {
    int flag_min_space = 0;
    if (argu->minus == 1 && argu->space == 1 && num > 0) {
      flag_min_space = 1;
    }
    int space = 0;
    if (argu->space == 1 && argu->minus == 0 &&
        (int)s21_strlen(mas_2) + 2 > argu->width) {
      space = 1;
    }
    if (argu->space == 1 && num < 0 && argu->width <= (int)s21_strlen(mas_2)) {
      space--;
    }
    if (argu->plus == 1 && argu->width <= (int)s21_strlen(mas_2) &&
        argu->acc <= 1 && argu->acc != -1) {
      check_plus++;
    }
    while (i != x + y + flag + check_0 + flag_min_space + check_plus + space) {
      check = *(mas + i);
      *(mas + i) = *(mas + i - 1);
      *(mas + i + 1) = check;
      i--;
    }
    *(mas + i) = '.';
  }
  if (argu->width > y && argu->minus == 1) {
    h = s21_strlen(mas);
    if ((int)s21_strlen(mas) <= argu->width) {
      j = argu->width - s21_strlen(mas);
    } else {
      j = 0;
    }
    for (g = 0; g < j; g++, h++) {
      *(mas + h) = ' ';
    }
    *(mas + h) = '\0';
  }
}
