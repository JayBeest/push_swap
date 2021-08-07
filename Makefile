NAME = checker
NAME2 = push_swap
SRCS_PATH = ./srcs/
TEST_PATH = ./ctest/
HEADER_FILES = push_swap.h libft.h get_next_line.h
TEST_HEADER_FILES = $(TEST_PATH)
SRCS_CHECKER = 	checker.c
SRCS_SHARED =	push_swap_errors.c \
				push_swap_debug.c \
				push_swap_operations.c \
				push_swap_parser.c \
				push_swap_ops.c
SRCS_PUSH_SWAP = push_swap.c
O_FILES_CHECKER = $(SRCS_SHARED:%.c=$(SRCS_PATH)%.o) $(SRCS_CHECKER:%.c=$(SRCS_PATH)%.o)
O_FILES_PUSH_SWAP = $(SRCS_SHARED:%.c=$(SRCS_PATH)%.o) $(SRCS_PUSH_SWAP:%.c=$(SRCS_PATH)%.o)
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
CC = clang

all: $(NAME) $(NAME2)

$(NAME): $(O_FILES_CHECKER)
	$(MAKE) -C ./libft
	$(MAKE) -C ./gnl
	$(CC) -o $@ $^ $(CFLAGS) -Llibft -Lgnl -lft -lgnl

$(NAME2): $(O_FILES_PUSH_SWAP)
	$(MAKE) -C ./libft
	$(MAKE) -C ./gnl
	$(CC) -o $@ $^ $(CFLAGS) -Llibft -Lgnl -lft -lgnl

%.o: %.c $(HEADER_FILES)
	$(CC) -o $@ $< $(CFLAGS) -Ilibft -Ignl -c

clean:
	rm $(O_FILES_CHECKER)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./gnl fclean
	rm $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
