##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

SRC	=	src/main.c				\
		src/allocate_maze.c		\
		src/check_inside_cell.c	\
		src/trace_path.c		\
		src/print_maze.c		\
		src/imperfect_maze.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

CFLAGS += -Wall -Wextra -Wshadow -Wimplicit

LDFLAGS += -L./lib -lmy -lm

CPPFLAGS += -I./include

all:	$(NAME)
PHONY	+= all

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
PHONY	+= clean

fclean:	clean

PHONY	+= fclean

re:	fclean all
PHONY	+= re

unit_tests:
	cd tests && \
	gcc -o unit_tests $(addprefix ../, $(filter-out main.c, $(SRC))) \
	test_name.c --coverage -lcriterion
PHONY	+= unit_tests

tests_run:
	make unit_tests
	./tests/unit_tests
PHONY	+= tests_run

.PHONY:	$(PHONY)
