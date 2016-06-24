/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint128.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:39:22 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/05/14 17:11:48 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putint128(__int128 n)
{
	unsigned __int128 nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = (unsigned __int128)-n;
	}
	else
		nb = (unsigned __int128)n;
	if (nb >= 10)
	{
		ft_putint128(nb / 10);
		ft_putint128(nb % 10);
	}
	else
		ft_putchar((char)nb + '0');
}
