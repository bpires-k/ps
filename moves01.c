#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*second;

	if (!stack || !*stack ||  !(*stack)->next)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	(*stack)->prev = second;
	second->prev = 0;
	second->next = *stack;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack);
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tail = ft_lsttail(*stack);
	(*stack)->prev = tail;
	(*stack)->next->prev = 0;
	tail = *stack;
	*stack = (*stack)->next;
	tail->next = 0;
}

void	r_rotate(t_stack **stack)
{
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tail = ft_lsttail(*stack);
	tail->next = *stack;
	tail->prev->next = 0;
	tail->prev = 0;
	(*stack)->prev = tail;
	*stack = tail;
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
		(*stack1)->next->prev = 0;
		*stack1 = (*stack1)->next;
	}
	ft_lstadd_front(stack2, new);
}
