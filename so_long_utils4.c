/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:14:51 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 21:38:45 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

int	rocket_anim_verif1(t_game *game, char *map)
{
	if (is_collide(map, (((game->ennemy->current_anim->instances[0].y) + 64)
				/ 64) * line_len(game->map->map_path) + (round_up_to_nearest_64(
					game->ennemy->current_anim->instances[0].x) / 64), game)
		&& is_collide(map, (((game->ennemy->current_anim->instances[0].y) + 64)
				/ 64) * line_len(game->map->map_path) + (
				round_down_to_nearest_64(game->ennemy->current_anim
					->instances[0].x) / 64), game))
	{
		game->ennemy->current_anim->instances[0].y += 2;
		return (1);
	}
	return (0);
}

int	rocket_anim_verif2(t_game *game, char *map)
{
	if (is_collide(map, (((game->ennemy->current_anim->instances[0].y + 2) + 64)
				/ 64) * line_len(game->map->map_path) + (round_up_to_nearest_64
				(game->ennemy->current_anim->instances[0].x) / 64), game)
		&& is_collide(map, (((game->ennemy->current_anim->instances[0].y
						+ 2) + 64) / 64) * line_len(game->map->map_path)
			+ (round_down_to_nearest_64(game->ennemy->current_anim->instances[0]
					.x) / 64), game))
	{
		game->ennemy->current_anim->instances[0].y += 2;
		return (1);
	}
	return (0);
}

int	rocket_anim_verif3(t_game *game, char *map)
{
	if (is_collide(map, ((game->ennemy->current_anim->instances[0].y) / 64)
			* line_len(game->map->map_path) + (round_up_to_nearest_64(game
					->ennemy->current_anim->instances[0].x) / 64), game)
		&& is_collide(map, ((game->ennemy->current_anim
					->instances[0].y) / 64) * line_len(game->map->map_path)
			+ (round_down_to_nearest_64(game->ennemy->current_anim->instances
					[0].x) / 64), game))
	{
		game->ennemy->current_anim->instances[0].y -= 2;
		return (1);
	}
	return (0);
}

int	rocket_anim_verif4(t_game *game, char *map)
{
	if (is_collide(map, ((game->ennemy->current_anim->instances[0].y) / 64)
			* line_len(game->map->map_path) + (round_up_to_nearest_64(game
					->ennemy->current_anim->instances[0].x) / 64), game)
		&& is_collide(map, ((game->ennemy->current_anim->instances[0].y)
				/ 64) * line_len(game->map->map_path) + (
				round_down_to_nearest_64(game->ennemy->current_anim
					->instances[0].x) / 64), game))
	{
		game->ennemy->current_anim->instances[0].y -= 2;
		return (1);
	}
	return (0);
}

int	rocket_anim_verif5(t_game *game, char *map)
{
	if (is_collide(map, (round_down_to_nearest_64(game->ennemy->current_anim
					->instances[0].y) / 64) * line_len(game->map->map_path)
			+ (((game->ennemy->current_anim->instances[0].x) + 64)
				/ 64), game) && is_collide(map, (round_up_to_nearest_64(game
					->ennemy->current_anim->instances[0].y) / 64) * line_len
			(game->map->map_path) + (((game->ennemy->current_anim
						->instances[0].x) + 64) / 64), game))
	{
		game->ennemy->current_anim->instances[0].x += 2;
		return (1);
	}
	return (0);
}
