NAME      = libftprintf.a
LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

CC        = cc
CFLAGS    = -Wall -Wextra -Werror -g -I. -I$(LIBFT_DIR)

SRCS      = ft_printf.c \
			parse.c \
			handle_char.c \
			handle_string.c \
			handle_void.c \
			handle_int.c \
			handle_unsigned_dec.c \
			handle_hexa_lower.c \
			handle_hexa_upper.c
OBJS      = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
