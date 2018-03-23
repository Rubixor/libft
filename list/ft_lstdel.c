/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:23:02 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/23 03:14:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsuppress(void *content, size_t content_size)
{
	(void)content_size;
	ft_memdel(&content);
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	while (*alst)
	{
		next = (*alst)->next;
		if (del)
			del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = next;
	}
}
