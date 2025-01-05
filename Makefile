LIBRARY = s21_string.a
SRCS = $(wildcard *.c)
HEADERS = $(SRCS:.c=.h)
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra
GCOV_FLAGS = -fprofile-arcs -ftest-coverage --coverage
LIBS = -lcheck -lm -lpthread

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	@ar rcs $@ $^

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

test: $(LIBRARY)
	$(CC) $(CFLAGS) test/*.c $(LIBRARY) -o run_test $(LIBS)
	./run_test

gcov_report: s21_string.a
	gcc $(GCC_FLAGS) --coverage main.c $(TEST_C_FILES) $(SRC_C_FILES) s21_string.a -L. s21_string.a $(TEST_FLAGS) -o $(BUILD_PATH)$(EXE) 
	$(BUILD_PATH)$(EXE)
	lcov -t "Report" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/
	open $(BUILD_PATH)report/index.html


clean:
	@rm -rf *.o *.a *.gcno *.gcda *.info run_test report/

.PHONY: all clean test gcov_report
