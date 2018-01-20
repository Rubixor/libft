/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:51:57 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:50:36 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (sub)
	{
		while (i < len)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		sub[i] = '\0';
	}
	else
		return (NULL);
	return (sub);
}
