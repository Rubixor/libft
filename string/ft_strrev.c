/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 18:59:39 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/01/18 17:50:15 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		ft_swap((void *)&str[i], (void *)&str[len]);
		i++;
		len--;
	}
	return (str);
}
