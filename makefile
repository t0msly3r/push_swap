CC = cc
CFLAGS = -Werror -Wextra -Wall -g -I . -I includes/
NAME = push_swap
SRC = src/utils.c src/movements.c src/algorithm.c src/utils_2.c src/main.c src/setters.c src/utils_3.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = includes/
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