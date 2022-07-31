/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:34:43 by egun              #+#    #+#             */
/*   Updated: 2022/07/31 16:16:18 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_error(char *msg)
{
	ft_printf(RED"%s\n"RST, msg);
	ft_printf("error\n");
	exit(0);
}

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

void	start_struct(t_swap *a, t_swap *b, t_swap *c, char **av, int argc)
{
	char	**argv = ft_calloc(9999, 1);

	argv = av;
	if (argc == 2)
		argv = ft_split(av[1], ' ');
	a->len = ft_getlen(argv);
	c->len = a->len;
	a->id = 'a';
	b->id = 'b';
	c->id = 'c';
	a->stack = ft_calloc(sizeof(int), a->len);
	b->stack = ft_calloc(sizeof(int), a->len);
	c->stack = ft_calloc(sizeof(int), a->len);
	ft_printf(BMAG"%d\n"RST, a->len);
	ft_getarg(argv, a, c);
	if (!sort_check(a->stack, a->len))
	{
		destroy(a, b, c);
		ft_printf("Errorr\n");
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
		//TODO: get_len broken fix
		a = ft_calloc(sizeof(t_swap), 1);
		b = ft_calloc(sizeof(t_swap), 1);
		c = ft_calloc(sizeof(t_swap), 1);
		start_struct(a, b, c, argv, argc);
		selectin_sort(c->stack, c->len, 0);
		to_index(a, c);
		if (a->len < 6)
			little_sort(a, b);
		else
			radix_sort(a, b);
		destroy(a, b, c);
	}
	else
		ft_printf("Erroadsr\n");
	return (0);
	exit(0);
}
