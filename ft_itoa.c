/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:46:02 by mdenoyel          #+#    #+#             */
/*   Updated: 2017/04/11 14:42:19 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char			*a;
	int				i;
	unsigned int	nb;

	a = (char *)malloc(sizeof(char) * 12);
	i = 0;
	if (!a)
		return (NULL);
	if (n < 0)
		nb = (unsigned int)(-n);
	else
		nb = (unsigned int)n;
	while (i == 0 || nb)
	{
		a[i++] = '0' + (nb % 10);
		nb /= 10;
	}
	if (n < 0)
		a[i++] = '-';
	a[i] = '\0';
	ft_strrev(a);
	return (a);
}
