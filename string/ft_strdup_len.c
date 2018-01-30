/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:11:09 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/27 19:07:27 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup_len(const char *str, char c)
{
	unsigned int	i;
	char			*dst;
	size_t			len;

	i = 0;
	len = ft_strsub_len(str, c);
	if (len == 0)
		len = 1;
	dst = (char *)malloc(sizeof(char) * len);
	if (dst)
	{
		while (str[i] && i < len)
		{
			dst[i] = str[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
