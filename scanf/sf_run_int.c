/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:03:14 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/28 22:54:37 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		sf_int_len(t_scanf *sf)
{
	unsigned int	i;

	i = 0;
	if ((sf->str[i] == '+') || (sf->str[i] == '-'))
		i++;
	while (ft_isdigit(sf->str[i]))
		i++;
	return (i);
}

int						sf_run_int(t_scanf *sf)
{
	if (!(sf->flags & SF_FLAG_STAR))
	{
		if (!(ft_isdigit(*sf->str)) && !(ft_strchr("+-", *sf->str)))
			return (SF_ERROR);
		if (sf->flags & SF_FLAG_HH)
			*va_arg(*sf->args, char *) = (char)ft_atoi(sf->str);
		else if (sf->flags & SF_FLAG_H)
			*va_arg(*sf->args, short *) = (short)ft_atoi(sf->str);
		else
			*va_arg(*sf->args, int *) = ft_atoi(sf->str);
		while (ft_isdigit(*sf->str))
			sf->str++;
		return (SF_OK);
	}
	sf->str += sf_int_len(sf);
	return (SF_OK);
}
