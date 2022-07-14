/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:10:58 by egun              #+#    #+#             */
/*   Updated: 2022/07/13 20:45:31 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	findIndex(int *arr, int x, int size)
{
	int i;

	i = 0;
	while (i < size -1 && arr[i] != x)
		i++;
	return (i);
}
void	toIndex(p_swap *a, p_swap *c)
{
	int i;
	int j;

	i = 0;
	while (i < a->len)
	{
		j = findIndex(c->stack, a->stack[i], a->len);
		a->stack[i] = j;
		i++;
	}
}