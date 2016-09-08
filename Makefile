CC = gcc
FLAGS = -Wall -Werror -Wextra -o
FILES = main.c grid_setup.c checkavail.c
NAME = solve_sudoku

all : $(NAME)

$(NAME) :
	$(CC) $(FILES) $(FLAGS) $(NAME)

fclean :
	/bin/rm -f $(NAME)
re : fclean all

.PHONY : fclean re 
