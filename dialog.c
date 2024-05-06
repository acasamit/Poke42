/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:03:01 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 18:52:26 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	bike_dialog(void *param)
{
	t_game		*game;

	game = param;
	if (game->bike_dialog == false && mlx_is_key_down(game->mlx, MLX_KEY_ENTER)
		&& game->collide_bike == true && game->pikachu_number == 0)
	{
		game->bike_dialog = true;
		game->win_dialog = true;
	}
	if (game->bike_dialog == false && mlx_is_key_down(game->mlx, MLX_KEY_ENTER)
		&& game->collide_bike == true && game->pikachu_number != 0)
	{
		game->bike_dialog = true;
		game->cant_leave = true;
	}
}

void	win_dialog(void *param)
{
	static int	first = 0;
	static int	deux = 2;
	t_game		*game;

	game = param;
	if (game->win_dialog == false)
		return ;
	game->menu->is_dialog = true;
	if ((first++ == 0 || game->do_dialog_anim == true) && (deux++ % 2) == 0)
		set_dialog_param(game, "sprites/dialogs/win/", 20);
	if (game->do_dialog_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->win_dialog = false;
		game->win_wait = true;
		first = 0;
	}
}

void	win_wait(void *param)
{
	t_game		*game;

	game = param;
	if (game->win_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
	{
		mlx_close_window(game->mlx);
		game->menu->is_dialog = false;
	}
}

void	ft_dialog_anim(void *param)
{
	static int	frame = 0;
	static int	wait = 1;
	t_game		*game;

	game = param;
	if (game->do_dialog_anim == false)
		return ;
	if (frame != wait)
		frame++;
	if (frame == game->hmframes)
	{
		frame = 0;
		wait = 1;
		game->do_dialog_anim = false;
		game->want_co = game->zero;
		return ;
	}
	if (frame != 1)
		mlx_delete_image(game->mlx, game->dialog_img);
	game->dialog_img = mlx_texture_to_image(game->mlx,
			game->tlist->dial = mlx_load_png(game->anim_path));
	mlx_delete_texture(game->tlist->dial);
	mlx_image_to_window(game->mlx, game->dialog_img,
		game->mlx->width - 832, game->mlx->height - 448);
	wait++;
}

void	set_dialog_param(t_game *game, char *path,
		int frame)
{
	static int	i = 0;
	char		*itof;

	if (game->do_dialog_anim == false)
	{
		i = 0;
		game->anim_path = malloc(ft_strlen(path) + 8);
	}
	if (++i < frame)
	{
		game->anim_path[0] = '\0';
		itof = ft_itoa(i);
		ft_strcat(game->anim_path, path);
		ft_strcat(game->anim_path, itof);
		ft_strcat(game->anim_path, ".png");
		free(itof);
	}
	game->hmframes = frame;
	game->do_dialog_anim = true;
}
