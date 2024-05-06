/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:31:19 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 19:40:05 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	fight_menu2(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->fight->fight == true)
	{
		game->fight->fight = false;
		game->fight->item = true;
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, game->fight->sprite_path[2]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->fight->pkmn == true)
	{
		game->fight->pkmn = false;
		game->fight->fight = true;
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, game->fight->sprite_path[0]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
}

void	fight_menu3(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && game->fight->pkmn == true)
	{
		game->fight->pkmn = false;
		game->fight->run = true;
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, game->fight->sprite_path[3]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && game->fight->run == true)
	{
		game->fight->run = false;
		game->fight->item = true;
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, game->fight->sprite_path[2]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
}

void	fight_menu4(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && game->fight->run == true)
	{
		game->fight->run = false;
		game->fight->pkmn = true;
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, game->fight->sprite_path[1]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->fight->item == true)
	{
		game->fight->item = false;
		game->fight->run = true;
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, game->fight->sprite_path[3]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
}

void	fight_menu5(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && game->fight->item == true)
	{
		game->fight->item = false;
		game->fight->fight = true;
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, game->fight->sprite_path[0]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER) && game->fight->fight == true)
	{
		game->fight->battle_wait = 10;
		game->fight->fight = false;
		game->fight->select_attack = true;
		game->fight->thunder = true;
	}
}

void	hp_print(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->display_bar == false)
	{
		first = 0;
		frame = 0;
		return ;
	}
	if (first == 0)
	{
		ennemy_bar_init(game);
		first++;
	}
	if (frame++ != 40)
		return ;
	else
	{
		player_bar_init(game);
		frame++;
	}
}
