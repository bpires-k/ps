#include "push_swap.h"

void	ss(t_bench *bm, t_stack **a, t_stack **b)
{
	s(a);
	s(b);
	++bm->moves[9];
	write(1, "ss\n", 3);
}

void	rr(t_bench *bm, t_stack **a, t_stack **b)
{
	r(a);
	r(b);
	++bm->moves[10];
	write(1, "rr\n", 3);
}

void	rrr(t_bench *bm, t_stack **a, t_stack **b)
{
	rr(a);
	rr(b);
	++bm->moves[11];
	write(1, "rrr\n", 4);
}
