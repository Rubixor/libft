/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:54:12 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/02/25 10:25:36 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstinsert(t_list **last, t_list *item)
{
	if (!*last)
		*last = item;
	else
	{
		item->next = (*last)->next;
		(*last)->next = item;
	}
}
