# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct s_swap{
	int	*stack;
	int	len;
}	p_swap;

void	ft_printstack(p_swap *s);
void push(p_swap *a, p_swap *b);
void	ft_stacklen(p_swap *x);
void	ft_getarg(char **argv, p_swap *a);
int	ft_getlen(char **argv);
int	ft_argcontrol(int argc, char **argv);