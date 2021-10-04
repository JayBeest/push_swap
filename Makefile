NAME = 		push_swap
NAME2 =		rando
SRC = 		main.c \
			operations.c \
			op_push_swap.c \
			op_rotate.c \
			custom_sort.c \
			radix_sort.c \
			utils.c \
			debug.c
RANDO_SRC = rando_bonus.c
SRC_DIR =	src
OBJ_DIR	= 	$(SRC_DIR)/obj
INCL = 		-I$(SRC_DIR)/incl
C_FLAGS = 	-Wall -Wextra -Werror
OBJ = 		$(SRC:%.c=$(OBJ_DIR)/%.o)
RANDO_OBJ = $(RANDO_SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: all

rando: $(NAME2)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) -o $@ $^ -Llibft -lft

$(NAME2): $(RANDO_OBJ)
	$(CC) -o $@ $< -Llibft -lft

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $< $(C_FLAGS) $(INCL) -Ilibft -c -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: clean all
