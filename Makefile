##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compilation file
##

CC	= gcc -g

RM	= rm -f

NAME	= mysh

SRC	= mysh.c    \
      my_str_to_wordtab.c   \
      get_line.c    \
      my_getenv.c   \
      my_getpath.c  \
      my_putchar.c  \
      my_putstr.c   \
      my_strcmp.c   \
      my_strncmp.c  \
      my_strlen.c   \
      my_fork.c

OBJ	= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	= -W -Wextra -Wall -I include/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
