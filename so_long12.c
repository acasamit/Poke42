/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:17:21 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 01:17:33 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

void	ft_lstdelone(t_rocket *lst, void (*del)(void *, void *), t_game *game)
{
	if (!lst)
		return ;
	del(game, lst->sprite);
	free(lst);
}

void	ft_lstpikadelone(t_pika *lst, void (*del)(void *, void *), t_game *game)
{
	if (!lst)
		return ;
	del(game, lst->sprite);
	free(lst);
}

void	ft_lstpikaclear(t_pika **lst, void (*del)(void *, void *), t_game *game)
{
	t_pika	*current;
	t_pika	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstpikadelone(current, del, game);
		current = next;
	}
	*lst = NULL;
}

void	ft_lstclear(t_rocket **lst, void (*del)(void *, void *), t_game *game)
{
	t_rocket	*current;
	t_rocket	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del, game);
		current = next;
	}
	*lst = NULL;
}

int	lenn(int _n)
{
	int		len;
	long	n;

	n = _n;
	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}
