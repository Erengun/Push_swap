#include "push.h"


void	swap(p_swap *x)
{
	int	temp;

	temp = x->stack[0];
	x->stack[0] = x->stack[1];
	x->stack[1] = temp;
}

void push(p_swap *a, p_swap *b)
{
	int temp;
	int	i;

	i = a->len;
	while(i)
	{
		a->stack[i] = a->stack[i - 1];
		i--;
	}
	a->stack[0] = b->stack[0];
	ft_printf("%d to %d\n", a->stack[0], b->stack[0]);
	while(i < b->len - 1)
	{
		b->stack[i] = b->stack[i + 1];
		ft_printf("%d to %d\n", b->stack[i], b->stack[i+1]);
		i++;
	}
	b->len = ft_getlen(b->stack);
	a->len = ft_getlen(a->stack);
}