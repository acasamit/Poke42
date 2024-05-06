/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:45:20 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/07 22:33:57 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dest == src)
		return (dest);
	else if (dest < src)
	{
		while (++i < n)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	}
	else if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}

void	supprimer_n_premiers(char *chaine, int n)
{
	int	len;

	len = ft_strlen(chaine);
	if (n > 0 && n < len)
	{
		ft_memmove(chaine, chaine + n, len - n + 1);
		chaine[len - n + 1] = '\0';
	}
	else if (n >= len)
		chaine[0] = '\0';
}

char	*is_empty(char *line, char *buf, ssize_t read_check)
{
	if (buf[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	if (read_check == 0)
	{
		buf[0] = '\0';
		return (line);
	}
	else
		buf[read_check] = '\0';
	line = ft_strcat(line, buf);
	if (is_br(line) != -42)
	{
		line[is_br(line) + 1] = '\0';
		supprimer_n_premiers(buf, is_br(buf) + 1);
	}
	else
		buf[0] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	char		*line;
	ssize_t		read_check;

	if (buf[0] == '\0')
	{
		read_check = read(fd, buf, BUFFER_SIZE);
		if (read_check == -1)
			return (NULL);
		buf[read_check] = '\0';
		if (read_check == 0)
			return (NULL);
	}
	line = ft_strdup(buf);
	if (!line)
		return (NULL);
	return (line_selector(line, buf, fd, read_check));
}

/*int main(void)
{
	int	fd;
	int	i;

	i = -1;
	fd = open("read_error.txt", O_RDONLY);
	while (++i < 12)
		printf("%s", get_next_line(fd));
	return (0);
}*/
