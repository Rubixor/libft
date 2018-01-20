/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:22:47 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/02/07 17:45:16 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*new;
	unsigned char	*newcontent;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if ((newcontent = (unsigned char *)malloc(content_size)))
		{
			ft_memcpy(newcontent, content, content_size);
			new->content = (void *)newcontent;
		}
		if (content_size)
			new->content_size = content_size;
		else
			new->content_size = 0;
	}
	else
		new->content = NULL;
	new->next = NULL;
	return (new);
}
