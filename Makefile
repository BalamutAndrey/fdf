NAME=fdf

CC=gcc
FLAGS=-g -lmlx -framework OpenGL -framework AppKit -lm 
#-Wall -Wextra -Werror

SRC_DIR=./srcs
OBJ_DIR=./obj
LIB_DIR=./libft

SRC_NAME=fdf.c \
		fdf_error.c \
		fdf_func.c \
		fdf_struct.c \
		fdf_readmap.c \
		fdf_map_valid.c \
		gnl.c \
		gnl_clear.c \
		fdf_init.c \
		fdf_keyboard.c \
		fdf_draw.c


SRC = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))

OBJ = $(SRC)
INC = -I ./includes -I $(LIB_DIR)/includes

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(LIB_DIR)
	@$(CC) -o $(NAME) $(SRC) \
		$(LIB_DIR)/libft.a -lncurses -ltermcap $(INC) $(FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@$(CC) -o $@ -c $< $(INC) $(FLAGS)
	@printf "\033[0m\033[36%-45s\033[1m\033[34m%s\033[0m\n" "m$(notdir $<)" "OK"

clean:
		@make clean -s -C $(LIB_DIR)
		@rm -f $(OBJ)

fclean: clean
		@make fclean -s -C $(LIB_DIR)
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re
