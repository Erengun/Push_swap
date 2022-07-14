# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct s_swap{
	int	*stack;
	int	len;
	char	id;
}	p_swap;

void	ft_printstack(p_swap *s);
void	push(p_swap *a, p_swap *b);
void	ft_stacklen(p_swap *x);
void	ft_getarg(char **argv, p_swap *a, p_swap *c);
int		ft_argcontrol(int argc, char **argv);
void	ss(p_swap *a, p_swap *b);
void	rotate(p_swap *x, int flag);
void	r_rotate(p_swap *x, int flag);
void	rrr(p_swap *a, p_swap *b);
void	rr(p_swap *a, p_swap *b, int flag);
void	selectinSort(int *stack, int size, int index);
void	swapIndex(int	*arr, int i, int j);
void	toIndex(p_swap *a, p_swap *c);
void	radix_sort(p_swap *a, p_swap *b);
int	sortCheck(int *stack);
void	destroy(p_swap *a, p_swap *b, p_swap *c);
void	ft_error(char *msg);
