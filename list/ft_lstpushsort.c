/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:52:40 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/10 16:18:38 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushsort(t_list **lst, t_list *item, int (*cmp)())
{
	t_list *i;
	t_list *last;

	if (!*lst)
		*lst = item;
	else
	{
		i = *lst;
		last = 0;
		while (i && (*cmp)(i->content, item->content) < 0)
		{
			last = i;
			i = i->next;
		}
		if (!last)
			ft_lstadd(lst, item);
		else
			ft_lstinsert(&last, item);
	}
}
