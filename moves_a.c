#include "push_swap.h"

void	sa(t_bench *bm, t_stack **a, t_stack **b)
{
	(void)b;
	swap(a);
	++bm->moves[0];
	write(1, "sa\n", 3);
}

void	ra(t_bench *bm, t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
	++bm->moves[1];
	write(1, "ra\n", 3);
}

void	rra(t_bench *bm, t_stack **a, t_stack **b)
{
	(void)b;
	r_rotate(a);
	++bm->moves[2];
	write(1, "rra\n", 4);
}

void	pa(t_bench *bm, t_stack **a, t_stack **b)
{
	push(b, a);
	++bm->moves[3];
	write(1, "pa\n", 3);
}
