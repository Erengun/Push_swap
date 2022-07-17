#include "push.h"

void	ft_error(char *msg)
{
	ft_printf(RED"%s\n"RST, msg);
	ft_printf("error\n");
	exit(0);
}

void	destroy(p_swap *a, p_swap *b, p_swap *c)
{
	free(a->stack);
	free(b->stack);
	free(c->stack);
	exit(0);
}

int	ft_argcontrol(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
			return (0);
	}
	return (1);
}

void	ft_getarg(char **argv, p_swap *a, p_swap *c)
{
	int	i;
	int	len;

	len = a->len;
	i = 0;
	while (argv[++i])
		a->stack[i - 1] = ft_atoi(argv[len--]);
	i = 0;
	len = a->len;
	while (argv[++i])
		c->stack[i - 1] = ft_atoi(argv[len--]);
	selectinSort(c->stack, c->len, 0);
}

int	sortCheck(int *stack)
{
	int i;

	i = 0;
	while (stack[++i + 1])
	{
		if (stack[i] < stack[i+1])
			ft_error("Argument already sorted lol");
	}
	return(1);
}		