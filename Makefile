CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM = rm -f

NAME 	= push_swap
BONUS = checker

SRCS = mandatory/main.c $(wildcard mandatory/commands/*.c) $(wildcard mandatory/stack_management/*.c) $(wildcard mandatory/error_management/*.c) $(wildcard mandatory/push_swap_sort/*.c) $(wildcard mandatory/parsing/*.c)
SRCS_BONUS = $(wildcard bonus/*.c)  $(wildcard bonus/commands/*.c) $(wildcard bonus/gnl/*.c) $(wildcard bonus/stack_management/*.c) $(wildcard bonus/error_management/*.c) $(wildcard bonus/push_swap_sort/*.c) $(wildcard bonus/parsing/*.c)
OBJ = $(SRCS:.c=.o)
OBJB = $(SRCS_BONUS:.c=.o)

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
