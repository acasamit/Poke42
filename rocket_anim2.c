/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocket_anim2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:54:10 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 21:38:04 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	anim_right_step2(void *param)
{
	t_game		*game;
	static int	frame = 0;
	static int	wait = 0;
	char		*map;

	game = param;
	map = game->map->map_file;
	if (game->test.mooving_d != 2 || game->menu->is_escape == true
		|| game->menu->is_dialog == true || game->fight->is_fighting == true)
		return ;
	if (frame != wait)
	{
		frame++;
		return ;
	}
	game->ennemy->current_anim->pixels = game->rocket_anim->right->pixels;
	wait++;
	if (!rocket_anim_verif5(game, map))
		return (cancel_anim(game));
	if (frame != 15)
		return ;
	cancel_anim(game);
	frame = 0;
	wait = 0;
}

void	anim_right_step1(void *param)
{
	t_game		*game;
	static int	frame = 0;
	static int	wait = 0;
	char		*map;

	game = param;
	map = game->map->map_file;
	if (game->test.mooving_d != 1 || game->menu->is_escape == true
		|| game->menu->is_dialog == true || game->fight->is_fighting == true)
		return ;
	if (frame != wait)
	{
		frame++;
		return ;
	}
	game->ennemy->current_anim->pixels = game->rocket_anim->wright->pixels;
	wait++;
	if (!rocket_anim_verif6(game, map))
		return (cancel_anim(game));
	if (frame != 15)
		return ;
	game->test.mooving_d = 2;
	frame = 0;
	wait = 0;
}

void	anim_left_step2(void *param)
{
	t_game		*game;
	static int	frame = 0;
	static int	wait = 0;
	char		*map;

	game = param;
	map = game->map->map_file;
	if (game->test.mooving_g != 2 || game->menu->is_escape == true
		|| game->menu->is_dialog == true || game->fight->is_fighting == true)
		return ;
	if (frame != wait)
	{
		frame++;
		return ;
	}
	game->ennemy->current_anim->pixels = game->rocket_anim->left->pixels;
	wait++;
	if (!rocket_anim_verif7(game, map))
		return (cancel_anim(game));
	if (frame != 15)
		return ;
	cancel_anim(game);
	frame = 0;
	wait = 0;
}

void	anim_left_step1(void *param)
{
	t_game		*game;
	static int	frame = 0;
	static int	wait = 0;
	char		*map;

	game = param;
	map = game->map->map_file;
	if (game->test.mooving_g != 1 || game->menu->is_escape == true
		|| game->menu->is_dialog == true || game->fight->is_fighting == true)
		return ;
	if (frame != wait)
	{
		frame++;
		return ;
	}
	game->ennemy->current_anim->pixels = game->rocket_anim->wleft->pixels;
	wait++;
	if (!rocket_anim_verif8(game, map))
		return (cancel_anim(game));
	if (frame != 15)
		return ;
	game->test.mooving_g = 2;
	frame = 0;
	wait = 0;
}
