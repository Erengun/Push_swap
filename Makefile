# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 15:08:45 by egun              #+#    #+#              #
#    Updated: 2022/07/14 15:12:50 by egun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGSS = -Wall -Wextra -Werror
SRCS = commands.c arg.c push_swap.c selectionSort.c utils.c radix.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CC = gcc
LIB = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME) : $(LIB)  $(OBJS)
	gcc $(OBJS) ./ft_printf/libftprintf.a -o $(NAME)

$(LIB) :
	@make -C ft_printf/
	@echo "libft compiled."

.c.o:
	$(CC) $(CFLAGSS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)

fclean: clean
	make fclean -C ft_printf/

re: clean all

norm:
	@norminette *.[ch]

.PHONY: clean re