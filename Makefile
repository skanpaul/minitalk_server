NAME	= server

# **************************************************************************
CC		= gcc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -f

NORM	= norminette
NFLAG	= -R CheckForbiddenSourceHeader

LIBFTPATH = .
LIBFTNAME = ft

# **************************************************************************
HD		= server.h \
			libft.h
SRC		= server.c \
			init_data_server.c \
			stream_in_int.c \
			stream_in_str.c

OBJ		= $(SRC:.c=.o)

# **************************************************************************
all: $(NAME)

$(NAME): $(OBJ) $(HD)
	$(CC) $(CFLAG) -L$(LIBFTPATH) -l$(LIBFTNAME) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************
run:
	./$(NAME)

nono:
	$(NORM) $(NFLAG) $(SRC)
	$(NORM) $(NFLAG) $(HD)