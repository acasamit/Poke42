/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:11:48 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 00:44:05 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	win_message(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->wmess == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->do_anim == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/wmessage/", 60,
			game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->wmess = false;
		game->fight->fourth_wait = true;
		first = 0;
		frame = 0;
	}
}

void	fourth_fight_wait(void *param)
{
	t_game		*game;

	game = param;
	if (game->fight->fourth_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
	{
		mlx_delete_image(game->mlx, game->what_img);
		game->fight->rage_mess = true;
		game->fight->fourth_wait = false;
	}
}

void	rage_message(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->rage_mess == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->do_anim == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/ragemess/", 138,
			game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->rage_mess = false;
		game->fight->fifth_wait = true;
		first = 0;
		frame = 0;
	}
}

void	fifth_fight_wait(void *param)
{
	t_game		*game;

	game = param;
	if (game->fight->fifth_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
	{
		mlx_delete_image(game->mlx, game->what_img);
		game->fight->money = true;
		game->fight->fifth_wait = false;
	}
}

void	money_gain(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->money == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->do_anim == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/money/", 48,
			game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->money = false;
		game->fight->sixth_wait = true;
		mlx_delete_image(game->mlx, game->open_anim->current_frame);
		first = 0;
		frame = 0;
	}
}
