/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long13.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:50:00 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 03:01:46 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	ft_lstiter(t_rocket *lst, void (*f)(void *, t_game *), t_game *game)
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->sprite, game);
		lst = lst->next;
	}
}

void	rocket_moove(mlx_image_t *img, int rand, t_game *game)
{
	char	*map;

	map = game->map->map_file;
	if (rand == 0)
		if (!rocket_moove0(game, img, map))
			return ;
	if (rand == 1)
		if (!rocket_moove1(game, img, map))
			return ;
	if (rand == 2)
		if (!rocket_moove2(game, img, map))
			return ;
	if (rand == 3)
		if (!rocket_moove3(game, img, map))
			return ;
}

void	do_random(void *param, t_game *game)
{
	int				fd;
	unsigned char	buf[1];
	int				read_check;
	int				rand;
	mlx_image_t		*sprite;

	if (!game->ennemy->current_anim
		|| game->ennemy->current_anim->is_anim == true)
		return ;
	sprite = param;
	fd = open("/dev/urandom", O_RDONLY);
	read_check = read(fd, buf, 1);
	close(fd);
	rand = buf[0] % 8;
	if (rand >= 4)
		return ;
	else
		rocket_moove(sprite, rand, game);
}

void	rocket_loop(void *param)
{
	t_game	*game;

	game = param;
	if (game->wait_moove == 30)
	{
		ft_lstiter(game->ennemy, do_random, game);
		game->wait_moove = 0;
	}
	else
		game->wait_moove += 1;
	return ;
}

void	del(void *mlx, void *img)
{
	t_game		*game;
	mlx_image_t	*image;

	game = (t_game *)mlx;
	image = (mlx_image_t *)img;
	mlx_delete_image(game->mlx, image);
}
