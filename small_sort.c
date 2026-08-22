#include "push_swap.h"

void	sort_2(t_bench *bm, t_stack **a, t_stack **b)
{
	if ((*a)->value > (*a)->next->value)
		sa(bm, a, b);
}

void sort_3(t_bench *bm, t_stack **a, t_stack **b)
{
    t_stack	*max;

	if (!a || !*a || !(*a)->next)
		return ;
	max = ft_lstmax(*a);
	if (*a == max)
		ra(bm, a, b);
	else if ((*a)->next == max)
		rra(bm, a, b);
	if ((*a)->value > (*a)->next->value)
		sa(bm, a, b);
}

void	sort_mt3(t_bench *bm, t_stack **a, t_stack **b, int size)
{
	int	current_size;

	current_size = size;
	while (current_size > 3)
	{
		while (*a && (*a)->value != ft_lstmin(*a)->value)
			ra(bm, a, b);
		pb(bm, a,b);
		--current_size;
	}
	sort_3(bm, a, b);
	while (*b)
		pa(bm, a, b);
}

void	small_sort(t_bench *bm, t_stack **a, t_stack **b, int size)
{
	if (!a || !*a || is_sorted(a, b))
		return ;
	if (size == 2)
		sort_2(bm, a, b);
	else if (size == 3)
		sort_3(bm, a, b);
	else if (size > 3)
		sort_mt3(bm, a, b, size);
}
