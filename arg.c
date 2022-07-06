#include "push.h"

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
		if (!ft_isdigit(argv[i][j]))
			return (0);
	}
	return (1);
}

void	ft_getarg(char **argv, p_swap *a)
{
	int	i;
	int	len;

	len = a->len;
	i = 0;
	while (argv[++i])
		a->stack[i - 1] = ft_atoi(argv[len--]);
}