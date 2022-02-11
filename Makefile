NAME	= server

CC		= gcc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -f

LIBFTPATH = .
LIBFTNAME = ft

SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)
# $(CC) $(CFLAG) -L$(LIBFTPATH) -l$(LIBFTNAME) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

run:
	./$(NAME)