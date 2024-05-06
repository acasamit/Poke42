/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:52:09 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 19:09:01 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	process_tiles(char c, t_game *game, t_co xy, int i)
{
	char		*str[7];

	str[0] = "sprites/tiles/ground1.png";
	str[1] = "sprites/tiles/bush.png";
	str[2] = "sprites/player/player_front.png";
	str[3] = "sprites/tiles/sign_empty.png";
	str[4] = "sprites/tiles/exit.png";
	str[5] = "sprites/ennemy/james_front.png";
	str[6] = "sprites/tiles/pikachu.png";
	if (c == 'P')
		process_player(game, xy);
	else if (c == 'R')
		process_rocket(game, xy);
	else if (c == 'C')
		is_pika(i, game, xy);
	else
	{
		mlx_image_to_window(game->mlx, mlx_texture_to_image(game->mlx,
				game->tlist->tile = mlx_load_png(str[first_occurence("01PSERC",
						c)])), xy.x, xy.y);
		mlx_delete_texture(game->tlist->tile);
	}
	if (c == 'S')
		game->sign_co = xy;
}

int	rocket_moove0(t_game *game, mlx_image_t *img, char *map)
{
	if (is_collide(map, (((img->instances[0].y) + 64) / 64)
			* line_len(game->map->map_path) + (round_up_to_nearest_64
				(img->instances[0].x) / 64), game) && is_collide(map, ((
					(img->instances[0].y) + 64) / 64) * line_len
			(game->map->map_path) + (round_down_to_nearest_64
				(img->instances[0].x) / 64), game))
	{
		game->ennemy->current_anim = img;
		game->ennemy->current_anim->is_anim = true;
		game->test.mooving_b = 1;
		return (1);
	}
	return (0);
}

int	rocket_moove1(t_game *game, mlx_image_t *img, char *map)
{
	if (is_collide(map, (round_down_to_nearest_64(img->instances[0].y) / 64)
			* line_len(game->map->map_path) + ((img->instances[0].x - 2)
				/ 64), game) && is_collide(map, (round_up_to_nearest_64
				(img->instances[0].y) / 64) * line_len(game->map->map_path)
			+ ((img->instances[0].x - 2) / 64), game))
	{
		game->ennemy->current_anim = img;
		game->ennemy->current_anim->is_anim = true;
		game->test.mooving_g = 1;
		return (1);
	}
	return (0);
}

int	rocket_moove2(t_game *game, mlx_image_t *img, char *map)
{
	if (is_collide(map, ((img->instances[0].y) / 64)
			* line_len(game->map->map_path) + (round_up_to_nearest_64
				(img->instances[0].x) / 64), game) && is_collide(map,
			((img->instances[0].y) / 64) * line_len(game->map->map_path)
			+ (round_down_to_nearest_64(img->instances[0].x) / 64), game))
	{
		game->ennemy->current_anim = img;
		game->ennemy->current_anim->is_anim = true;
		game->test.mooving_h = 1;
		return (1);
	}
	return (0);
}

int	rocket_moove3(t_game *game, mlx_image_t *img, char *map)
{
	if (is_collide(map, (round_down_to_nearest_64(img->instances[0].y) / 64)
			* line_len(game->map->map_path) + (((img->instances[0].x + 2)
					+ 64) / 64), game) && is_collide(map,
			(round_up_to_nearest_64(img->instances[0].y) / 64)
			* line_len(game->map->map_path) + (((img->instances[0].x + 2)
					+ 64) / 64), game))
	{
		game->ennemy->current_anim = img;
		game->ennemy->current_anim->is_anim = true;
		game->test.mooving_d = 1;
		return (1);
	}
	return (0);
}
