/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:03:21 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:46:20 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*w1 = s1;
	const unsigned char	*w2 = s2;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (w1[i] != w2[i])
			return (w1[i] - w2[i]);
		i++;
	}
	return (0);
}
