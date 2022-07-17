/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:34:43 by egun              #+#    #+#             */
/*   Updated: 2022/07/17 20:55:05 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_getlen(char **argv)
{
	int	i;

	i = 0;
	while (*(++argv))
		i++;
	return (i);
}

void	ft_printstack(t_swap *x)
{
	int	i;

	i = x->len;
	ft_printf("--------------%c Stack-----------\n", x->id);
	while (--i >= 0)
		ft_printf("%c[%d]: %d\n", x->id, i, x->stack[i]);
}

void	start_struct(t_swap *a, t_swap *b, t_swap *c, char **argv)
{
	a->len = ft_getlen(argv);
	c->len = a->len;
	a->id = 'a';
	b->id = 'b';
	c->id = 'c';
	a->stack = ft_calloc(sizeof(int), a->len);
	b->stack = ft_calloc(sizeof(int), a->len);
	c->stack = ft_calloc(sizeof(int), a->len);
	ft_getarg(argv, a, c);
	if (!sort_check(a->stack))
	{
		ft_error("Argument already sorted lol");
		destroy(a, b, c);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_swap	*a;
	t_swap	*b;
	t_swap	*c;

	if (ft_argcontrol(argc, argv))
	{
		//TODO: radix for 1 2 3 4 5, sortcheck not working well, repeat arg check
		a = ft_calloc(sizeof(t_swap), 1);
		b = ft_calloc(sizeof(t_swap), 1);
		c = ft_calloc(sizeof(t_swap), 1);
		start_struct(a, b, c, argv);
		selectin_sort(c->stack, c->len, 0);
		to_index(a, c);
		radix_sort(a, b);
		destroy(a, b, c);
		system("leaks pushswap");
	}
	else
		ft_error("Invalid Input.");
	return (0);
}
