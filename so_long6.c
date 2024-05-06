/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:10:08 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 18:49:04 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	ft_escape(void *param)
{
	t_game		*game;
	static int	frame = 0;

	game = param;
	if (game->fight->is_fighting == true)
		return ;
	if (frame != 3)
	{
		frame++;
		return ;
	}
	else
		frame = 0;
	if (game->menu->is_escape == false && mlx_is_key_down(game->mlx,
			MLX_KEY_ESCAPE))
	{
		game->menu->menu_res->enabled = true;
		game->menu->is_escape = true;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_ENTER)
		&& game->menu->menu_res->enabled == true)
	{
		game->menu->menu_res->enabled = false;
		game->menu->is_escape = false;
	}
}

void	menu_load(t_game *game)
{
	game->menu->menu_res = mlx_texture_to_image(game->mlx,
			game->tlist->menu1 = mlx_load_png
			("sprites/menu/esc_resume.png"));
	game->menu->menu_save = mlx_texture_to_image(game->mlx,
			game->tlist->menu2 = mlx_load_png("sprites/menu/esc_save.png"));
	game->menu->menu_quit = mlx_texture_to_image(game->mlx,
			game->tlist->menu3 = mlx_load_png("sprites/menu/esc_quit.png"));
	mlx_image_to_window(game->mlx, game->menu->menu_res, 320 - 20, 128);
	mlx_image_to_window(game->mlx, game->menu->menu_save, 320 - 20, 128);
	mlx_image_to_window(game->mlx, game->menu->menu_quit, 320 - 20, 128);
	game->menu->menu_res->enabled = false;
	game->menu->menu_save->enabled = false;
	game->menu->menu_quit->enabled = false;
}

void	ft_print_moove(void *param)
{
	char				*itoaa;
	static mlx_image_t	*str;
	static int			moove_num = 0;
	static t_first		first = {false, false, false, false};
	static t_co			co = {0, 0};

	if (!first.first1)
	{
		co.x = ((t_game *)param)->sign_co.x + 27;
		co.y = ((t_game *)param)->sign_co.y + 16;
		first.first1 = true;
	}
	if (moove_num != ((t_game *)param)->moove_num)
	{
		update_position(((t_game *)param), &first, &co);
		mlx_delete_image(((t_game *)param)->mlx, str);
		itoaa = ft_itoa(((t_game *)param)->moove_num);
		str = mlx_put_string(((t_game *)param)->mlx, itoaa, co.x, co.y);
		moove_num = ((t_game *)param)->moove_num;
		free(itoaa);
	}
}

t_anim	*ft_load_sprite(t_game *game)
{
	t_anim	*animation;

	animation = calloc(sizeof(t_anim), 1);
	animation->front = mlx_texture_to_image(game->mlx,
			game->tlist->p0 = mlx_load_png("sprites/player/player_front.png"));
	animation->back = mlx_texture_to_image(game->mlx,
			game->tlist->p1 = mlx_load_png("sprites/player/player_back.png"));
	animation->left = mlx_texture_to_image(game->mlx,
			game->tlist->p2 = mlx_load_png("sprites/player/player_left.png"));
	animation->right = mlx_texture_to_image(game->mlx,
			game->tlist->p3 = mlx_load_png("sprites/player/player_right.png"));
	animation->wback1 = mlx_texture_to_image(game->mlx,
			game->tlist->p4 = mlx_load_png("sprites/player/player_back1.png"));
	animation->wback2 = mlx_texture_to_image(game->mlx,
			game->tlist->p5 = mlx_load_png("sprites/player/player_back2.png"));
	animation->wleft = mlx_texture_to_image(game->mlx,
			game->tlist->p6 = mlx_load_png("sprites/player/player_left1.png"));
	animation->wright = mlx_texture_to_image(game->mlx,
			game->tlist->p7 = mlx_load_png("sprites/player/playerright1.png"));
	animation->wfront1 = mlx_texture_to_image(game->mlx,
			game->tlist->p8 = mlx_load_png("sprites/player/playerfront1.png"));
	animation->wfront2 = mlx_texture_to_image(game->mlx,
			game->tlist->p9 = mlx_load_png("sprites/player/playerfront2.png"));
	return (animation);
}

t_anim	*ft_load_rocket_sprite(t_game *game)
{
	t_anim	*animation;

	animation = malloc(sizeof(t_anim));
	animation->front = mlx_texture_to_image(game->mlx,
			game->tlist->r0 = mlx_load_png("sprites/ennemy/james_front.png"));
	animation->back = mlx_texture_to_image(game->mlx,
			game->tlist->r1 = mlx_load_png("sprites/ennemy/james_back.png"));
	animation->left = mlx_texture_to_image(game->mlx,
			game->tlist->r2 = mlx_load_png("sprites/ennemy/james_left.png"));
	animation->right = mlx_texture_to_image(game->mlx,
			game->tlist->r3 = mlx_load_png("sprites/ennemy/james_right.png"));
	animation->wback1 = mlx_texture_to_image(game->mlx,
			game->tlist->r4 = mlx_load_png("sprites/ennemy/james_wback1.png"));
	animation->wback2 = mlx_texture_to_image(game->mlx,
			game->tlist->r5 = mlx_load_png("sprites/ennemy/james_wback2.png"));
	animation->wleft = mlx_texture_to_image(game->mlx,
			game->tlist->r6 = mlx_load_png("sprites/ennemy/james_wleft.png"));
	animation->wright = mlx_texture_to_image(game->mlx,
			game->tlist->r7 = mlx_load_png("sprites/ennemy/james_wright.png"));
	animation->wfront1 = mlx_texture_to_image(game->mlx,
			game->tlist->r8 = mlx_load_png("sprites/ennemy/james_wfront1.png"));
	animation->wfront2 = mlx_texture_to_image(game->mlx,
			game->tlist->r9 = mlx_load_png("sprites/ennemy/james_wfront2.png"));
	return (animation);
}
