#  -fsanitize=address
CC=gcc
CFLAGS=-Wall -Wextra -Werror
CHECKFLAGS=-lcheck -lm -lpthread
GCOVFLAGS=-fprofile-arcs -ftest-coverage
STRINGFILES = s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_strcat.c s21_strchr.c s21_strcmp.c s21_strcpy.c s21_strcspn.c s21_strerror.c s21_strlen.c s21_strncat.c s21_strncmp.c s21_strncpy.c s21_strpbrk.c s21_strrchr.c s21_strspn.c s21_strstr.c s21_strtok.c s21_sprintf.c s21_to_lower.c s21_to_upper.c s21_trim.c s21_insert.c
OUT=exec
TESTFILES = tests/memcmp_test.c tests/memchr_test.c tests/memcpy_test.c tests/memmove_test.c tests/memset_test.c tests/strcat_test.c tests/strchr_test.c tests/strcmp_test.c tests/strcpy_test.c tests/strcspn_test.c tests/strerror_test.c tests/strlen_test.c tests/tests_main.c tests/strncat_test.c tests/strncmp_test.c tests/strncpy_test.c tests/strpbrk_test.c tests/strrchr_test.c tests/strspn_test.c tests/strstr_test.c  tests/sprintf_test_d_i.c tests/sprintf_test_c.c tests/sprintf_test_f.c tests/sprintf_test_u.c tests/sprintf_test_s.c tests/to_lower_test.c tests/to_upper_test.c tests/insert_test.c tests/trim_test.c tests/strtok_test.c

all: s21_string.a

tests: test gcov_report

gcov_report:
	$(CC) -o $(OUT) $(GCOVFLAGS) $(STRINGFILES) $(TESTFILES) $(CHECKFLAGS)
	./$(OUT)
	lcov -capture --directory . --output-file main_coverage.info
	genhtml *.info -o ./gcov_report
	rm -rf *.gcda *.gcno *.info exec a.out

test:
	$(CC) $(STRINGFILES) $(TESTFILES) $(CHECKFLAGS)

s21_string.a:
	$(CC) -c $(STRINGFILES)
	clang-format -i *.[ch]
	ar -rc s21_string.a *.o
	rm -rf *.o

clean:
	rm -rf gcov_report tests/*.o ./a.out *.o *.gcda *.gcno *.info exec s21_string.a main

main_test:
	gcc -Wall -Wextra -Werror -c *.c
	ar rc s21_string.a *.o
	ranlib s21_string.a
	rm -rf *.o
	gcc main.c -L./ s21_string.a -o main