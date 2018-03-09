/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:14:13 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/09 14:47:36 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		uint_len(t_scanf *sf)
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
	unsigned int	*arg;

	arg = NULL;
	if (!(sf->flags & SF_FLAG_STAR))
	{
		arg = va_arg(*sf->args, unsigned int *);
		if (!(ft_isdigit(*sf->str)) && (*sf->str != '+'))
			return (SF_ERROR);
		sf->str += ft_atonum(sf->str, arg);
		return (SF_OK);
	}
	sf->str += uint_len(sf);
	return (SF_OK);
}
