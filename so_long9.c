/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:15:10 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 19:18:50 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	is_player_collide_rocket(void *param, t_game *game)
{
	mlx_image_t		*sprite;

	sprite = param;
	if (game->fight->is_fighting == true || sprite->enabled == false)
		return ;
	if ((abs(game->player_img->instances[0].x - sprite->instances[0].x) < 64)
		&& (abs(game->player_img->instances[0].y - sprite->instances[0].y)
			< 64))
		ft_fight(game, sprite);
	else
		return ;
}

void	pika_function(void *param1, int index, t_game *game)
{
	mlx_image_t	*sprite;

	sprite = param1;
	(void)game;
	if (index == game->pika_index)
	{
		sprite->enabled = false;
		game->map->map_file[index] = '0';
		game->pikachu_number -= 1;
	}
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = param;
	if (game->fight->is_fighting == false)
		ft_lstiter(game->ennemy, is_player_collide_rocket, game);
}

int	line_counter(char *map_path)
{
	int		line_count;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("The map file is corrupted or missing\n");
		ft_error();
	}
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line_count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

char	*map_reader(char *map_path)
{
	char	*buf;
	int		fd;
	int		read_check;
	char	*map;

	map = malloc(line_counter(map_path) * line_len(map_path) + 1);
	map[0] = '\0';
	buf = malloc(2);
	fd = open(map_path, O_RDONLY);
	read_check = read(fd, buf, 1);
	buf[1] = '\0';
	if (!read_check)
		ft_error();
	while (read_check)
	{
		map = ft_strcat(map, buf);
		read_check = read(fd, buf, 1);
		buf[1] = '\0';
	}
	free(buf);
	return (map);
}
