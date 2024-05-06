/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:11:34 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 01:55:13 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	cant_leave(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	deux = 2;

	game = param;
	if (game->cant_leave == false)
		return ;
	game->menu->is_dialog = true;
	if ((first++ == 0 || game->do_dialog_anim == true) && (deux++ % 2) == 0)
		set_dialog_param(game, "sprites/dialogs/bike/", 16);
	if (game->do_dialog_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->cant_leave = false;
		game->bike_wait = true;
		first = 0;
	}
}

void	bike_wait(void *param)
{
	t_game		*game;
	static bool	key_pressed = false;
	static int	frame = 20;

	game = param;
	if (game->bike_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER) && key_pressed == false)
	{
		mlx_delete_image(game->mlx, game->dialog_img);
		game->menu->is_dialog = false;
		key_pressed = true;
	}
	if (key_pressed == true && frame != 60)
		frame++;
	else if (key_pressed == true && frame == 60)
	{
		game->bike_wait = false;
		key_pressed = false;
		game->bike_dialog = false;
		game->bike_wait = false;
		frame = 0;
	}
}

void	take_pika(void *param)
{
	t_game	*game;

	game = param;
	if (game->collide_pikachu && mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
	{
		ft_lstpikaiter(game->pika, pika_function, game);
		game->collide_pikachu = false;
	}
}

void	save_anim(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	deux = 2;

	game = param;
	if (game->save_anim == false)
		return ;
	game->menu->is_dialog = true;
	if ((first++ == 0 || game->do_dialog_anim == true) && (deux++ % 2) == 0)
		set_dialog_param(game, "sprites/dialogs/save/", 20);
	if (game->do_dialog_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->save_anim = false;
		game->save_wait = true;
		first = 0;
	}
}

void	save_wait(void *param)
{
	t_game		*game;
	static bool	key_pressed = false;
	static int	frame = 20;

	game = param;
	if (game->save_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER) && key_pressed == false)
	{
		mlx_delete_image(game->mlx, game->dialog_img);
		game->menu->is_dialog = false;
		key_pressed = true;
	}
	if (key_pressed == true && frame != 60)
		frame++;
	else if (key_pressed == true && frame == 60)
	{
		key_pressed = false;
		game->menu->is_dialog = false;
		game->save_wait = false;
		frame = 0;
	}
}
