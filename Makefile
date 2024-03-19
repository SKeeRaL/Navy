##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## maje file
##

NAME    =	my_navy

SRCS    =	src/main.c	\
			src/NAVY/navy.c	\
			src/NAVY/connection.c	\
			src/NAVY/map.c	\
			src/NAVY/defense.c	\
			src/NAVY/attack.c	\
			src/CSFML/game.c	\
			src/CSFML/menu.c	\
			src/CSFML/connect.c	\
			src/CSFML/init_dest.c	\
			src/CSFML/att_def.c	\

OBJS    =    $(SRCS:.c=.o)

CPPFLAGS    =	-I./includes/ -L./lib/my -lmy

CFLAGS    =   	-W -Wextra -Wall -lcsfml-graphics	\
				-lcsfml-audio -lcsfml-window -lcsfml-system -lm

all:    $(NAME)

lib_make:
	make -C ./lib/my

sujet: $(OBJS)
	make -C ./lib/my
	ar rc libhashtable.a $(OBJS)
	cp libhashtable.a ../

$(NAME): lib_make $(OBJS)
	@echo "\033[1;30m🕐 Marco à l'heure, pas Raph... 🕐\033[0m"
	@gcc -o $(NAME) $(OBJS) $(CPPFLAGS) $(CFLAGS)
	@echo "\033[1;33m🔒 Secured en 1 jour on est où 🔒\033[0m"

clean:
	@rm -f $(OBJS)

fclean: clean
	@echo "\033[1;34m🧹 MrPropre au charbon 🧹\033[0m"
	@rm -f $(NAME)
	@rm -f *.o
	@rm -f *.a
	@make fclean -C ./lib/my
	@echo "\033[1;33m🪄  Tutty Propo 🪄\033[0m"

re: fclean all

tests_run:
	make tests_run -C ./lib/my
