/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:08:51 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 19:59:24 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	ft_moove_x(char c, t_game *game)
{
	static int		frame = 15;
	static int		i = 0;
	mlx_image_t		*sprite;

	if (c == 'd')
		sprite = moove_x_utils(game, i);
	else if (c == 'g')
	{
		if ((i % 2) == 0)
			sprite = game->player_anim->wleft;
		else
			sprite = game->player_anim->left;
	}
	if (frame == 15)
	{
		game->player_img->pixels = sprite->pixels;
		frame = 0;
		i++;
	}
	if (c == 'd')
		game->player_img->instances[0].x += 2;
	else if (c == 'g')
		game->player_img->instances[0].x -= 2;
	frame++;
}

void	ft_moove_y(char c, t_game *game)
{
	static int	frame = 15;
	static int	i = 0;
	mlx_image_t	*sprite;

	if (c == 'h' && (mlx_is_key_down(game->mlx, MLX_KEY_D) == false))
		sprite = moove_y_utils1(game, i);
	else if (c == 'b' && (mlx_is_key_down(game->mlx, MLX_KEY_D) == false))
		sprite = moove_y_utils2(game, i);
	if ((mlx_is_key_down(game->mlx, MLX_KEY_D) == false)
		&& (mlx_is_key_down(game->mlx, MLX_KEY_A) == false))
		game->player_img->pixels = sprite->pixels;
	if (frame == 15)
	{
		frame = 0;
		i++;
	}
	if (c == 'h')
		game->player_img->instances[0].y -= 2;
	else if (c == 'b')
		game->player_img->instances[0].y += 2;
	frame++;
}

int	is_double_press(t_game *game)
{
	return ((mlx_is_key_down(game->mlx, MLX_KEY_W) && mlx_is_key_down(game->mlx,
				MLX_KEY_S)) || (mlx_is_key_down(game->mlx, MLX_KEY_D)
			&& mlx_is_key_down(game->mlx, MLX_KEY_A)));
}

void	ft_nothing_press(t_game *game, char last_dir)
{
	if ((mlx_is_key_down(game->mlx, MLX_KEY_D) == false)
		&& (mlx_is_key_down(game->mlx, MLX_KEY_A) == false)
		&& (mlx_is_key_down(game->mlx, MLX_KEY_W) == false)
		&& (mlx_is_key_down(game->mlx, MLX_KEY_S) == false))
	{
		if (last_dir == 'b')
			game->player_img->pixels = game->player_anim->front->pixels;
		if (last_dir == 'h')
			game->player_img->pixels = game->player_anim->back->pixels;
		if (last_dir == 'd')
			game->player_img->pixels = game->player_anim->right->pixels;
		if (last_dir == 'g')
			game->player_img->pixels = game->player_anim->left->pixels;
	}
	else
		return ;
}

void	key_hook(void *param)
{
	t_game		*game;
	static char	last_dir = 'b';

	game = param;
	if (game->menu->is_escape == true || game->fight->is_fighting == true
		|| game->menu->is_dialog == true || is_double_press(game))
		return ;
	ft_nothing_press(game, last_dir);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& can_moove_to(game->player_img->instances[0].x,
			game->player_img->instances[0].y, 'd', game))
		ft_moove_x(last_dir = 'd', game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& can_moove_to(game->player_img->instances[0].x,
			game->player_img->instances[0].y, 'g', game))
		ft_moove_x(last_dir = 'g', game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& can_moove_to(game->player_img->instances[0].x,
			game->player_img->instances[0].y, 'h', game))
		ft_moove_y(last_dir = 'h', game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& can_moove_to(game->player_img->instances[0].x,
			game->player_img->instances[0].y, 'b', game))
		ft_moove_y(last_dir = 'b', game);
}
