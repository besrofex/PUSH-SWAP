CC		= cc
CFLAGS	= -Wall -Werror -Wextra

NAME 	= push_swap
NAME_BONUS = checker
SRCS = $(wildcard *.c) $(wildcard stack_management/*.c) $(wildcard error_management/*.c) $(wildcard push_swap_sort/*.c)
SRCS_BONUS = $(wildcard checker/*.c)
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) -o $(NAME)
	
%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus :$(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	cc $(OBJ_BONUS) -o $(NAME_BONUS)
	
%.o : %.c checker.h
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re
