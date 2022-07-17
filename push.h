/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:00:10 by egun              #+#    #+#             */
/*   Updated: 2022/07/17 20:43:47 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

//! SİL
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct s_swap
{
	int		*stack;
	int		len;
	char	id;
}t_swap;

void	ft_printstack(t_swap *s);
void	push(t_swap *a, t_swap *b);
void	ft_stacklen(t_swap *x);
void	ft_getarg(char **argv, t_swap *a, t_swap *c);
int		ft_argcontrol(int argc, char **argv);
void	ss(t_swap *a, t_swap *b);
void	rotate(t_swap *x, int flag);
void	r_rotate(t_swap *x, int flag);
void	rrr(t_swap *a, t_swap *b);
void	rr(t_swap *a, t_swap *b, int flag);
void	selectin_sort(int *stack, int size, int index);
void	to_index(t_swap *a, t_swap *c);
void	radix_sort(t_swap *a, t_swap *b);
int		sort_check(int *stack);
void	destroy(t_swap *a, t_swap *b, t_swap *c);
void	ft_error(char *msg);

#endif