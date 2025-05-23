CC = cc
CFLAGS = -Werror -Wextra -Wall -g -I . -I includes/
NAME = push_swap
SRC = src/utils.c src/movements.c src/algorithm.c src/utils_2.c src/main.c src/setters.c src/movements_2.c src/checkers.c src/getter.c src/print.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = lib/
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L $(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re