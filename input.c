#include "push_swap.h"

int	set_value(t_stack **a, char *arg)
{
	long long	value;

	value = ft_atoi(arg);
	if (value >= (long long)INT_MIN && value <= (long long)INT_MAX)
		return (add_value(a, value));
	return (0);
}

int	set_flag(t_bench *benchmark, char *arg)
{
	if (ft_strcmp(arg, "bench") == 0)
		benchmark->display = 1;
	else if (ft_strcmp(arg, "simple") == 0)
		benchmark->strategy = "Simple";
	else if (ft_strcmp(arg, "medium") == 0)
		benchmark->strategy = "Medium";
	else if (ft_strcmp(arg, "complex") == 0)
		benchmark->strategy = "Complex";
	else if (ft_strcmp(arg, "adaptive") == 0)
		benchmark->strategy = "Adaptive";
	else
		return (0);
	return (1);
}

int	set_input(t_bench *benchmark, t_stack **a, char *arg)
{
	if (arg[0] == '-' && arg[1] == '-')
	{
		if (set_flag(benchmark, arg + 2))
			return (0);
	}
	else
		if (set_value(a, arg))
			return (1);
	return (-1);
}

int	set_inputs(t_bench *benchmark, t_stack **a, char **arg)
{
	int	input_status;
	int	arg_status;
	int	arg_len;

	if (!**arg)
		return (2);
	arg_status = 0;
	arg_len = 0;
	while ((*arg)[arg_len] && (*arg)[arg_len] != ' ')
		++arg_len;
	if ((*arg)[arg_len] == 0)
		arg_status += 2;
	(*arg)[arg_len] = 0;
	input_status = set_input(benchmark, a, (*arg));
	if (input_status == -1)
		return (-1);
	arg_status += input_status;
	(*arg) += arg_len + 1;
	return (arg_status);
}

int	check_inputs(t_bench *bm, t_stack **a, int ac, char **av)
{
	int	arg_status;
	int	num_count;
	int	index;

	num_count = 0;
	index = -1;
	while (++index < ac)
	{
		arg_status = 0;
		while (*av[index] == ' ')
			++av[index];
		if (*av[index] == 0)
			return (-1);
		while (arg_status < 2)
		{
			while (*av[index] == ' ')
				++av[index];
			arg_status = set_inputs(bm, a, &av[index]);
			if (arg_status == -1)
				return (-1);
			if (arg_status % 2 == 1)
				++num_count;
		}
	}
	return (num_count);
}
