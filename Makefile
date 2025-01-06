LIBRARY = s21_string.a

test_fails = test/test_insert.c test/test_memchr.c test/test_memcmp.c test/test_memcpy.c test/test_memset.c
ma:=$(test_fails:.c=.o)

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
	gcc $(CFLAGS) test/main.c $(TEST_OBJS) s21_string.a -o run_test $(LDFLAGS)

gcov_report:$(LIBRARY) $(TEST_OBJS)
	gcc -Wall -Werror -Wextra --coverage test/main.c  $(TEST_OBJS) s21_string.a -lcheck -lm -lsubunit -o test_with_gcov
	./test_with_gcov
	rm test_with_gcov
	mkdir report
	gcovr --html-details -o ./report/report.html --exclude test/main.c

clean:
	rm -f $(OBJS) $(LIBRARY) run_test test_with_gcov
	rm -rf report
	rm test/*.o

.PHONY: all clean test gcov_report