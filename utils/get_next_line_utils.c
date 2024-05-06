/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:49:16 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/07 22:33:32 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

int	is_br(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-42);
}

void	*ft_realloc(char *ptr, size_t size)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(size);
	if (!str)
		return (NULL);
	while (ptr[++i])
		str[i] = ptr[i];
	str[i] = '\0';
	free(ptr);
	return (str);
}

char	*line_selector(char *line, char *buf, int fd, ssize_t read_check)
{
	while (is_br(line) == -42)
	{
		line = ft_realloc(line, ft_strlen(line) + BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(line);
			buf[0] = '\0';
			return (NULL);
		}
		if (read_check < BUFFER_SIZE)
			return (is_empty(line, buf, read_check));
		line = ft_strcat(line, buf);
	}
	line[is_br(line) + 1] = '\0';
	supprimer_n_premiers(buf, is_br(buf) + 1);
	return (line);
}
