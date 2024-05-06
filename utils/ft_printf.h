/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:40:00 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/02 22:59:04 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		what_type(char c, va_list args);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
char	bin_to_hex_l(unsigned int bin);
char	bin_to_hex_u(unsigned int bin);
int		ft_put_ptr_adress_hexa(void *ptr);
int		ft_putunbr(unsigned int n);
int		put_hexa_l(unsigned int n);
int		put_hexa_u(unsigned int n);
int		ft_putchar(char c);
int		hexa_utils(unsigned long long address, void *ptr, int count);
int		hexa_utils2(unsigned long long address, unsigned int n, int count);
int		hexa_utils3(unsigned long long address, unsigned int n, int count);

#endif
