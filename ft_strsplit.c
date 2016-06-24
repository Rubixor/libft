/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 19:49:08 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:50:19 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

static int		ft_count_words(const char *s, char c)
{
	int nb;

	nb = 0;
	while (*s && ++nb)
	{
		while (*s == c)
			s++;
		if (!*s)
			return (nb + 1);
		else
			s++;
	}
	return (nb + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	len;
	int		i;
	char	**tab;

	len = 0;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c)));
	if (tab)
	{
		while (*s)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				len = ft_strsub_len(s, c);
				tab[i++] = ft_strsub(s, 0, len);
				s += len;
			}
		}
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
