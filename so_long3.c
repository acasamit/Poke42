/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:06:13 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 01:09:23 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

char	*ft_strndup(const char *s, int n)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_wordcount(const char *s, char c)
{
	int	i;
	int	len;
	int	words;

	i = 0;
	len = 0;
	words = 0;
	while (s[i])
	{
		if (ft_is_delimiter(s[i], c))
			i++;
		else
		{
			len = ft_strlen_mod(s + i, c);
			words++;
			i += len;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**words;
	int		k;
	int		len;

	i = 0;
	k = 0;
	len = 0;
	words = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (s[i])
	{
		if (ft_is_delimiter(s[i], c))
			i++;
		else
		{
			len = ft_strlen_mod(s + i, c);
			words[k++] = ft_strndup(s + i, len);
			i += len;
		}
	}
	words[k] = NULL;
	return (words);
}

int	check_border_and_format(char *map, int numberoflines, t_game *game)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 1] != 'r' || map[i - 2] != 'e' || map[i - 3] != 'b' || map[i
			- 4] != '.')
		return (0);
	i = -1;
	while (game->map->map_file[++i])
	{
		if (game->map->map_file[i] == 'P')
			game->n_player += 1;
		if (game->map->map_file[i] == 'E')
			game->n_exit += 1;
		if (game->map->map_file[i] == 'C')
			game->n_pika += 1;
		if (first_occurence("01PSERC\n", game->map->map_file[i]) == -42)
			return (0);
	}
	while (numberoflines-- > 1)
	{
		if (ft_strlen(game->map->map_tab[numberoflines])
			!= ft_strlen(game->map->map_tab[numberoflines - 1]))
			return (0);
	}
	return (1);
}

void	clean_map(char **map, int numberoflines)
{
	int	i;
	int	j;

	i = 0;
	while (i < numberoflines)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			map[i][j] &= 0b01111111;
			j++;
		}
		i++;
	}
}
