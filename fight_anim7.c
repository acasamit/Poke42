/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:47:27 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/20 19:44:42 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	ebard(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->ebar_to_death == false)
		return ;
	if (first++ == 0 || game->do_ebar_anim == true)
		set_ebar_anim_param(game, "sprites/fight/bar/tod/", 11);
	if (frame++ != 120)
		return ;
	if (game->do_ebar_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->ebar_to_death = false;
		game->fight->ectofainted = true;
		mlx_delete_image(game->mlx, game->what_img);
		first = 0;
		frame = 0;
	}
}

void	ectofainted(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->ectofainted == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->do_anim == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/pwin/", 72,
			game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->ectofainted = false;
		game->fight->second_wait = true;
		first = 0;
		frame = 0;
	}
}

void	second_fight_wait(void *param)
{
	t_game		*game;

	game = param;
	if (game->fight->second_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
	{
		mlx_delete_image(game->mlx, game->what_img);
		game->fight->exp = true;
		game->fight->second_wait = false;
	}
}

void	exp_gain(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->exp == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->do_anim == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/exp/", 60,
			game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->exp = false;
		game->fight->third_wait = true;
		first = 0;
		frame = 0;
	}
}

void	third_fight_wait(void *param)
{
	t_game		*game;

	game = param;
	if (game->fight->third_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
	{
		mlx_delete_image(game->mlx, game->what_img);
		game->fight->wmess = true;
		game->fight->third_wait = false;
	}
}
