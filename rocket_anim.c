/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocket_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:04:14 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 21:14:32 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	cancel_anim(t_game *game)
{
	game->ennemy->current_anim->is_anim = false;
	if (game->test.mooving_b != 0)
		game->ennemy->current_anim->pixels = game->rocket_anim->front->pixels;
	if (game->test.mooving_h != 0)
		game->ennemy->current_anim->pixels = game->rocket_anim->back->pixels;
	if (game->test.mooving_g != 0)
		game->ennemy->current_anim->pixels = game->rocket_anim->left->pixels;
	if (game->test.mooving_d != 0)
		game->ennemy->current_anim->pixels = game->rocket_anim->right->pixels;
	game->test.mooving_b = 0;
	game->test.mooving_h = 0;
	game->test.mooving_g = 0;
	game->test.mooving_d = 0;
}

void	anim_front_step2(void *param)
{
	t_game		*game;
	static int	frame = 0;
	static int	wait = 0;
	char		*map;

	game = param;
	map = game->map->map_file;
	if (game->test.mooving_b != 2 || game->menu->is_escape == true
		|| game->menu->is_dialog == true || game->fight->is_fighting == true)
		return ;
	if (frame != wait)
	{
		frame++;
		return ;
	}
	game->ennemy->current_anim->pixels = game->rocket_anim->wfront2->pixels;
	wait++;
	if (!rocket_anim_verif1(game, map))
		return (cancel_anim(game));
	if (frame != 15)
		return ;
	cancel_anim(game);
	frame = 0;
	wait = 0;
}

void	anim_front_step1(void *param)
{
	t_game		*game;
	static int	frame = 0;
	static int	wait = 0;
	char		*map;

	game = param;
	map = game->map->map_file;
	if (game->test.mooving_b != 1 || game->menu->is_escape == true
		|| game->menu->is_dialog == true || game->fight->is_fighting == true)
		return ;
	if (frame != wait)
	{
		frame++;
		return ;
	}
	game->ennemy->current_anim->pixels = game->rocket_anim->wfront1->pixels;
	wait++;
	if (!rocket_anim_verif2(game, map))
		return (cancel_anim(game));
	if (frame != 15)
		return ;
	game->test.mooving_b = 2;
	frame = 0;
	wait = 0;
}

void	anim_back_step2(void *param)
{
	t_game		*game;
	static int	frame = 0;
	static int	wait = 1;
	char		*map;

	game = param;
	map = game->map->map_file;
	if (game->test.mooving_h != 2 || game->menu->is_escape == true
		|| game->menu->is_dialog == true || game->fight->is_fighting == true)
		return ;
	if (frame != wait)
	{
		frame++;
		return ;
	}
	game->ennemy->current_anim->pixels = game->rocket_anim->wback2->pixels;
	wait++;
	if (!rocket_anim_verif3(game, map))
		return (cancel_anim(game));
	if (frame != 15)
		return ;
	cancel_anim(game);
	frame = 0;
	wait = 0;
}

void	anim_back_step1(void *param)
{
	t_game		*game;
	static int	frame = 0;
	static int	wait = 1;
	char		*map;

	game = param;
	map = game->map->map_file;
	if (game->test.mooving_h != 1 || game->menu->is_escape == true
		|| game->menu->is_dialog == true || game->fight->is_fighting == true)
		return ;
	if (frame != wait)
	{
		frame++;
		return ;
	}
	game->ennemy->current_anim->pixels = game->rocket_anim->wback1->pixels;
	wait++;
	if (!rocket_anim_verif4(game, map))
		return (cancel_anim(game));
	if (frame != 15)
		return ;
	game->test.mooving_h = 2;
	frame = 0;
	wait = 0;
}
