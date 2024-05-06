/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:07:26 by acasamit          #+#    #+#             */
/*   Updated: 2024/01/28 02:24:28 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	str = ft_itoa(n);
	ft_putstr_fd(str, fd);
	free(str);
}

void	ft_load_save(t_game *game)
{
	int		fd;
	char	*map;
	char	*line;

	fd = open("save/save.txt", O_RDONLY);
	map = get_next_line(fd);
	if (!map)
	{
		map_printer(game->map->map_path, game);
		return ;
	}
	map[ft_strlen(map) - 1] = '\0';
	map_printer(game->map->map_path, game);
	line = get_next_line(fd);
	game->player_img->instances[0].x = ft_atoi(line);
	line = get_next_line(fd);
	game->player_img->instances[0].y = ft_atoi(line);
	game->moove_num = ft_atoi(get_next_line(fd)) - 1;
	close (fd);
	free(map);
	free(line);
}

int	ft_is_delimiter(char c, char delim)
{
	return (c == delim);
}

int	ft_strlen_mod(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !ft_is_delimiter(s[i], c))
		i++;
	return (i);
}
