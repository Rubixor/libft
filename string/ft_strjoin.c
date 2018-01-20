/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:23:48 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:48:50 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new)
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			new[i] = s2[j];
			i++;
			j++;
		}
		new[i] = '\0';
	}
	else
		return (NULL);
	return (new);
}
