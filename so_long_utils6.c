/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:16:22 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 20:17:18 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	free_texture(t_game *game)
{
	mlx_delete_texture(game->tlist->icon);
	mlx_delete_texture(game->tlist->menu1);
	mlx_delete_texture(game->tlist->menu2);
	mlx_delete_texture(game->tlist->menu3);
	mlx_delete_texture(game->tlist->p0);
	mlx_delete_texture(game->tlist->p1);
	mlx_delete_texture(game->tlist->p2);
	mlx_delete_texture(game->tlist->p3);
	mlx_delete_texture(game->tlist->p4);
	mlx_delete_texture(game->tlist->p5);
	mlx_delete_texture(game->tlist->p6);
	mlx_delete_texture(game->tlist->p7);
	mlx_delete_texture(game->tlist->p8);
	mlx_delete_texture(game->tlist->p9);
	mlx_delete_texture(game->tlist->r0);
	mlx_delete_texture(game->tlist->r1);
	mlx_delete_texture(game->tlist->r2);
	mlx_delete_texture(game->tlist->r3);
	mlx_delete_texture(game->tlist->r4);
	mlx_delete_texture(game->tlist->r5);
	mlx_delete_texture(game->tlist->r6);
	mlx_delete_texture(game->tlist->r7);
	mlx_delete_texture(game->tlist->r8);
	mlx_delete_texture(game->tlist->r9);
}

mlx_image_t	*image_send(t_game *game, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	image = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}
