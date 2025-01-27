CC = cc 
NAME = checker
CFLAGS = -Wall -Wextra -werror
ARCHIVE = ../push_swap

SRCS = $(wildcard *.c)
OBJS = $(SRCS = .c:.o)

all : $(NAME)

%.o = %.c checker.h
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) = $(OBJS) $(ARCHIVE)
	$(CC) $^ -o $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -F $(NAME)

re : clean all

.PHONY : all clean fclean re
