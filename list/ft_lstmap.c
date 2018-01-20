/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:07:01 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:45:52 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *cpy;

	cpy = lst;
	new = NULL;
	while (cpy)
	{
		ft_lst_pushback(&new, f(cpy));
		cpy = cpy->next;
	}
	return (new);
}
