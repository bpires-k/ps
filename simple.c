#include "push_swap.h"

int	find_position(t_stack *stack, int value)
{
	t_stack *current;
	int		position;

	current = stack;
	position = 1;
	while (current)
	{
		if (current->value == value)
			return (position);
		++position;
		current = current->next;
	}
	return (0);
}

void	findmin_sort(t_bench *bm, t_stack **a, t_stack **b, int size)
{
	int	current_size;
	int	position;
	int	min;

	current_size = size;
	while (current_size > 1)
	{
		min = ft_lstmin(*a)->value;
		position = find_position(*a, min);
		if (position == 0)
			return ;
		else if (position < current_size / 2)
			while ((*a)->value != min)
				ra(bm, a, b);
		else
			while ((*a)->value != min)
				rra(bm, a, b);
		pb(bm, a, b);
		--current_size;
	}
	while (*b)
		pa(bm, a, b);
}
