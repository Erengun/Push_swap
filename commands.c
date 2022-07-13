#include "push.h"

void	swap(p_swap *x)
{
	int	temp;

	if (x->stack[0] && x->stack[1])
	{
		temp = x->stack[0];
		x->stack[0] = x->stack[1];
		x->stack[1] = temp;
	}
}

void	push(p_swap *a, p_swap *b)
{
	a->len--;
	b->len++;
	if(a->len > 0)
		b->stack[b->len] = a->stack[a->len];
}

void	ss(p_swap *a, p_swap *b)
{
	swap(a);
	swap(b);
}

void	rotate(p_swap *x)
{
	int	temp;

	temp = x->stack[0];
	ft_memmove(&x->stack[0], &x->stack[1], x->len * 4);
	x->stack[x->len - 1] = temp;
}

void	r_rotate(p_swap *x)
{
	int	temp;

	temp = x->stack[x->len-1];
	ft_memmove(&x->stack[1], &x->stack[0], x->len * 4);
	x->stack[0] = temp;
}

void	rr(p_swap *a, p_swap *b)
{
	rotate(a);
	rotate(b);
}

void	rrr(p_swap *a, p_swap *b)
{
	r_rotate(a);
	r_rotate(b);
}
