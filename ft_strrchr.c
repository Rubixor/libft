/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:46:18 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:50:10 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char *)s);
	if (c == '\0')
		return ((char *)s + i);
	while (s[--i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
