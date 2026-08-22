#include "push_swap.h"

void	index_to_binary(t_stack *stack)
{
	t_stack *current;
	int		original;
	int		bin;
	int		exp;

	current = stack;
	while (current)
	{
		original = current->index;
		exp = 1;
		bin = 0;
		while (original > 0)
		{
			bin = bin + ((original / exp) % 2) * exp;
			exp *= 10;
			original %= exp;
		}
		current->index = bin;
	}
}

void	LSD_sort(t_bench *bm, t_stack **a, t_stack **b, int size)
{
	(void)size;
	int	rotations;
	int	max;
	
	index_to_binary(*a);
	max = ft_lstmax(*a)->index;
	rotations = 1;
	while (max / rotations > 0)
	{
		while (*a)
		{
			if (((*a)->index / rotations) % 10 == 0)
			{
				pb(bm, a, b);
				rb(bm, a, b);
			}
			else
				pb(bm, a, b);
		}
		while (*b)
			pa(bm, a, b);
		rotations *= 10;
	}
}
