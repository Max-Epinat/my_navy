##
## EPITECH PROJECT, 2023
## B-CPE-110-MAR-1-1-organized-maxime.finaud
## File description:
## Makefile
##

NAME	=		my_navy

SRC		=		./src/main.c		\
				./src/openfile.c	\
				./src/my_strlen.c	\
				./src/my_strdup.c	\
				./src/my_strcmp.c	\
				./src/my_putstr.c	\
				./src/my_putchar.c	\
				./src/my_put_nbr.c	\
				./src/my_compute_power_rec.c	\
				./src/my_printf.c	\
				./src/my_getnbr.c	\
				./src/stock.c		\
				./src/description.c	\
				./src/char_star.c	\
				./src/signal.c		\
				./src/attack1.c		\
				./src/attack1_1.c	\
				./src/attack2.c 	\
				./src/error.c		\

SRC_TEST		=	./src/openfile.c	\
				./src/my_strlen.c	\
				./src/my_strdup.c	\
				./src/my_strcmp.c	\
				./src/my_putstr.c	\
				./src/my_putchar.c	\
				./src/my_put_nbr.c	\
				./src/my_compute_power_rec.c	\
				./src/my_printf.c	\
				./src/my_getnbr.c	\
				./src/stock.c		\
				./src/description.c	\
				./src/char_star.c	\
				./src/signal.c		\
				./src/attack1.c		\
				./src/attack1_1.c	\
				./src/attack2.c 	\
				./src/error.c		\


OBJ		=		$(SRC:.c=.o)

TEST	=	tests/tests.c

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) -I./includes -g3
		make clean

%.o: %.c
	gcc -c -g -o $@ $<

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f *.gcno *.gcda *.gcov unittest

re:	fclean all

coding-style:
	coding-style . .
	cat -e coding-style-reports.log
	rm -f coding-style-reports.log

tests_run:
	gcc $(TEST) -o unittest --coverage -lcriterion $(SRC_TEST)
	./unittest
