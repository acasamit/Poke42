/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:08:30 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 19:49:48 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	ft_do_anim(void *param)
{
	static int	frame = 0;
	static int	wait = 1;
	t_game		*game;

	game = param;
	if (game->do_anim == false)
		return ;
	if (frame != wait)
		frame++;
	if (frame == game->hmframes)
	{
		frame = 0;
		wait = 1;
		game->do_anim = false;
		game->want_co = game->zero;
		return ;
	}
	if (frame != 1)
		mlx_delete_image(game->mlx, game->what_img);
	game->what_img = mlx_texture_to_image(game->mlx,
			game->tlist->a = mlx_load_png(game->anim_path));
	mlx_delete_texture(game->tlist->a);
	mlx_image_to_window(game->mlx, game->what_img,
		0, 0);
	wait++;
}

void	ft_open_fight(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->is_open == false)
		return ;
	if (frame++ == 52)
	{
		game->open_anim->back_img = image_send(game, "sprites/fight/back.png");
		mlx_image_to_window(game->mlx, game->open_anim->back_img, 0, 0);
	}
	if (first++ == 0 || game->do_anim == true)
		set_anim_param(game, "sprites/fight/open_anim/",
			105, game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->is_open = false;
		game->fight->first_wait = true;
		first = 0;
		frame = 0;
	}
}

void	first_fight_wait(void *param)
{
	t_game		*game;

	game = param;
	if (game->fight->first_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
	{
		mlx_delete_image(game->mlx, game->what_img);
		game->fight->first_wait = false;
		game->fight->is_deploy = true;
	}
}

void	deploy_anim(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->is_deploy == false)
		return ;
	if ((first++ == 0 || game->do_anim == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/deploy/", 250,
			game->open_anim->current_frame);
	if (frame++ == 44)
		game->fight->display_bar = true;
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->is_deploy = false;
		game->fight->menu = true;
		mlx_delete_image(game->mlx, game->what_img);
		first = 0;
		frame = 0;
	}
}

void	fight_menu1(void *param)
{
	t_game		*game;
	static int	first = 0;

	game = param;
	if (game->fight->is_fighting == false || game->fight->menu == false)
	{
		first = 0;
		return ;
	}
	if (first++ == 0)
	{
		game->what_img = image_send(game, game->fight->sprite_path[0]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
		game->fight->fight = true;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) && game->fight->fight == true)
	{
		game->fight->fight = false;
		game->fight->pkmn = true;
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, game->fight->sprite_path[1]);
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
}
