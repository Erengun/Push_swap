#include "push.h"

void	ft_error(char *str)
{
	ft_printf("%s",str);
	exit(1);
}

void	ft_printstack(p_swap *s)
{
	int	i;

	i = -1;

	while (++i < s->len)
		ft_printf("[%d]: %d\n",i,s->stack[i]);
}

int	main(int argc, char **argv)
{
	p_swap	*a;
	p_swap	*b;

	a = ft_calloc(sizeof(p_swap), 1);
	b = ft_calloc(sizeof(p_swap), 1);
	if (ft_argcontrol(argc, argv))
	{
		a->len = ft_getlen(argv);
		a->stack = ft_calloc(a->len, 1);
		b->stack = ft_calloc(a->len, 1);
		ft_stacklen(b);
		ft_printf("%d\n", b->len);
		ft_getarg(argv, a);
		ft_printstack(a);
		ft_printf(" b :  Rez \n");
		ft_printstack(b);
		ft_printf("\n Rez \n");		
		push(b,a);
		ft_stacklen(b);
		ft_stacklen(a);
		ft_printstack(a);
		ft_printf("\n b :  Rez \n");	
		ft_printstack(b);
	}
	else
		ft_error("Invalid Input.");
	return (0);
}