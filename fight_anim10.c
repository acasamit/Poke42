/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:11:28 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 19:47:27 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	set_pbar_anim_param(t_game *game, char *path, int frame)
{
	static int	i = 0;
	char		*itof;

	if (game->do_pbar_anim == false)
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
	game->do_pbar_anim = true;
}

void	curse(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->curse == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->fight->curse == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/curse/",
			225, game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->php -= 13;
		game->fight->curse = false;
		first = 0;
	}
}

void	set_anim_param(t_game *game, char *path, int frame, mlx_image_t *image)
{
	static int	i = 0;
	char		*itof;

	if (game->do_anim == false)
	{
		i = 0;
		game->anim_path = malloc(ft_strlen(path) + 8);
		game->what_img = image;
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
	game->do_anim = true;
	game->anim_co = game->want_co;
}

void	ennemy_bar_init(t_game *game)
{
	game->fight->e_bar = image_send(game, "sprites/fight/bar/Hbar.png");
	mlx_image_to_window(game->mlx, game->fight->e_bar, 236, 59);
}

void	player_bar_init(t_game *game)
{
	game->fight->p_bar = image_send(game, "sprites/fight/bar/Hbar.png");
	mlx_image_to_window(game->mlx, game->fight->p_bar, 500, 239);
}
