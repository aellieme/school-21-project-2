TARGET = s21_sprintf
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS := s21_sprintf.c
OBJS := $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) *.o

rebuild: clean all

clang:
	clang-format -i *.c *.h
	clang-format -n *.c *.h
