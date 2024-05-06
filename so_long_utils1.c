/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:34:50 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 20:01:13 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	select_attack_utils1(t_game *game)
{
	mlx_delete_image(game->mlx, game->what_img);
	game->what_img = image_send(game, "sprites/fight/attack/thunder.png");
	mlx_image_to_window(game->mlx, game->what_img, 0, 0);
	game->fight->thunder = true;
	game->fight->quick = false;
}

void	select_attack_utils2(t_game *game)
{
	game->fight->lthunder = true;
	mlx_delete_image(game->mlx, game->what_img);
}

void	select_attack_utils3(t_game *game)
{
	game->fight->lquick = true;
	mlx_delete_image(game->mlx, game->what_img);
}

void	menu_utils(t_game *game)
{
	ft_save(game);
	game->menu->is_dialog = true;
	game->save_anim = true;
	game->menu->menu_save->enabled = false;
	game->menu->is_escape = false;
}

void	update_position(t_game *game, t_first *first, t_co *co)
{
	if (game->moove_num >= 10 && !first->first2)
	{
		co->x -= 5;
		first->first2 = true;
	}
	if (game->moove_num >= 100 && !first->first3)
	{
		co->x -= 5;
		first->first3 = true;
	}
	if (game->moove_num >= 1000 && !first->first4)
	{
		co->x -= 5;
		first->first4 = true;
	}
}
