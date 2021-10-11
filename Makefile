NAME = 		push_swap
NAME2 =		checker
NAME3 =		rando
SRC = 		main.c \
			operations.c \
			custom_sort.c \
			radix_sort.c
SHARE_SRC =	parser.c \
			operations.c \
			op_push_swap.c \
			op_rotate.c \
			debug.c \
			utils.c
CHECK_SRC =	checker.c
RANDO_SRC =	rando_bonus.c
SRC_DIR =	src
OBJ_DIR	=	$(SRC_DIR)/obj
INCL = 		-I$(SRC_DIR)/incl
C_FLAGS =	-g -Wall -Wextra -Werror -fsanitize=address
OBJ = 		$(SRC:%.c=$(OBJ_DIR)/%.o)
SHARE_OBJ =	$(SHARE_SRC:%.c=$(OBJ_DIR)/%.o)
CHECK_OBJ =	$(CHECK_SRC:%.c=$(OBJ_DIR)/%.o)
RANDO_OBJ = $(RANDO_SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(NAME) $(NAME2) $(NAME3)

$(NAME): $(OBJ) $(SHARE_OBJ)
	$(MAKE) -C libft
	$(CC) $(C_FLAGS) -o $@ $^ -Llibft -lft

$(NAME2): $(CHECK_OBJ) $(SHARE_OBJ)
	$(MAKE) -C libft
	$(CC) $(C_FLAGS) -o $@ $^ -Llibft -lft

$(NAME3): $(RANDO_OBJ)
	$(CC) $(C_FLAGS) -o $@ $< -Llibft -lft

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $< $(C_FLAGS) $(INCL) -Ilibft -c -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME) $(NAME2) $(NAME3)

re: clean all
