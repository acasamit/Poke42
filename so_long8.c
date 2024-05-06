/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:14:12 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 19:05:06 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

int	line_len(char *map_path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("The map file is corrupted or missing\n");
		ft_error();
	}
	line = get_next_line(fd);
	i = 0;
	close (fd);
	while (line[i])
		i++;
	free(line);
	return (i);
}

int	first_occurence(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-42);
}

void	is_pika(int i, t_game *game, t_co xy)
{
	t_pika	*collectible;

	collectible = calloc(sizeof(t_pika), 1);
	collectible->sprite = mlx_texture_to_image(game->mlx,
			game->tlist->tile = mlx_load_png("sprites/tiles/pikachu.png"));
	mlx_delete_texture(game->tlist->tile);
	collectible->index = i + ((game->line_readed - 1)
			* line_len(game->map->map_path));
	collectible->next = NULL;
	game->pikachu_number += 1;
	if (!game->pika)
		game->pika = collectible;
	else
		ft_lstpikaadd_back(&game->pika, collectible);
	mlx_image_to_window(game->mlx,
		mlx_texture_to_image(game->mlx,
			game->tlist->tile = mlx_load_png
			("sprites/tiles/ground1.png")), xy.x, xy.y);
	mlx_delete_texture(game->tlist->tile);
	mlx_image_to_window(game->mlx, collectible->sprite, xy.x, xy.y);
}

int	what_sprite(int fd, t_game *game)
{
	static t_co	xy = {0};
	char		*line;
	int			i;

	i = -1;
	line = get_next_line(fd);
	game->line_readed += 1;
	if (!line)
		return (0);
	while (line[++i])
	{
		if (line[i] == '\n')
			break ;
		process_tiles(line[i], game, xy, i);
		xy.x += 64;
	}
	xy.x = 0;
	xy.y += 64;
	free(line);
	return (1);
}

void	map_printer(char *map_path, t_game *game)
{
	int	fd;
	int	i;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("The map file is corrupted or missing\n");
		end_program(game);
		ft_error();
	}
	if (!fd)
		ft_error();
	i = 1;
	while (i)
		i = what_sprite(fd, game);
	close (fd);
	game->player_img = mlx_texture_to_image(game->mlx,
			game->tlist->tile = mlx_load_png
			("sprites/player/player_front.png"));
	mlx_delete_texture(game->tlist->tile);
	free(game->player_img->pixels);
	mlx_image_to_window(game->mlx, game->player_img,
		game->player_co.x, game->player_co.y);
}
