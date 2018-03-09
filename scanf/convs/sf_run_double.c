/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:38:11 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/09 14:47:35 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	double_len(t_scanf *sf)
{
	size_t		len;

	len = 0;
	while (ft_isdigit(sf->str[len]))
		len++;
	if (sf->str[len] == '.')
		len++;
	while (ft_isdigit(sf->str[len]))
		len++;
	return (len);
}

int				sf_run_double(t_scanf *sf)
{
	if (!(sf->flags & SF_FLAG_STAR))
		*va_arg(*sf->args, double *) = ft_atod(sf->str);
	sf->str += double_len(sf);
	return (SF_OK);
}
