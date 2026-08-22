#include "push_swap.h"

t_stack	*ft_lstmin(t_stack *stack)
{
	int		min;
	t_stack *current;
	t_stack *min_node;

	current = *stack;
	min = INT_MAX;
	while (current)
	{
		if ((current)->value < min)
			min_node = current->value;
		current = current->next;
	}
	return (min_node);
}

t_stack *ft_lstmax(t_stack *stack)
{
	t_stack *max_node;
	t_stack *current;
	int		max;

	current = *stack;
	max = INT_MIN;
	while (current)
	{
		if ((current)->value > max)
			max_node = current->value;
		current = current->next;
	}
	return (max_node);
}
