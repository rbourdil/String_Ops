NAME = strops

OBJS = main.o add.o diff.o subops.o reverse.o pop.o

HEAD = strops.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

$(OBJS):	%.o:%.c $(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re
