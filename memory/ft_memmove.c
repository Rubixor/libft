/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:56:48 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:46:39 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s = src;

	if (dest == src)
		return (dest);
	if (dest < src || dest > (const void *)((size_t)src + n))
		return (ft_memcpy(dest, src, n));
	d = (unsigned char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
