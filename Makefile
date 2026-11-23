CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = create_node.c \
       stack_init.c \
       stack_utils.c \
       swap_operations.c \
       push_operations.c \
       rotate_operations.c \
       reverse_rotate_operations.c \
       free_stack.c

OBJS = $(SRCS:.c=.o)
TEST_NAME = test_runner

all: $(TEST_NAME)

$(TEST_NAME): $(OBJS) test_main.o
	$(CC) $(CFLAGS) $(OBJS) test_main.o -o $(TEST_NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_NAME)
	@./$(TEST_NAME)

clean:
	rm -f $(OBJS) test_main.o

fclean: clean
	rm -f $(TEST_NAME)

re: fclean all

.PHONY: all test clean fclean re
