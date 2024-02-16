##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC		=	hash.c \
			new_hashtable.c \
			delete_hashtable.c \
			ht_delete.c \
			ht_dump.c \
			ht_insert.c \
			ht_search.c \
			push_to_list.c \
			mini_printf.c \
			my_putchar.c	\
			my_put_nbr.c	\
			my_putstr.c	\
			my_strcmp.c	\
			my_strdup.c	\
			my_strlen.c

SRC_MAIN	=	main.c

TEST_SRC	= 	$(SRC)	\
				tests/test_create_del.c \
				tests/test_delete.c \
				tests/test_insert.c \
				tests/test_search.c

TESTS	=	unit_tests

CRFLAGS	=	--coverage -lcriterion

OBJ	=	$(SRC:.c=.o)

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

NAME	=	secured

LIBHASHNAME	=	libhashtable.a

LIBHASH = -L. -lhashtable

all:	$(LIBHASHNAME)

$(LIBHASHNAME):	$(OBJ)
	ar rc -o $(LIBHASHNAME) $(OBJ)

$(NAME):	re $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ_MAIN) $(LIBHASH) -I./include/ -Wall -Wextra \
		-Werror

tests_run: lib
	gcc -o $(TESTS) $(TEST_SRC) $(CRFLAGS)
	./$(TESTS)

clean:
	rm -f $(OBJ) $(OBJ_MAIN) *~ \
	*.gcda *.gcno

fclean:	clean
	rm -f $(NAME) $(TESTS) $(LIBHASHNAME)

re:     fclean all

.PHONY: lib $(LIBHASHNAME) $(NAME)
