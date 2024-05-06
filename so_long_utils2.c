/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:58:49 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 19:02:46 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

mlx_image_t	*moove_y_utils1(t_game *game, int i)
{
	if (i % 2 == 0)
		return (game->player_anim->wback1);
	else
		return (game->player_anim->wback2);
}

mlx_image_t	*moove_y_utils2(t_game *game, int i)
{
	if (i % 2 == 0)
		return (game->player_anim->wfront1);
	else
		return (game->player_anim->wfront2);
}

mlx_image_t	*moove_x_utils(t_game *game, int i)
{
	if ((i % 2) == 0)
		return (game->player_anim->wright);
	else
		return (game->player_anim->right);
}

void	process_player(t_game *game, t_co xy)
{
	mlx_image_to_window(game->mlx, mlx_texture_to_image
		(game->mlx, game->tlist->tile = mlx_load_png
			("sprites/tiles/ground1.png")), xy.x, xy.y);
	mlx_delete_texture(game->tlist->tile);
	game->player_co = xy;
}

void	process_rocket(t_game *game, t_co xy)
{
	t_rocket	*james;

	james = calloc(sizeof(t_rocket), 1);
	james->sprite = mlx_texture_to_image
		(game->mlx, game->tlist->tile = mlx_load_png
			("sprites/ennemy/james_front.png"));
	mlx_delete_texture(game->tlist->tile);
	james->next = NULL;
	mlx_image_to_window(game->mlx, mlx_texture_to_image
		(game->mlx, game->tlist->tile = mlx_load_png
			("sprites/tiles/ground1.png")), xy.x, xy.y);
	mlx_delete_texture(game->tlist->tile);
	if (!game->ennemy)
		game->ennemy = james;
	else
		ft_lstadd_back(&game->ennemy, james);
	mlx_image_to_window(game->mlx, james->sprite, xy.x, xy.y);
	mlx_set_instance_depth(james->sprite->instances,
		ft_strlen(game->map->map_file) - line_counter(game->map->map_path));
}
