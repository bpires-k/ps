#include "push_swap.h"

int	sum_moves(t_bench *bm)
{
	int	total_moves;
	int	i;

	total_moves = 0;
	i = 0;
	while (i < 11)
	{
		total_moves += bm->moves[i];
		++i;
	}
	return (total_moves);
}

t_bench	*init_bench(void)
{
	t_bench	*benchmark;
	int		i;

	benchmark = (t_bench *) malloc(sizeof(t_bench));
	if (!benchmark)
		return (0);
	benchmark->display = 0;
	benchmark->disorder = 0;
	benchmark->strategy = "adaptive";
	benchmark->big_o = 0;
	i = 0;
	while (i < 11)
	{
		benchmark->moves[i] = 0;
		i++;
	}
	return (benchmark);
}

void	print_bench(t_bench *bm)
{
	ft_printf(2, "[bench] disorder: %f%%\n", bm->disorder * 100);
	ft_printf(2, "[bench] strategy: %s / ", bm->strategy);
	ft_printf(2, "O(%s)\n", bm->big_o);
	ft_printf(2, "[bench] total_ops: %d\n", sum_moves(bm));
	ft_printf(2, "[bench] sa: %d sb: %d ", bm->moves[0], bm->moves[4]);
	ft_printf(2, "ss: %d pa: %d ", bm->moves[8], bm->moves[3]);
	ft_printf(2, "pb: %d\n", bm->moves[7]);
	ft_printf(2, "[bench] ra: %d rb: %d ", bm->moves[1], bm->moves[5]);
	ft_printf(2, "rr: %d rra: %d ", bm->moves[9], bm->moves[2]);
	ft_printf(2, "rrb: %d rrr: %d\n", bm->moves[7], bm->moves[10]);
}
