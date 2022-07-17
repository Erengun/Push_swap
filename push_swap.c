#include "push.h"

int	ft_getlen(char **argv)
{
	int	i;

	i = 0;
	while(*(++argv))
		i++;
	return (i);
}

void	ft_printstack(p_swap *x)
{
	int	i;

	i = x->len;
	ft_printf("--------------%c Stack-----------\n", x->id);
	while (--i >= 0)
		ft_printf("%c[%d]: %d\n", x->id, i, x->stack[i]);
}

void start_struct(p_swap *a, p_swap *b, p_swap *c, char **argv)
{
	a->len = ft_getlen(argv);
	c->len = a->len;
	a->id = 'a';
	b->id = 'b';
	c->id = 'c';
	a->stack = ft_calloc(sizeof(int), a->len);
	b->stack = ft_calloc(sizeof(int), a->len);
	c->stack = ft_calloc(sizeof(int), a->len);
	ft_getarg(argv, a, c);
}

int	main(int argc, char **argv)
{
	p_swap	*a;
	p_swap	*b;
	p_swap	*c;

	if (ft_argcontrol(argc, argv))
	{
		a = ft_calloc(sizeof(p_swap),1);
		b = ft_calloc(sizeof(p_swap),1);
		c = ft_calloc(sizeof(p_swap),1);
		start_struct(a,b,c, argv);
		//ft_printstack(a);
		selectinSort(c->stack, c->len, 0);
		toIndex(a,c);
		//ft_printstack(c);
		//ft_printstack(a);
		radix_sort(a, b);
		destroy(a,b,c);
	}
	else
		ft_error("Invalid Input.");
	return (0);
}