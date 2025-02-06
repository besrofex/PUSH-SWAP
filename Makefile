CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
RM = rm -f

NAME 	= push_swap
NAME_BONUS = checker

SRCS = mandatory/main.c $(wildcard mandatory/commands/*.c) $(wildcard mandatory/stack_management/*.c) $(wildcard mandatory/error_management/*.c) $(wildcard mandatory/push_swap_sort/*.c) $(wildcard mandatory/parsing/*.c)
SRCS_BONUS = $(wildcard bonus/*.c)
OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

mandatory/%.o: mandatory/%.c mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
bonus/%.o: bonus/%.c bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(BONUS): $(OBJB)
	$(CC) $(OBJB) -o $(BONUS)

clean :
	$(RM) $(OBJ) $(OBJB)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY: clean
