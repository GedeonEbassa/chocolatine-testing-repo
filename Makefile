##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## my_top Makefile
##

CC ?= clang

SRC     =       ./SRC/main.c    \
                ./SRC/my_str_to_word_array.c	\
				./SRC/my_mini_printf.c	\
				./SRC/string.c	\
				./SRC/string2.c	\
				./SRC/file.c	\
				./SRC/array_utils.c	\
				./SRC/callexecv.c	\
				./SRC/env.c	\
				./SRC/builtin_setenv.c	\
				./SRC/builtin_unsetenv.c	./SRC/trim.c	\
				./SRC/operator.c	./SRC/operator2.c	\
				./SRC/pipe.c\

NAME = mysh

all:    $(NAME)

$(NAME): $(SRC)
	$(CC) -o $(NAME) $(SRC)
clean:
	rm -f $(NAME)
	rm -f *~
	rm -f #*
	rm -f "*#"
fclean: clean

re: fclean all
