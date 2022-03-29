##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	main.c				\
		mysh.c				\
		mysh2.c				\
		my_cd.c				\
		my_cd2.c			\
		str_to_tab.c		\
		path_to_tab.c		\
		my_print_err.c		\
		my_setenv.c			\
		my_unsetenv.c		\
		my_arrdup.c			\
		display_arr.c		\
		environnement.c		\
		do_exit.c			\
		do_special_cmd.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CPPFLAGS += -I include

all: $(NAME)

lib/libmy.a:
	make -C lib/my

$(NAME): lib/libmy.a $(OBJ)
	gcc -o $(NAME) $(OBJ) -L lib -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:
	make clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all

.PHONY:	all	clean fclean re
