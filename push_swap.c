#include "push.h"

void	ft_error(char *str)
{
	ft_printf("%s",str);
	exit(1);
}

int	ft_getlen(char **argv)
{
	int	i;

	i = 0;
	while(*(++argv))
		i++;
	return (i);
}

void	ft_getarg(char **argv, p_swap *a)
{
	int	i;

	a->stack = ft_calloc(a->len, 1);
	i = 0;
	while (argv[++i])
	{
		a->stack[i - 1] = ft_atoi(argv[i]);
	}
}

void	ft_printstack(p_swap *s)
{
	int	i;

	i = 0;
	while (i < s->len)
	{
		ft_printf("%d\n",s->stack[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	p_swap	*a;
	p_swap	*b;

	a = ft_calloc(sizeof(p_swap), 1);
	b = ft_calloc(sizeof(p_swap), 1);
	if (argc > 1)
	{
		a->len = ft_getlen(argv);
		ft_getarg(argv, a);
		ft_printstack(a);
	}
	else
		ft_error("Invalid Input.");
	return (0);
}