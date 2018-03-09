/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:43:20 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/09 15:46:24 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strchrpos(const char *s, int c)
{
	unsigned int	i;
	while (*s)
	{
		if (c == s[i])
			return (i);
		i++;
		s++;
	}
	return (-1);
}
