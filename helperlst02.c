#include "push_swap.h"

t_stack	*ft_lstmin(t_stack *stack)
{	
	t_stack *current;
	t_stack *min_node;

	min_node = stack;
	current = min_node->next;
	while (current)
	{
		if ((current)->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_stack *ft_lstmax(t_stack *stack)
{
	t_stack *max_node;
	t_stack *current;

	max_node = stack;
	current = max_node->next;
	while (current)
	{
		if ((current)->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}

t_stack	*ft_lsttail(t_stack *stack)
{
	t_stack	*tail;

	tail = stack;
	while (tail->next)
		tail = tail->next;
	return (tail);
}

void	init_index(t_stack **stack)
{
	int		i;
	t_stack	*current;
	t_stack	*tester;

	current = *stack;
	while (current)
	{
		i = 1;
		tester = current->next;
		while (tester)
		{
			if (current->value > tester->value)
				++i;
			tester = tester->next;
		}
		current->index = i;
		current = current->next;
	}
}