LIBRARY = s21_string.a

SRCS = $(wildcard *.c)

HEADERS = $(SRCS:.c=.h)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -fPIC

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	@ar rcs $@ $^

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(LIBRARY)

.PHONY: all clean
