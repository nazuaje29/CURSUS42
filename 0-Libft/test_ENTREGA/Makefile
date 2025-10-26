CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = main

INCDIR = ../ENTREGA

LIBFT = $(INCDIR)/libft.a

SRCS = main.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = main_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) $(LIBFT) -o $(NAME) 

%.o: %.c $(INCDIR)/libft.h | 
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

bonus: $(OBJS_BONUS)
	$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS_BONUS) $(LIBFT) -o main_bonus

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f main_bonus.o

re: fclean all

.PHONY: all clean fclean re

