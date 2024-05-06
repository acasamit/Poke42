/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:00:45 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/28 02:46:29 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

int	is_there_a_collectible_path(char **map, int i, int j)
{
	if (map[i][j] == 'C')
		return (1);
	map[i][j] |= 0b10000000;
	if ((map[i][j + 1] != '1' && map[i][j + 1] != 'S' && map[i][j + 1] != 'E'
			&& !(map[i][j + 1] & 0b10000000))
		&& is_there_a_collectible_path(map, i, j + 1))
		return (1);
	else if ((map[i][j - 1] != '1' && map[i][j - 1] != 'S' && map[i][j
				- 1] != 'E' && !(map[i][j - 1] & 0b10000000))
			&& is_there_a_collectible_path(map, i, j - 1))
		return (1);
	else if ((map[i + 1][j] != '1' && map[i + 1][j] != 'S' && map[i
				+ 1][j] != 'E' && !(map[i + 1][j] & 0b10000000))
			&& is_there_a_collectible_path(map, i + 1, j))
		return (1);
	else if ((map[i - 1][j] != '1' && map[i - 1][j] != 'S' && map[i
				- 1][j] != 'E' && !(map[i - 1][j] & 0b10000000))
			&& is_there_a_collectible_path(map, i - 1, j))
		return (1);
	else
		return (0);
}

int	is_there_a_path(char **map, int i, int j)
{
	if (map[i][j] == 'E')
		return (1);
	map[i][j] |= 0b10000000;
	if ((map[i][j + 1] != '1' && map[i][j + 1] != 'S' && !(map[i][j
				+ 1] & 0b10000000)) && is_there_a_path(map, i, j + 1))
		return (1);
	else if ((map[i][j - 1] != '1' && map[i][j - 1] != 'S' && !(map[i][j
					- 1] & 0b10000000)) && is_there_a_path(map, i, j - 1))
		return (1);
	else if ((map[i + 1][j] != '1' && map[i + 1][j] != 'S' && !(map[i
					+ 1][j] & 0b10000000)) && is_there_a_path(map, i + 1, j))
		return (1);
	else if ((map[i - 1][j] != '1' && map[i - 1][j] != 'S' && !(map[i
					- 1][j] & 0b10000000)) && is_there_a_path(map, i - 1, j))
		return (1);
	else
		return (0);
}

int	is_map_achievable(char **map, int numberoflines, t_game *game)
{
	int	i;
	int	j;

	if (!check_border_and_format(game->map->map_path, numberoflines, game))
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (!is_there_a_path(map, i, j))
					return (0);
				clean_map(map, numberoflines);
				if (!is_there_a_collectible_path(map, i, j))
					return (0);
				clean_map(map, numberoflines);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	map_is_sourrounded(char **map, int n_line)
{
	int	i;

	i = -1;
	while (map[0][++i])
	{
		if (map[0][i] != '1')
			return (0);
	}
	i = -1;
	while (map[n_line - 1][++i])
	{
		if (map[n_line - 1][i] != '1')
			return (0);
	}
	while (--n_line != 0)
	{
		if (map[n_line][0] != '1')
			return (0);
		if (map[n_line][ft_strlen(map[n_line]) - 1] != '1')
			return (0);
	}
	return (1);
}

void	game_init(t_game *game)
{
	game->menu = calloc(sizeof(t_menu), 1);
	game->open_anim = calloc(sizeof(t_open_fight), 1);
	game->map = calloc(sizeof(t_map), 1);
	game->fight = calloc(sizeof(t_fight), 1);
	game->wait_moove = 0;
	game->player_img = NULL;
	game->moove_num = -1;
	game->fight->sprite_path[0] = "sprites/fight/menu/fight.png";
	game->fight->sprite_path[1] = "sprites/fight/menu/pkmn.png";
	game->fight->sprite_path[2] = "sprites/fight/menu/item.png";
	game->fight->sprite_path[3] = "sprites/fight/menu/run.png";
	game->fight->qpp = 30;
	game->fight->tpp = 30;
	game->fight->php = 42;
	game->fight->ehp = 42;
	game->zero.x = 0;
	game->zero.y = 0;
	game->n_pika = 0;
	game->n_exit = 0;
	game->n_player = 0;
	game->line_readed = 0;
}
