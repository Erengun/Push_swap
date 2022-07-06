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

// void	pb(p_swap *a, p_swap *b)
// {
// 	int	temp;
// 	int	i;

// 	i = b->len;
// 	temp = a->stack[0];
// 	while(i > 0)
// 	{
// 		b->stack[i] = b->stack[i - 1];
// 		i--;
// 	}
// 	b->stack[0] = temp;
// 	i = 0;
// 	while (i < a->len - 1)
// 	{
// 		a->stack[i] = a->stack[i + 1];
// 		i++;
// 	}
// 	a->len--;
// 	b->len++;
// }

void	pb(p_swap *a, p_swap *b)
{
	a->len--;
	b->len++;
	if(a->len > 0)
		b->stack[b->len] = a->stack[a->len];
	ft_printf("%d\n", a->len);

}