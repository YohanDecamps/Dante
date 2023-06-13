##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

SRC	=	src/main.c	            	\
		src/utils.c             	\
        src/solver.c   				\
		src/printer.c				\
        src/get_str_to_line_array.c	\
		src/get_maze.c				\
		src/queu_handler.c


OBJ	=	$(SRC:.c=.o)

NAME	=	solver

CFLAGS += -Wextra -Wshadow -Wimplicit

CPPFLAGS += -I./include

all:	$(NAME)
PHONY	+= all

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
PHONY	+= clean

fclean:	clean
	rm -f $(NAME)

PHONY	+= fclean

re:	fclean all
PHONY	+= re

.PHONY:	$(PHONY)
