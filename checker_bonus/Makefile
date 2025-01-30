SRCS = $(wildcard *.c)
OBJS = ${SRCS:.c=.o}
NAME = checker
LIBC = ar -r
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror


$(NAME) : $(OBJ) checker.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean