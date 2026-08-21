#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_bench	*benchmark;
	t_stack	*a;
	t_stack	*b;
	int		num_count;

	benchmark = init_bench();
	if (!benchmark)
		return (1);
	a = 0;
	b = 0;
	num_count = check_inputs(benchmark, &a, argc - 1, &argv[1]);
	if (num_count == -1)
		return (do_error(benchmark, &a, &b);
	if (num_count == 0)
		return (free_all(benchmark, &a, &b);
	benchmark->disorder = compute_disorder(a);
	sort_stack(benchmark, &a, &b, num_count);
	if (benchmark->display)
		print_bench(benchmark);
	return(free_all(benchmark, &a, &b);
}
