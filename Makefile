##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

all:	$(NAME)
	cd ./generator && make
	cd ./solver && make
PHONY	+= all

clean:
	cd ./generator && make fclean
	cd ./solver && make fclean
PHONY	+= clean

fclean:	clean
	cd ./generator && make clean
	cd ./solver && make clean
PHONY	+= fclean

re:	fclean all
PHONY	+= re

unit_tests:
	cd tests && \
	gcc -o unit_tests $(addprefix ../, $(filter-out main.c, $(SRC))) \
	test_bsq.c --coverage -lcriterion
PHONY	+= unit_tests

tests_run:
	make unit_tests
	./tests/unit_tests
PHONY	+= tests_run

.PHONY:	$(PHONY)
