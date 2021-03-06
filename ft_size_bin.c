/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:15:29 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/29 16:57:53 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t		ft_size_bin(long long n)
{
	size_t		i;
	char		*s;

	s = ft_i128toa(n, 2, "01");
	i = ft_strlen(s);
	free(s);
	return (i);
}
