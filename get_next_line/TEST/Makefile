CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = main.out
NAME_LIB = get_next_line.a

SRCDIR = ../ENTREGA
OBJDIR = obj
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

SRC_MAIN = main.c
OBJ_MAIN = main.o

INCDIR = ../ENTREGA

LIBFT = get_next_line.a

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_MAIN) $(LIBFT) 

$(LIBFT): $(OBJS)
	ar rcs $(NAME_LIB) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/get_next_line.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

