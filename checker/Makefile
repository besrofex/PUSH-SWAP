CC = cc 
NAME = checker
CFLAGS = -Wall -werror -Wextra

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME) = $(OBJS)
	$(CC) $^ -o $(NAME)

%.o = %.c checker.h
	$(CC) -c $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re
