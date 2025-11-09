CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(OBJS_BON)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

