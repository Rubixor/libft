/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:29:15 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/02 17:20:04 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dst;

	i = 0;
	if (!str)
		return (NULL);
	if ((dst = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		while (str[i])
		{
			dst[i] = str[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
