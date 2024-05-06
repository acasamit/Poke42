/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:26:51 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 20:11:30 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	select_attack(void *param)
{
	t_game		*game;
	static int	first = 0;

	game = param;
	if (game->fight->select_attack == false)
	{
		first = 0;
		return ;
	}
	if (first++ == 0)
	{
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, "sprites/fight/attack/thunder.png");
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	}
	if (game->fight->thunder == true && mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		mlx_delete_image(game->mlx, game->what_img);
		game->what_img = image_send(game, "sprites/fight/attack/quick.png");
		mlx_image_to_window(game->mlx, game->what_img, 0, 0);
		game->fight->thunder = false;
		game->fight->quick = true;
	}
}

void	select_attack2(void *param)
{
	t_game	*game;

	game = param;
	if (game->fight->quick == true && mlx_is_key_down(game->mlx, MLX_KEY_W))
		select_attack_utils1(game);
	if ((game->fight->quick == true || game->fight->thunder == true)
		&& mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(game->mlx, game->what_img);
		game->fight->select_attack = false;
		game->fight->thunder = false;
		game->fight->quick = false;
		game->fight->menu = true;
	}
	if (game->fight->battle_wait != 0)
	{
		game->fight->battle_wait--;
		return ;
	}
	if (game->fight->thunder == true
		&& mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
		select_attack_utils2(game);
	if (game->fight->quick == true && mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
		select_attack_utils3(game);
}

void	bool_checker(void *param)
{
	t_game	*game;

	game = param;
	if (game->fight->is_deploy == true)
		game->fight->first_wait = false;
	if (game->fight->menu == true)
		game->fight->is_deploy = false;
	if (game->fight->select_attack == true)
		game->fight->menu = false;
	if (game->fight->lthunder == true || game->fight->lquick == true)
	{
		game->fight->thunder = false;
		game->fight->select_attack = false;
	}
	if (game->fight->ebar_to_mid == true || game->fight->pbar_to_mid == true)
	{
		game->fight->lthunder = false;
		game->fight->lquick = false;
	}
}

void	static_pp_print(void *param)
{
	t_game					*game;
	static int				first = 0;

	game = param;
	if (game->fight->select_attack == false)
	{
		if (first > 0)
			mlx_delete_image(game->mlx, game->fight->static_pp);
		first = 0;
		return ;
	}
	if (first == 0)
	{
		game->fight->static_pp = mlx_put_string(game->mlx, "30", 360, 276);
		first++;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		mlx_delete_image(game->mlx, game->fight->static_pp);
		game->fight->static_pp = mlx_put_string(game->mlx, "30", 360, 276);
	}
}

void	pp_print(void *param)
{
	t_game			*game;
	static int		first = 0;

	game = param;
	if (game->fight->select_attack == false)
	{
		if (first > 0)
			mlx_delete_image(game->mlx, game->fight->pp + (first = 0));
		return ;
	}
	if (first++ == 0)
	{
		game->fight->pp = mlx_put_string
			(game->mlx, game->s = ft_itoa(game->fight->tpp), 337, 260);
		free(game->s);
	}
	mlx_delete_image(game->mlx, game->fight->pp);
	if (game->fight->thunder == true)
		game->fight->pp = mlx_put_string
			(game->mlx, game->s = ft_itoa(game->fight->tpp), 337, 260);
	if (game->fight->quick == true)
		game->fight->pp = mlx_put_string
			(game->mlx, game->s = ft_itoa(game->fight->qpp), 337, 260);
	free(game->s);
}
