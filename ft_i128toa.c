/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i128toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 15:35:37 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/01/19 22:40:41 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int		ft_i128toa_len(__int128 n, unsigned int base)
{
	unsigned int 	len;

	len = 1;
	if (n < 0)
		len++;
	while (n && (n /= base))
		len++;
	return (len);
}

char					*ft_i128toa(__int128 n, unsigned int base, char *map)
{
	char				*buf;
	unsigned int		i;
	unsigned int		len;

	if (base > ft_strlen(map))
		return (NULL);
	len = ft_i128toa_len(n, base);
	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = len;
	buf[i--] = '\0';
	if (n < 0)
	{
		buf[0] = '-';
		n *= -1;
	}
	else if (n == 0)
		buf[i] = map[0];
	while (n)
	{
		buf[i--] = map[n % base];
		n /= (int)base;
	}
	return (buf);
}
