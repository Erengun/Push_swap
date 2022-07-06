NAME=libftprintf.a
LIBFT=libft/libft.a

SRCS=ft_printf.c printf_utils.c
OBJS=$(SRCS:.c=.o)

BONUS_OBJS=$(BONUS:.c=.o)

CC=gcc
CFLAGS=-Wall -Wextra -Werror

# $@ - target
# $^ - butun dependen
# $< - ilk dependen

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C ./libft
	@cp libft/libft.a $(NAME)
	@ar rcs $@ $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^

clean:
	@make clean -C ./libft
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all
	@make re -C ./libf

.PHONY: all clean fclean re bonus