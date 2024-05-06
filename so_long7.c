/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:11:11 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 19:02:59 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

int	is_collide(char *map, int index, t_game *game)
{
	static char	*collide_list = "1SEC";
	int			i;

	i = -1;
	if (map[index] == 'E')
		game->collide_bike = true;
	else
		game->collide_bike = false;
	if (map[index] == 'C')
	{
		game->collide_pikachu = true;
		game->pika_index = index;
	}
	else
	{
		game->collide_pikachu = false;
		game->pika_index = -42;
	}
	while (collide_list[++i])
	{
		if (collide_list[i] == map[index])
			return (0);
	}
	return (1);
}

int	can_moove_to(int32_t x, int32_t y, char direction, t_game *game)
{
	if (direction == 'h')
		return (is_collide(game->map->map_file, ((y - 2) / 64)
				* line_len(game->map->map_path) + (round_up_to_nearest_64(x)
					/ 64), game) && is_collide(game->map->map_file, ((y) / 64)
				* line_len(game->map->map_path) + (round_down_to_nearest_64(x)
					/ 64), game));
	if (direction == 'b')
		return (is_collide(game->map->map_file, (((y) + 64) / 64)
				* line_len(game->map->map_path) + (round_up_to_nearest_64(x)
					/ 64), game) && is_collide(game->map->map_file, (((y) + 64)
					/ 64) * line_len(game->map->map_path)
				+ (round_down_to_nearest_64(x) / 64), game));
	if (direction == 'd')
		return (is_collide(game->map->map_file, (round_down_to_nearest_64(y)
					/ 64) * line_len(game->map->map_path) + (((x) + 64) / 64),
				game) && is_collide(game->map->map_file,
				(round_up_to_nearest_64(y) / 64) * line_len(game->map->map_path)
				+ (((x) + 64) / 64), game));
	if (direction == 'g')
		return (is_collide(game->map->map_file, (round_down_to_nearest_64(y)
					/ 64) * line_len(game->map->map_path) + ((x) / 64), game)
			&& is_collide(game->map->map_file, (round_up_to_nearest_64(y) / 64)
				* line_len(game->map->map_path) + ((x) / 64), game));
	else
		return (0);
}

void	ft_moovement_count(void *param)
{
	t_game		*game;
	static int	player_index = -1;

	game = param;
	if (player_index != ((game->player_img->instances[0].y - 2) / 64)
		* line_len(game->map->map_path) + (game->player_img->instances[0].x
			/ 64))
	{
		game->moove_num += 1;
		player_index = ((game->player_img->instances[0].y - 2) / 64)
			* line_len(game->map->map_path) + (game->player_img->instances[0].x
				/ 64);
	}
}

void	ft_escape_quit(void *param)
{
	static t_game	*game;
	static int		frame = 0;

	game = param;
	if (frame++ != 3)
		return ;
	else
		frame = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& game->menu->menu_res->enabled == true && game->wait_frames == 0)
	{
		game->menu->menu_res->enabled = false;
		game->menu->menu_save->enabled = true;
		game->wait_frames = 30;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER)
		&& game->menu->menu_quit->enabled == true)
	{
		mlx_close_window(game->mlx);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER)
		&& game->menu->menu_save->enabled == true)
		menu_utils(game);
}

void	ft_escape_save(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& game->menu->menu_save->enabled == true && game->wait_frames == 0)
	{
		game->menu->menu_save->enabled = false;
		game->menu->menu_res->enabled = true;
		game->wait_frames = 30;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& game->menu->menu_save->enabled == true && game->wait_frames == 0)
	{
		game->menu->menu_save->enabled = false;
		game->menu->menu_quit->enabled = true;
		game->wait_frames = 30;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& game->menu->menu_quit->enabled == true && game->wait_frames == 0)
	{
		game->menu->menu_quit->enabled = false;
		game->menu->menu_save->enabled = true;
		game->wait_frames = 30;
	}
	ft_escape_quit(game);
}
