#include "push.h"

void	swap(p_swap *x, int flag)
{
	int	temp;

	if (x->stack[0] && x->stack[1])
	{
		temp = x->stack[0];
		x->stack[0] = x->stack[1];
		x->stack[1] = temp;
	}
	if (flag)
		ft_printf("s%c\n",x->id);
}

void	push(p_swap *a, p_swap *b)
{
	if(a->len > 0)
	{
		b->len++;
		b->stack[b->len - 1] = a->stack[a->len - 1];
		a->len--;
		ft_printf("p%c\n",b->id);
	}
}

void	ss(p_swap *a, p_swap *b)
{
	swap(a, 0);
	swap(b, 0);
}

void	rotate(p_swap *x, int flag)
{
	int	temp;

	temp = x->stack[x->len - 1];
	ft_memmove(&x->stack[1], &x->stack[0], (x->len - 1) * 4);
	x->stack[0] = temp;
	if (flag)
		ft_printf("r%c\n", x->id);
}

void	r_rotate(p_swap *x, int flag)
{
	int	temp;

	temp = x->stack[x->len-1];
	ft_memmove(&x->stack[0], &x->stack[1], x->len * 4);
	x->stack[0] = temp;
	if (flag)
		ft_printf("rr%c\n", x->id);
}

void	rr(p_swap *a, p_swap *b, int flag)
{
	rotate(a, 0);
	rotate(b, 0);
	if (flag)
		ft_printf("rr\n");
}

void	rrr(p_swap *a, p_swap *b)
{
	r_rotate(a, 0);
	r_rotate(b, 0);
	ft_printf("rrr");
}
