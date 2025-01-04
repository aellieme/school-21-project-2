LIBRARY = s21_string.a

SRCS = $(wildcard *.c)

HEADERS = $(SRCS:.c=.h)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra 

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	@ar rcs $@ $^

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

test: s21_string.a

	gcc $(CFLGS) $(TESTFLAGS) test/*.c s21_string.a -o run_test $(LDFLAGS)
	./run_test


clean:
	@rm -f $(OBJS) $(LIBRARY)

.PHONY: all clean