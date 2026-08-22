#include "push_swap.h"

void	ss(t_bench *bm, t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	++bm->moves[8];
	write(1, "ss\n", 3);
}

void	rr(t_bench *bm, t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	++bm->moves[9];
	write(1, "rr\n", 3);
}

void	rrr(t_bench *bm, t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	++bm->moves[10];
	write(1, "rrr\n", 4);
}
