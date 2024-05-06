/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long14.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 01:50:54 by acasamit          #+#    #+#             */
/*   Updated: 2023/11/25 03:03:38 by acasamit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/MLX42/mlx42.h"
#include "utils/get_next_line.h"
#include "utils/ft_printf.h"

t_pika	*ft_lstpikalast(t_pika *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstpikaadd_back(t_pika **lst, t_pika *new)
{
	t_pika	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstpikalast(*lst);
	last->next = new;
}

void	ft_lstpikaiter(t_pika *lst, void (*f)(void *, int, t_game *),
		t_game *game)
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->sprite, lst->index, game);
		lst = lst->next;
	}
}

t_rocket	*ft_lstlast(t_rocket *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_rocket **lst, t_rocket *new)
{
	t_rocket	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
