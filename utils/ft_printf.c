/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/29 20:57:18 by marvin            #+#    #+#             */
/*   Updated: 2023/10/29 20:57:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	char	res;
	int		count;

	count = 0;
	if (n <= -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n == 0)
		return (ft_putchar('0'));
	if (n > 9)
		count += ft_putnbr(n / 10);
	res = (n % 10) + '0';
	write(1, &res, 1);
	return (++count);
}

int	what_type(char c, va_list args)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_put_ptr_adress_hexa(va_arg(args, void *)));
	else if (c == 'x')
		return (put_hexa_l(va_arg(args, int)));
	else
		return (put_hexa_u(va_arg(args, unsigned int)));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		else
		{
			count += what_type(str[i + 1], args);
			i++;
		}
	}
	va_end(args);
	return (count);
}
