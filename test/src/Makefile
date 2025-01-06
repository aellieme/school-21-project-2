LIBRARY = s21_string.a

SRCS = $(wildcard *.c)
HEADERS = $(SRCS:.c=.h)
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lcheck -lm -lrt -pthread -lsubunit

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

test/%.o: test/%.c
	$(CC) $(CFLAGS) -c $< -o $@

TEST_SRCS = $(filter-out test/main.c, $(wildcard test/*.c))
TEST_OBJS = $(TEST_SRCS:.c=.o)

test: $(TEST_OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) test/main.c $(TEST_OBJS) $(LIBRARY) -o run_test $(LDFLAGS)
	./run_test

gcov_report: CFLAGS += --coverage
gcov_report: clean $(LIBRARY)
	$(CC) $(CFLAGS) $(SRCS) test/main.c $(TEST_SRCS) -o run_test_with_gcov $(LDFLAGS)
	./run_test_with_gcov
	# lcov -t "Report" -c -d . --output-file coverage.info
	# genhtml coverage.info --output-directory gcov_report
	lcov --rc branch_coverage=1 -d . -o s21_string_coverage.info -c
	genhtml --branch-coverage s21_string_coverage.info --output-directory gcov_report
	open gcov_report/index.html

clean:
	rm -f $(OBJS) $(LIBRARY) run_test run_test_with_gcov
	rm -rf gcov_report coverage.info
	rm -f test/*.o
	rm -rf *.gcno *.gcov *.gcda
	rm -rf report/

.PHONY: all clean test gcov_report