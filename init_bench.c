#include "push_swap.h"

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
