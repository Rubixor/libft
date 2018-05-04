/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:28:10 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/05/04 17:32:39 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t size)
{
	unsigned char	*dest;

	if (!(dest = (unsigned char *)malloc(size)))
		return (NULL);
	dest = ft_memcpy(dest, src, size);
	return (dest);
}
