/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:38:22 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 20:18:03 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

int	rocket_anim_verif6(t_game *game, char *map)
{
	if (is_collide(map, (round_down_to_nearest_64(game->ennemy->current_anim
					->instances[0].y) / 64) * line_len(game->map->map_path)
			+ (((game->ennemy->current_anim->instances[0].x) + 64) / 64),
			game) && is_collide(map, (round_up_to_nearest_64(game->ennemy
					->current_anim->instances[0].y) / 64) * line_len(game->map
				->map_path) + (((game->ennemy->current_anim->instances[0].x)
					+ 64) / 64), game))
	{
		game->ennemy->current_anim->instances[0].x += 2;
		return (1);
	}
	return (0);
}

int	rocket_anim_verif7(t_game *game, char *map)
{
	if (is_collide(map, (round_down_to_nearest_64(game->ennemy->current_anim
					->instances[0].y) / 64) * line_len(game->map->map_path) + (
				(game->ennemy->current_anim->instances[0].x - 2) / 64), game)
		&& is_collide(map, (round_up_to_nearest_64(game->ennemy->current_anim
					->instances[0].y) / 64) * line_len(game->map->map_path)
			+ ((game->ennemy->current_anim->instances[0].x - 2) / 64), game))
	{
		game->ennemy->current_anim->instances[0].x -= 2;
		return (1);
	}
	return (0);
}

int	rocket_anim_verif8(t_game *game, char *map)
{
	if (is_collide(map, (round_down_to_nearest_64(game->ennemy->current_anim
					->instances[0].y) / 64) * line_len(game->map->map_path) + (
				(game->ennemy->current_anim->instances[0].x - 2) / 64), game)
		&& is_collide(map, (round_up_to_nearest_64(game->ennemy->current_anim
					->instances[0].y) / 64) * line_len(game->map->map_path) + (
				(game->ennemy->current_anim->instances[0].x - 2) / 64), game))
	{
		game->ennemy->current_anim->instances[0].x -= 2;
		return (1);
	}
	return (0);
}

void	end_program(t_game *game)
{
	int	i;

	i = -1;
	game->player_img->pixels = NULL;
	free(game->menu);
	free(game->map->map_file);
	free(game->open_anim);
	while (game->map->map_tab[++i])
		free(game->map->map_tab[i]);
	free(game->map->map_tab);
	free(game->map);
	free(game->fight);
	free(game->player_anim);
	free(game->rocket_anim);
	free(game->ennemy);
	free(game->pika);
	free_texture(game);
	free(game->tlist);
	mlx_terminate(game->mlx);
}

void	end_program_error(t_game *game)
{
	int	i;

	i = -1;
	free(game->open_anim);
	free(game->menu);
	free(game->map->map_file);
	while (game->map->map_tab[++i])
		free(game->map->map_tab[i]);
	free(game->map->map_tab);
	free(game->map);
	free(game->fight);
	free(game->tlist);
}
