/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:01:18 by egun              #+#    #+#             */
/*   Updated: 2022/07/13 20:13:04 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swapIndex(int	*arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int		minIndex(int *arr, int i, int j)
{
	int	x;

	if (i == j)
		return (i);
	x = minIndex(arr, i + 1, j);
	if(arr[i] > arr[x])
		return (i);
	return (x);
}

void	selectinSort(int *stack, int size, int index)
{
	int	min;

	if (size == index)
		return ;
	min = minIndex(stack, index, size - 1);
	if(min != index)
		swapIndex(stack, index, min);
	selectinSort(stack, size, index + 1);
}