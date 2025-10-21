CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = main
OBJDIR = obj
SRCDIR = .
INCDIR = ../ENTREGA
LIBFT = $(INCDIR)/libft.a
SRCS = main.c
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCDIR) $(OBJS) $(LIBFT) -o $(NAME) 

$(OBJDIR)/%.o: %.c $(INCDIR)/libft.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -r $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

