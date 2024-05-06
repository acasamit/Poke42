/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:23:57 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/09 00:55:56 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		is_br(char *str);
void	*ft_realloc(char *ptr, size_t size);
char	*is_empty(char *line, char *buf, ssize_t read_check);
void	supprimer_n_premiers(char *chaine, int n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strcat(char *dest, char *src);
char	*line_selector(char *line, char *buf, int fd, ssize_t read_check);

#endif
