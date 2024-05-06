/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:30:44 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 01:59:30 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	thunder(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->lthunder == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->fight->lthunder == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/thunder/",
			253, game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->ehp -= 13;
		game->fight->tpp -= 1;
		game->fight->lthunder = false;
		first = 0;
	}
}

void	quick(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->lquick == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->fight->lquick == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/quick/",
			183, game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->ehp -= 13;
		game->fight->qpp -= 1;
		game->fight->lquick = false;
		game->fight->quick = false;
		first = 0;
	}
}

void	bar_anim(void *param)
{
	static int	first = 0;
	t_game		*game;

	game = param;
	if (game->fight->is_fighting == false)
	{
		first = 0;
		return ;
	}
	if (first == 0)
	{
		if (game->fight->ehp < 42 && 28 < game->fight->ehp)
		{
			game->fight->ebar_to_mid = true;
			first = 1;
		}
	}
	if (first == 1)
	{
		if (game->fight->ehp < 29 && 15 < game->fight->ehp)
		{
			game->fight->ebar_to_rmid = true;
			first = 0;
		}
	}
}

void	ebarm(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->ebar_to_mid == false)
		return ;
	if (first++ == 0 || game->do_ebar_anim == true)
		set_ebar_anim_param(game, "sprites/fight/bar/", 8);
	if (frame++ != 120)
		return ;
	if (game->do_ebar_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->ebar_to_mid = false;
		eselect_attack(game);
		mlx_delete_image(game->mlx, game->what_img);
		first = 0;
		frame = 0;
	}
}
