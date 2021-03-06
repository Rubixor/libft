/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcleanc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:55:52 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/31 16:53:01 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strcleanc(char **str, char c)
{
	size_t	i;
	size_t	j;
	size_t	final_len;
	char	*strtmp;

	i = ft_strsub_len((char const *)(*str), c) + 1;
	j = 0;
	final_len = ft_strlen(*str) - i;
	strtmp = NULL;
	if (final_len > 0)
		strtmp = (char *)malloc(sizeof(char) * (final_len + 1));
	if (strtmp)
	{
		while (i < ft_strlen(*str))
		{
			strtmp[j] = (*str)[i];
			i++;
			j++;
		}
		strtmp[j] = '\0';
		if (*str)
			free(*str);
	}
	*str = strtmp;
}
