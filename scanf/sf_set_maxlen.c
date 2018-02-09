/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_set_maxlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:59:12 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/09 19:52:16 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sf_set_maxlen(t_scanf *sf)
{
	int		len;

	if ((len = ft_atonum(sf->format, &sf->maxlen)) > 0)
	{
		sf->format += len;
		sf->flags |= SF_FLAG_MAXLEN;
	}
	if (*sf->format == '.')
	{
		sf->format++;
		if ((len = ft_atonum(sf->format, &sf->precision)) > 0)
		{
			sf->format += len;
			sf->flags |= SF_FLAG_PREC;
		}
	}
}
