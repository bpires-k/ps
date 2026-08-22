#include "push_swap.h"

double compute_disorder(t_stack *stack)
{
	double	total_pairs;
	double	mistakes;
	t_stack	*current;
	t_stack	*test;

	total_pairs = 0;
	mistakes = 0;
	current = stack;
	while (current)
	{
		test = current->next;
		while (test)
		{
			++total_pairs;
			if (current->value > test->value)
				++mistakes;
			test = test->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

void	sort_stack(t_bench *bm, t_stack **a, t_stack **b, int size)
{
	if (ft_strcmp(bm->strategy, "simple") == 0
		|| (ft_strcmp(bm->strategy, "adaptive") == 0 && bm->disorder < 0.2))
	{
		bm->big_o = "n2";
		if (bm->disorder && size > 5)
			findmin_sort(bm, a, b, size);
		small_sort(bm, a, b, size);
	}
	else if (ft_strcmp(bm->strategy, "medium") == 0
		|| (ft_strcmp(bm->strategy, "adaptive") == 0 && bm->disorder < 0.5))
	{
		bm->big_o = "nVn";
		if (bm->disorder && size > 5)
			bucket_sort(bm, a, b, size);
		small_sort(bm, a, b, size);
	}
	else
	{
		bm->big_o = "nlogn";
		if (bm->disorder && size > 5)
			LSD_sort(bm, a, b, size);
		small_sort(bm, a, b,size);
	}
}

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
	num_count = input_checker(benchmark, &a, argc - 1, &argv[1]);
	if (num_count == -1)
		return (error(benchmark, &a, &b));
	if (num_count == 0)
		return (free_all(benchmark, &a, &b));
	init_index(&a);
	benchmark->disorder = compute_disorder(a);
	sort_stack(benchmark, &a, &b, num_count);
	if (benchmark->display)
		print_bench(benchmark);
	return(free_all(benchmark, &a, &b));
}
