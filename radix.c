/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:53:50 by egun              #+#    #+#             */
/*   Updated: 2022/08/04 18:51:54 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	radix_sort_check(t_swap *index)
{
	int	i;

	i = 0;
	while (i < index->len - 1)
	{
		if (index->stack[i] > index->stack[i + 1])
			++i;
		else
			return (0);
	}
	return (1);
}

void	radix_b(t_swap *a, t_swap *b, int i, int max)
{
	int	b_len;

	b_len = b->len;
	while (b_len-- && radix_sort_check(b) && i < max)
	{
		if (((b->stack[b_len - 1] >> i) & 1) == 0)
			rotate(b, 1);
		else
			push(b, a);
	}
}

void	radix_a(t_swap *a, t_swap *b, int i)
{
	if (radix_sort_check(a) == 0)
	{
		if (((a->stack[a->len - 1] >> i) & 1) == 0)
			push(a, b);
		else
			rotate(a, 1);
	}
}

int	get_max_bits(t_swap *index)
{
	int	bit_size;
	int	size;

	bit_size = 0;
	size = index->len;
	while (size > 1)
	{
		bit_size++;
		size /= 2;
	}
	return (bit_size);
}

void	radix_sort(t_swap *a, t_swap *b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	max_bits = get_max_bits(a);
	while (i <= max_bits)
	{
		j = 0;
		size = a->len;
		while (j < size)
		{
			radix_a(a, b, i);
			j++;
		}
		i++;
		radix_b(a, b, i, max_bits);
		while (b->len)
			push(b, a);
	}
}
