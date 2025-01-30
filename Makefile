CC		= cc
CFLAGS	= -Wall -Werror -Wextra

NAME 	= push_swap
NAME_BONUS = checker
SRCS = $(wildcard *.c) $(wildcard stack_management/*.c) $(wildcard error_management/*.c) $(wildcard push_swap_sort/*.c)
SRCS_BONUS = $(wildcard checker_bonus/*.c)
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)



$(NAME) : $(OBJ) push_swap.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	
# %.o : %.c 
# 	$(CC) $(CFLAGS) -c $< -o $@

all:$(NAME)
bonus :$(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_BONUS)
	make all -C checker_bonus
	$(CC) $(CFLAGS) ./checker_bonus/checker.a -o $(NAME_BONUS)
	
# %.o : %.c checker.h
# 	$(CC) $(CFLAGS) -c $< -o $@


clean :
	make clean -C checker_bonus
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean : clean
	make fclean -C checker_bonus
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re
