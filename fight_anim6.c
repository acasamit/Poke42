/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:42:31 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 02:51:23 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	pbarrm(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->pbar_to_rmid == false)
		return ;
	if (first++ == 0 || game->do_pbar_anim == true)
		set_pbar_anim_param(game, "sprites/fight/bar/tom/", 8);
	if (frame++ != 120)
		return ;
	if (game->do_pbar_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->pbar_to_rmid = false;
		game->fight->menu = true;
		mlx_delete_image(game->mlx, game->what_img);
		first = 0;
		frame = 0;
	}
}

void	pbar_verif2(void *param)
{
	t_game		*game;
	static int	first = 0;

	game = param;
	if (game->fight->p_bar == NULL)
	{
		first = 0;
		return ;
	}
	if (first == 0)
	{
		if (game->fight->php == 3)
		{
			first = 1;
			game->fight->pbar_to_low = true;
		}
	}
}

void	ebar_verif2(void *param)
{
	t_game		*game;
	static int	first = 0;

	game = param;
	if (first == 0)
	{
		if (game->fight->ehp == 3)
		{
			first = 1;
			game->fight->ebar_to_low = true;
		}
	}
	if (first == 1)
	{
		if (game->fight->ehp <= 0)
		{
			first = 0;
			game->fight->ebar_to_death = true;
			game->fight->ebar_verif2 = false;
		}
	}
}

void	ebarl(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->ebar_to_low == false)
		return ;
	if (first++ == 0 || game->do_ebar_anim == true)
		set_ebar_anim_param(game, "sprites/fight/bar/tol/", 10);
	if (frame++ != 120)
		return ;
	if (game->do_ebar_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->ebar_to_low = false;
		eselect_attack(game);
		mlx_delete_image(game->mlx, game->what_img);
		first = 0;
		frame = 0;
	}
}

void	pbarl(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->pbar_to_low == false)
		return ;
	game->want_co.x = 500;
	game->want_co.y = 239;
	if (first++ == 0 || game->do_pbar_anim == true)
		set_pbar_anim_param(game, "sprites/fight/bar/tol/", 10);
	if (frame++ != 120 && game->fight->is_deploy == false)
		return ;
	if (game->do_pbar_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->pbar_to_low = false;
		if (game->fight->is_deploy == false)
			game->fight->menu = true;
		mlx_delete_image(game->mlx, game->what_img);
		first = 0;
		frame = 0;
	}
}
