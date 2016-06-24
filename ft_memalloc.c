/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:50:54 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:46:06 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (new)
	{
		ft_bzero(new, size);
		return (new);
	}
	return (NULL);
}
