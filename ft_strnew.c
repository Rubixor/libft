/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:51:05 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:49:57 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new)
	{
		ft_bzero(new, (size + 1));
		return (new);
	}
	return (NULL);
}
