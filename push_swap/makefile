CC = cc
CFLAGS = -Werror -Wextra -Wall
NAME = libsort.a
SRC = utils.c movements.c algorithm.c utils_2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	$(CC) $(CFLAGS) main.c -L. -lsort