#include "push_swap.h"

long long	ft_atoi(char *nb)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*nb == '-' || *nb == '+')
	{
		sign = 44 - *nb;
		++nb;
	}
	if (!(*nb >= '0' && *nb <= '9'))
		return ((long long)INT_MAX + 1);
	while (*nb >= '0' && *nb <= '9')
	{
		result = result * 10 + (*nb - '0') * sign;
		++nb;
	}
	if (*nb)
		return ((long long)INT_MAX + 1);
	return (result);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_sqrt(int	nb)
{
	int	i;

	i = 0;
	while ((i * i) < nb)
		i++;
	return (i);
}

int	is_sorted(t_stack **a, t_stack **b)
{
	if (!*b && compute_disorder(*a) == 0.0)
		return (1);
	return (0);
}

int	ft_putchar_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}
