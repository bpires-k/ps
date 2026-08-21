#include "push_swap.h"

int	set_value(t_stack **a, char *av)
{
	
}
int	set_flag(t_bench *benchmark, char *av)
{
	if (ft_strcmp(av, "bench") == 0)
		benchmark->display = 1;
	else if (ft_strcmp(av, "simple") == 0)
		benchmark->strategy = "simple";
	else if (ft_strcmp(av, "medium") == 0)
		benchmark->strategy = "medium";
	else if (ft_strcmp(av, "complex"))
		benchmark->strategy = "complex";
	else if (ft_strcmp(av, "adaptive"))
		benchmark->strategy = "adaptive";
	else
		return (0);
	return (1);
}

int	set_input(t_bench *benchmark, t_stack **a, char *av)
{
	if (av[0] == '-' && av[1] == '-')
	{
		if (set_flag(benchmark, av + 2))
			return (0);
	}
	else
		if (set_value (a, av))
			return (1);
	return (-1);
}

int	set_inputs(t_bench *benchmark, t_stack **a, char **av)
{
	int	input_status;
	int	arg_status;
	int	arg_len;

	if (!**av)
		return (2);
	arg_status = 0;
	arg_len = 0;
	while ((*av)[arg_len] && (*av)[arg_len] != ' ')
		++arg_len;
	if (arg_len == 0)
		arg_status += 2;
	(*av)[arg_len] = 0;
	input_status = set_input(benchmark, a, (*av));
	if (input_status == -1)
		return (-1);
	arg_status += input_status + 1;
	return (ar_status);
}
int	input_checker(t_bench *benchmark, t_stack **a, int ac, char **av)
{
	int	arg_status;
	int	num_count;
	int	i;

	num_count = 0;
	i = -1;
	while (++i < ac)
	{
		arg_status = 0;
		while (*av[i] == ' ')
			++av[i];
		if (*av[i] == 0)
			return (-1);
		while (arg_status < 2)
		{
			while (*av[i] == ' ')
				++av[i];
			arg_status = set_inputs(benchmark, a, &av[i]);
			if (arg_status == -1)
				return (-1);
			if (arg_status % 2 == 1)
				++num_count;
		}
	}
	return (num_count);
}
