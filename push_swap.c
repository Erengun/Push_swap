#include "push.h"

int	ft_getlen(char **argv)
{
	int	i;

	i = 0;
	while(*(++argv))
		i++;
	return (i);
}

void	ft_error(char *str)
{
	ft_printf("%s",str);
	exit(1);
}

void	ft_printstack(p_swap *x)
{
	int	i;

	i = -1;
	ft_printf("--------------%c Stack-----------\n", x->id);
	while (++i < x->len)
		ft_printf("%c[%d]: %d\n", x->id, i, x->stack[i]);
}

void start_struct(p_swap *a, p_swap *b, p_swap *c)
{
	a->id = 'A';
	b->id = 'B';
	c->id = 'C';
	a->stack = ft_calloc(sizeof(int), a->len);
	b->stack = ft_calloc(sizeof(int), a->len);
	c->stack = ft_calloc(sizeof(int), a->len);
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
		a->len = ft_getlen(argv);
		c->len = a->len;
		start_struct(a,b,c);
		ft_getarg(argv, a, c);
		ft_printstack(a);
		selectinSort(c->stack, c->len, 0);
		toIndex(a,c);
	}
	else
		ft_error("Invalid Input.");
	return (0);
}