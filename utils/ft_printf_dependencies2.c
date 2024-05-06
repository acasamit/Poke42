/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dependencies2.C                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/11/02 13:52:08 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/02 13:52:08 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hexa_u(unsigned int n)
{
	int					count;
	unsigned long long	address;

	if (n == 0)
		return (ft_putchar('0'));
	count = 0;
	address = n;
	return (hexa_utils3(address, n, count));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	hexa_utils(unsigned long long address, void *ptr, int count)
{
	int		count_false;
	int		boool;
	int		i;
	char	c;

	boool = 1;
	i = -1;
	count_false = 0;
	while (++i < 16)
	{
		address = (unsigned long long)ptr;
		address >>= 60 - (4 * (count + count_false));
		if (!(address & 0xF) && (boool == 1))
			count_false++;
		else
		{
			c = bin_to_hex_l(address & 0xF);
			write(1, &c, 1);
			count++;
			boool = 0;
		}
	}
	return (count);
}

int	hexa_utils2(unsigned long long address, unsigned int nbr, int count)
{
	int		count_false;
	int		boool;
	int		i;
	char	c;

	boool = 1;
	i = -1;
	count_false = 0;
	while (++i < 16)
	{
		address = (unsigned long long)nbr;
		address >>= 60 - (4 * (count + count_false));
		if (!(address & 0xF) && (boool == 1))
			count_false++;
		else
		{
			c = bin_to_hex_l(address & 0xF);
			write(1, &c, 1);
			count++;
			boool = 0;
		}
	}
	return (count);
}

int	hexa_utils3(unsigned long long address, unsigned int nbr, int count)
{
	int		count_false;
	int		boool;
	int		i;
	char	c;

	boool = 1;
	i = -1;
	count_false = 0;
	while (++i < 16)
	{
		address = (unsigned long long)nbr;
		address >>= 60 - (4 * (count + count_false));
		if (!(address & 0xF) && (boool == 1))
			count_false++;
		else
		{
			c = bin_to_hex_u(address & 0xF);
			write(1, &c, 1);
			count++;
			boool = 0;
		}
	}
	return (count);
}
