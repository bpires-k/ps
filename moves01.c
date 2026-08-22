#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (!stack || !*stack ||  !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next = (*stack)->prev;
	if ((*stack)->next->prev != *stack)
		(*stack)->prev = (*stack)->next->prev;
	(*stack)->next->prev = *stack;
	if ((*stack)->next->next)
		(*stack)->next->next->prev = (*stack)->next;
}

void	rotate(t_stack **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->prev->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev->next = 0;
}

void	r_rotate(t_stack **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->prev->next = (*stack);
	*stack = (*stack)->prev;
	(*stack)->prev->next = 0;
}

void push(t_stack **stack1, t_stack **stack2)
{
	t_stack *new;

	if (!stack1 || !stack2 || !*stack1)
		return;
	new = *stack1;
	if (!(*stack1)->next)
		*stack1 = 0;
	else
	{
		(*stack1)->next->prev = (*stack1)->prev;
		*stack1 = (*stack1)->next;
	}
	ft_lstadd_front(stack2, new);
}
