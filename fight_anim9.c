/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 02:17:05 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 19:40:38 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	sixth_fight_wait(void *param)
{
	t_game		*game;

	game = param;
	if (game->fight->sixth_wait == false)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER))
	{
		mlx_delete_image(game->mlx, game->open_anim->current_frame);
		game->fight->end_combat = true;
		game->fight->sixth_wait = false;
	}
}

void	end_combat(void *param)
{
	t_game	*game;

	game = param;
	if (game->fight->end_combat == false)
		return ;
	mlx_delete_image(game->mlx, game->what_img);
	mlx_delete_image(game->mlx, game->open_anim->back_img);
	mlx_delete_image(game->mlx, game->fight->e_bar);
	mlx_delete_image(game->mlx, game->fight->p_bar);
	game->fight->p_bar = NULL;
	game->fight->ehp = 42;
	game->fight->php = 42;
	game->fight->tpp = 30;
	game->fight->qpp = 30;
	game->fight->end_combat = false;
	game->fight->display_bar = false;
	game->fight->is_fighting = false;
}

void	ft_do_bar_anim(void *param)
{
	static int	frame = 0;
	static int	wait = 1;
	t_game		*game;

	game = param;
	if (game->do_ebar_anim == false)
		return ;
	if (frame != wait)
		frame++;
	if (frame == game->hmframes)
	{
		frame = 0;
		wait = 1;
		game->do_ebar_anim = false;
		return ;
	}
	mlx_delete_image(game->mlx, game->fight->e_bar);
	game->fight->e_bar = mlx_texture_to_image(game->mlx,
			game->tlist->h = mlx_load_png(game->anim_path));
	mlx_delete_texture(game->tlist->h);
	mlx_image_to_window(game->mlx, game->fight->e_bar, 236, 59);
	wait++;
}

void	ft_do_pbar_anim(void *param)
{
	static int	frame = 0;
	static int	wait = 1;
	t_game		*game;

	game = param;
	if (game->do_pbar_anim == false)
		return ;
	if (frame != wait)
		frame++;
	if (frame == game->hmframes)
	{
		frame = 0;
		wait = 1;
		game->do_pbar_anim = false;
		return ;
	}
	mlx_delete_image(game->mlx, game->fight->p_bar);
	game->fight->p_bar = mlx_texture_to_image(game->mlx,
			game->tlist->p = mlx_load_png(game->anim_path));
	mlx_delete_texture(game->tlist->p);
	mlx_image_to_window(game->mlx, game->fight->p_bar, 500, 239);
	wait++;
}

void	set_ebar_anim_param(t_game *game, char *path, int frame)
{
	static int	i = 0;
	char		*itof;

	if (game->do_ebar_anim == false)
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
	game->do_ebar_anim = true;
}
