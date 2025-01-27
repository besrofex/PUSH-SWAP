CC		= cc
CFLAGS	= -Wall -Werror -Wextra

NAME 	= push_swap
SRCS = $(wildcard *.c) $(wildcard stack_management/*.c) $(wildcard error_management/*.c) $(wildcard push_swap_sort/*.c)
OBJ = $(SRCS:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) -o $(NAME)
	
%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
