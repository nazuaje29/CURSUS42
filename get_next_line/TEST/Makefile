CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

NAME = main.out
NAME_LIB = get_next_line.a

SRCDIR = ../ENTREGA
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,%.o,$(SRCS))

SRC_MAIN = main.c
OBJ_MAIN = main.o

INCDIR = ../ENTREGA

LIBFT = get_next_line.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(SRC_MAIN) $(LIBFT) 

$(LIBFT): $(OBJS)
	ar rcs $(NAME_LIB) $(OBJS)

%.o: $(SRCDIR)/%.c $(INCDIR)/get_next_line.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

