/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:38:01 by egun              #+#    #+#             */
/*   Updated: 2022/07/31 19:01:55 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	destroy(t_swap *a, t_swap *b, t_swap *c)
{
	free(a->stack);
	free(b->stack);
	free(c->stack);
	free(a);
	free(b);
	free(c);
}

int	ft_argcontrol(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == ' ')
				continue ;
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
		}
	}
	return (1);
}

void	ft_getarg(char **argv, t_swap *a, t_swap *c)
{
	int	i;
	int	len;

	len = a->len;
	i = 0;
	ft_printf(BBLU"Nooo -- %d --  %i\n"RST, a->len, i);
	while (i <= a->len)
		a->stack[i++] = ft_atoi(argv[len--]);
	ft_printf(BLK"Yesss\n"RST);
	i = -1;
	len = a->len;
	while (argv[++i] && argv[len])
		c->stack[i] = ft_atoi(argv[len--]);
	a->len++;
	ft_printstack(a);
	selectin_sort(c->stack, c->len, 0);
}

void	get_str_arg(char **argv, t_swap *a, t_swap *c)
{
	char	**str;
	int		i;
	int		j;

	j = 0;
	i = -1;
	str = ft_split(argv[1], ' ');
	while (str[j])
		j++;
	a->len = j + 1;
	c->len = a->len;
	while (str[++i])
	{
		a->stack[i] = ft_atoi(str[j]);
		j--;
	}
}

int	sort_check(int *stack, int len)
{
	int	i;
	int	x;

	i = 0;
	while (++i < len)
	{
		x = i;
		while(++x < len)
			if (stack[i] == stack[x])
				return (0);
	}
	i = 0;
	while (i < len)
	{
		if (stack[i] > 2147483647)
			return (0);
		if(stack[i] > stack[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}
