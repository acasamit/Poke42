/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:16:32 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 02:20:00 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

char	*ft_itoa(int _n)
{
	char	*str;
	int		len;
	long	n;

	n = _n;
	len = lenn(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (1)
	{
		str[len--] = '0' + (n % 10);
		n /= 10;
		if (n == 0)
			break ;
	}
	return (str);
}

void	update_game(void *param)
{
	t_game	*game;

	game = param;
	if (game->wait_frames > 0)
	{
		game->wait_frames--;
		return ;
	}
}

void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}

void	ft_putustr_fd(unsigned char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}
