##
## EPITECH PROJECT, 2023
## makefile
## File description:
## task01 day10
##

NAME	=	libmy.a

SRCS	=	count_nums.c my_put_nbr.c my_putchar.c	\
			my_putstr.c	\
			my_strlen.c	\
			my_printf.c	\
			my_putnbr_base.c my_put_address.c \
			my_count_putchar.c	\
			my_count_putnbr.c	\
			my_count_putstr.c	\
			my_count_putfloat.c	\
			my_count_putu.c		\
			my_count_putepower.c	\
			my_count_putshort.c	\
			my_count_putshortd.c	\
			my_count_putli.c	\
			my_count_putprecision.c	\
			my_count_shorter.c	\
			my_strcpy.c	\
			my_strncpy.c	\
			my_strcat.c	\
			my_strcmp.c	\
			my_getnbr.c	\
			my_revstr.c	\
			count_float.c	\
			my_putnbr_base_preci.c	\
			my_count_shortermaj.c	\
			my_count_floatpreci.c	\
			my_compute_power_rec.c	\
			my_count_puthexa_preci.c	\
			putprecision_special.c	\
			my_count_putspace.c	\
			my_count_puthash.c	\
			my_count_putlx.c	\
			my_count_putnum.c	\
			plusmincond.c	\
			my_count_putflag.c	\
			my_count_putformatdb.c	\
			split_string.c	\
			my_int_to_str.c	\
			my_strdup.c	\
			load_arr_from_file.c	\

OBJS	=	$(SRCS:.c=.o)

TESTS	=	../../tests/test_my_printf.c

NAME_TEST	=	unit-tests

CPPFLAGS	=	-I./include/

CFLAGS	=	-g3 -W -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	cp $(NAME) ../../

clean:
	rm -f $(OBJS)
	rm -f *~

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all

tests_run:
	$(CC) -o $(NAME_TEST) --coverage -lcriterion $(SRCS) ../../tests/*.c
	$(CPPFLAGS)
	./$(NAME_TEST)
