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
void start_struct(p_swap *a, p_swap *b)
{
	a->id = 'A';
	b->id = 'B';
	a->stack = ft_calloc(sizeof(int), a->len);
	b->stack = ft_calloc(sizeof(int), a->len);
}

int	main(int argc, char **argv)
{
	p_swap	*a;
	p_swap	*b;

	if (ft_argcontrol(argc, argv))
	{
		a = ft_calloc(sizeof(p_swap),1);
		b = ft_calloc(sizeof(p_swap),1);
		a->len = ft_getlen(argv);
		start_struct(a,b);
		ft_getarg(argv, a);
		ft_printstack(a);
		ft_printstack(b);
		pb(a,b);
		ft_printstack(a);
		ft_printstack(b);
		ft_printf(RED"Pb done"RST);
		rotate(a);
		ft_printstack(a);
	}
	else
		ft_error("Invalid Input.");
	return (0);
}