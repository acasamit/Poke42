/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight_anim5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:01:02 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 00:54:22 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/ft_printf.h"
#include "utils/get_next_line.h"

void	eselect_attack(t_game *game)
{
	int				fd;
	unsigned char	buf[1];
	int				read_check;
	int				rand;

	(void)game;
	fd = open("/dev/urandom", O_RDONLY);
	read_check = read(fd, buf, 1);
	close(fd);
	rand = buf[0] % 2;
	if (rand == 0)
		game->fight->curse = true;
	else
		game->fight->shadow = true;
}

void	shadow(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	deux = 2;

	game = param;
	if (game->fight->shadow == false)
		return ;
	game->want_co = game->zero;
	if ((first++ == 0 || game->fight->shadow == true) && (deux++ % 2) == 0)
		set_anim_param(game, "sprites/fight/shadow/",
			295, game->open_anim->current_frame);
	if (game->do_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->php -= 13;
		game->fight->shadow = false;
		first = 0;
	}
}

void	pbar_anim(void *param)
{
	static int	first = 0;
	t_game		*game;

	game = param;
	if (game->fight->p_bar == NULL)
		first = 0;
	if (first == 0)
	{
		if (game->fight->php == 29)
		{
			game->fight->pbar_to_mid = true;
			first = 1;
		}
	}
	if (first == 1 || first == 0)
	{
		if (game->fight->php == 16)
		{
			game->fight->pbar_to_rmid = true;
			first = 2;
			game->fight->pbar_verif2 = true;
		}
	}
}

void	pbarm(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->pbar_to_mid == false)
		return ;
	if (first++ == 0 || game->do_pbar_anim == true)
		set_pbar_anim_param(game, "sprites/fight/bar/", 8);
	if (frame++ != 120)
		return ;
	if (game->do_pbar_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->pbar_to_mid = false;
		game->fight->menu = true;
		game->fight->thunder = true;
		mlx_delete_image(game->mlx, game->what_img);
		first = 0;
		frame = 0;
	}
}

void	ebarrm(void *param)
{
	t_game		*game;
	static int	first = 0;
	static int	frame = 0;

	game = param;
	if (game->fight->ebar_to_rmid == false)
		return ;
	if (first++ == 0 || game->do_ebar_anim == true)
		set_ebar_anim_param(game, "sprites/fight/bar/tom/", 8);
	if (frame++ != 120)
		return ;
	if (game->do_ebar_anim == false)
	{
		free(game->anim_path);
		game->anim_path = NULL;
		game->fight->ebar_to_rmid = false;
		eselect_attack(game);
		mlx_delete_image(game->mlx, game->what_img);
		first = 0;
		frame = 0;
	}
}
