CC		= cc
CFLAGS	= -Wall -Werror -Wextra

NAME 	= push_swap
SRC = 
OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean
