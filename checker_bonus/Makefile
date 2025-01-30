SRCS = $(wildcard *.c)
OBJS = ${SRCS:.c=.o}
NAME = checker.a
LIBC = ar -r
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
# DPRINTF= ft_printf
# DLIBFT = Libft
# PATH_LIBFT=./Libft/libft.a
# PATH_PRINTF=./ft_printf/libftprintf.a


$(NAME) : $(OBJ) checker.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean