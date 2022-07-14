/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:53:50 by egun              #+#    #+#             */
/*   Updated: 2022/07/14 20:08:06 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_sorted_rdx(p_swap *index)
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

int	get_max_bits(p_swap *index)
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

// void	radix_sub_one(p_swap *a, p_swap *b, int i)
// {
// 	if (check_sorted_rdx(a) == 0 && a->len > 0)
// 	{
// 		if (((a->stack[a->len - 1] >> i) & 1) == 0)
// 			push(a, b);
// 		else
// 			rotate(a, 1);
// 	}
// }


void	radix_sort(p_swap *a, p_swap *b)
{
	int		i;
	int		j;
	int		max_bits;

	i = 0;
	max_bits = get_max_bits(a);
	//ft_printstack(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < a->len)
		{
			if ((a->stack[a->len - 1]) >> i == 0)
				rotate(a,1);
			else
				push(a,b);
		}
		while (b->len)
			push(b,a);
		i++;
	}
}