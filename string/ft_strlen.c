/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:46:51 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/28 23:15:15 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	const char	*origin = str;

	while (*str)
		str++;
	return ((size_t)str - (size_t)origin);
}

size_t		ft_strplen(const char *str, const char *max)
{
	const char	*origin = str;

	while ((*str) && (str < max))
		str++;
	return ((size_t)str - (size_t)origin);
}
