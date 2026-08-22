#include "push_swap.h"

void	select_sort(t_bench *bm, t_stack **a, t_stack **b, int size)
{
	int	position;
	int	max;
	int	current_size;

	current_size = size;
	while (*b)
	{
		max = ft_lstmax(*b)->value;
		position = find_position(*b, max);
		if (position == 0)
			return ;
		else if (position < current_size / 2)
			while ((*b)->value != max)
				rb(bm, a, b);
		else
			while ((*b)->value != max)
				rra(bm, a, b);
		pa(bm, a, b);
	}

	
}
void	b_to_b(t_bench *bm, t_stack **a, t_stack **b, int size)
{
	int	range;
	int	bucket;
	int	i;

	range = ft_sqrt(size);
	bucket = range;
	i = 1;
	while (i < size)
	{
		if ((*a)->index < bucket - range + 1)
		{
			pb(bm, a, b);
			rb(bm, a, b);
			i++;
		}
		else if ((*a)->index > bucket)
		{
			pb(bm, a, b);
			i++;
		}
		else
			ra(bm, a, b);
		if (i == bucket)
			bucket += range;
	}
}

void	bucket_sort(t_bench *bm, t_stack **a, t_stack **b, int size)
{
	if (size < 2)
		return ;
	b_to_b(bm, a, b, size);
	select_sort(bm, a, b, size);
}
