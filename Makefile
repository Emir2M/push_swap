CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
TEST_NAME = test_runner

SRCS = create_node.c \
       stack_init.c \
       stack_utils.c \
       swap_operations.c \
       push_operations.c \
       rotate_operations.c \
       reverse_rotate_operations.c \
       free_stack.c \
       ft_split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) push_swap.o
	$(CC) $(CFLAGS) $(OBJS) push_swap.o -o $(NAME)

$(TEST_NAME): $(OBJS) test_main.o
	$(CC) $(CFLAGS) $(OBJS) test_main.o -o $(TEST_NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_NAME)
	@./$(TEST_NAME)

clean:
	rm -f $(OBJS) push_swap.o test_main.o

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all test clean fclean re
