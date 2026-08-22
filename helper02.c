#include "push_swap.h"

static int ft_putstr_fd(int fd, char *s)
{
	int	count;

	if(!s)
		return (ft_putstr_fd(1, "(null)"));
	count = 0;
	while (*s)
	{
		count += ft_putchar_fd(fd, *s);
		++s;
	}
	return (count);
}

static int	ft_putnbr_fd(int fd, int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_fd(fd, '-');
		nb *= -1;	
	}
	if (nb >= 10)
		count += ft_putnbr_fd(fd, nb / 10);
	count += ft_putchar_fd(fd, (nb % 10) + '0');
	return (count);
}

static int ft_putfloat_fd(int fd, float nb)
{
	int precision;
	int total_float;

	precision = 2;
	total_float = ft_putnbr_fd(fd, (int)nb);
	total_float += write(fd, ".", 1);
	while (precision > 0)
	{
		total_float += ft_putchar_fd(fd, (int)(nb *10) % 10 + '0');
		nb *=10;
		--precision;
	}
	return (total_float);
}

static int	get_format(int fd, const char *format, va_list args)
{
	if (*format == 's')
		return (ft_putstr_fd(fd, va_arg(args, char*)));
	else if (*format == 'd')
		return (ft_putnbr_fd(fd, va_arg(args, int)));
	else if (*format == 'f')
		return (ft_putfloat_fd(fd, va_arg(args, double)));
	else if (*format == '%')
		return (ft_putchar_fd(fd, '%'));
	return (-1);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list args;
	int		final_string;
	int		word;

	final_string = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			word = get_format(fd, ++format, args);
			if (word == -1)
			{
				va_end(args);
				return (final_string);
			}
			final_string += word;
		}
		else
			final_string += ft_putchar_fd(fd, *format);
		++format;
	}
	va_end(args);
	return (final_string);
}
