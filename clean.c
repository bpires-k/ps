#include "push_swap.h"

int	free_all(t_bench *bm, t_stack **a, t_stack **b)
{
	if (bm)
		free(bm);
	if (a)
		ft_lstclear(a);
	if (b)
		ft_lstclear(b);
	return (0);
}

int error(t_bench *bm, t_stack **a, t_stack **b)
{
	free_all(bm, a, b);
	write(2, "Error\n", 6);
	return (1);
}
