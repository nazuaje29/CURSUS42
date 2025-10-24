CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = main

INCDIR = ../ENTREGA

LIBFT = $(INCDIR)/libft.a

SRCS = main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) $(LIBFT) -o $(NAME) 

%.o: %.c $(INCDIR)/libft.h | 
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

