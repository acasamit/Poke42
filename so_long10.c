/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:15:55 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 02:17:58 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	ft_save(t_game *game)
{
	int	fd;

	fd = open("save/save.txt", O_WRONLY);
	if (fd == -1)
	{
		ft_printf("the save file is missing or corrupted\n");
		ft_error();
	}
	ft_putstr_fd(game->map->map_path, fd);
	write(fd, "\n", 1);
	ft_putstr_fd(ft_itoa(game->player_img->instances[0].x), fd);
	write(fd, "\n", 1);
	ft_putstr_fd(ft_itoa(game->player_img->instances[0].y), fd);
	write(fd, "\n", 1);
	ft_putstr_fd(ft_itoa(game->moove_num), fd);
	write(fd, "\n", 1);
	close(fd);
}

int	round_down_to_nearest_64(int num)
{
	return ((num / 64) * 64);
}

int	round_up_to_nearest_64(int num)
{
	return (((num + 63) / 64) * 64);
}

void	ft_fight(t_game *game, mlx_image_t *sprite)
{
	sprite->enabled = false;
	game->fight->is_fighting = true;
	game->fight->is_open = true;
}

int	abs(int value)
{
	if (value < 0)
	{
		return (-value);
	}
	return (value);
}
