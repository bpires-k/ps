#include "push_swap.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->value = value;
		new->prev = 0;
		new->next = 0;
	}
	return (new);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return;
	if (*stack)
	{
		new->prev = (*stack)->prev;
		(*stack)->prev->next = new;
		(*stack)->prev = new;
	}
	else
	{
		new->prev = new;
		*stack = new;
	}
}

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
return ;
	if (*stack)
	{
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
	}
	else
		new->prev = new;
	new->next = *stack;
	*stack = new;
}

void	ft_lstclear(t_stack **stack)
{
	t_stack *to_clean;
	t_stack *current;

	if (!stack || !*stack)
		return;
	current = *stack;
	while (current)
	{
		to_clean = current;
		current = current->next;
		free(to_clean);
	}
	*stack = 0;
}

int	add_value(t_stack **a, int value)
{
	t_stack *current;
	t_stack	*new;

	if(!a)
		return (0);
	current = *a;
	while (current)
	{
		if (current->value == value)
			return (0);
		current = current->next;
	}
	new = ft_lstnew(value);
	if (!new)
		return (0);
	ft_lstadd_back(a, new);
	return (1);
}
