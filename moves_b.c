#include "push_swap.h"

void	sb(t_bench *bm, t_stack **a, t_stack **b)
{
	(void)a;
	swap(b);
	++bm->moves[4];
	write(1, "sb\n", 3);
}

void	rb(t_bench *bm, t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
	++bm->moves[5];
	write(1, "rb\n", 3);
}

void	rrb(t_bench *bm, t_stack **a, t_stack **b)
{
	(void)a;
	r_rotate(b);
	++bm->moves[6];
	write(1, "rrb\n", 4);
}

void	pb(t_bench *bm, t_stack **a, t_stack **b)
{
	push(a, b);
	++bm->moves[7];
	write(1, "pb\n", 3);
}
