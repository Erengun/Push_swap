/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:38:01 by egun              #+#    #+#             */
/*   Updated: 2022/07/17 20:53:51 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_error(char *msg)
{
	ft_printf(RED"%s\n"RST, msg);
	ft_printf("error\n");
	exit(0);
}

void	destroy(t_swap *a, t_swap *b, t_swap *c)
{
	free(a->stack);
	free(b->stack);
	free(c->stack);
	free(a);
	free(b);
	free(c);
	exit(0);
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
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
	}
	return (1);
}

void	ft_getarg(char **argv, t_swap *a, t_swap *c)
{
	int	i;
	int	len;

	len = a->len;
	i = 0;
	while (argv[++i])
		a->stack[i - 1] = ft_atoi(argv[len--]);
	i = 0;
	len = a->len;
	while (argv[++i])
		c->stack[i - 1] = ft_atoi(argv[len--]);
	selectin_sort(c->stack, c->len, 0);
}

int	sort_check(int *stack)
{
	int	i;

	i = 0;
	while (stack[++i + 1])
	{
		if (stack[i] > stack[i + 1])
			return(1);
			//return (0);
		else
			continue ;
	}
	return (1);
}
