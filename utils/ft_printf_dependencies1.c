/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dependencies1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/30 11:45:49 by marvin            #+#    #+#             */
/*   Updated: 2023/10/30 11:45:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	bin_to_hex_l(unsigned int bin)
{
	if (bin < 10)
		return (bin + '0');
	else
		return (bin + 'a' - 10);
}

char	bin_to_hex_u(unsigned int bin)
{
	if (bin < 10)
		return (bin + '0');
	else
		return (bin + 'A' - 10);
}

int	ft_put_ptr_adress_hexa(void *ptr)
{
	int					count;
	unsigned long long	address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	address = (unsigned long long)ptr;
	ft_putstr("0x");
	return (hexa_utils(address, ptr, count) + 2);
}

int	ft_putunbr(unsigned int n)
{
	char	res;
	int		count;

	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n > 9)
		count += ft_putnbr(n / 10);
	res = (n % 10) + '0';
	write(1, &res, 1);
	return (++count);
}

int	put_hexa_l(unsigned int n)
{
	int					count;
	unsigned long long	address;

	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	address = n;
	return (hexa_utils2(address, n, count));
}
