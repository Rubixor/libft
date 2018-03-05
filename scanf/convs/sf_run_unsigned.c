/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:14:13 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/05 13:48:06 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		sf_uint_len(t_scanf *sf)
{
	unsigned int	i;

	i = 0;
	if (sf->str[i] == '+')
		i++;
	while (ft_isdigit(sf->str[i]))
		i++;
	return (i);
}

int						sf_run_uint(t_scanf *sf)
{
	if (!(sf->flags & SF_FLAG_STAR))
	{
		if (!(ft_isdigit(*sf->str)) && (*sf->str != '+'))
			return (SF_ERROR);
		ft_atonum(sf->str, va_arg(*sf->args, unsigned int *));
		while (ft_isdigit(*sf->str))
			sf->str++;
		return (SF_OK);
	}
	sf->str += sf_uint_len(sf);
	return (SF_OK);
}
