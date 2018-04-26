/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:06:36 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/04/26 16:04:06 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		base_conv(const char *str, const char *map,
	unsigned int base, long long int *dest)
{
	const char		*str_origin = str;
	long long int	c;

	*dest = 0;
	while ((c = ft_strchrpos(map, *str)) >= 0)
	{
		*dest = *dest * base + c;
		str++;
	}
	return ((unsigned int)((size_t)str - (size_t)str_origin));
}

int						sf_run_hex(t_scanf *sf)
{
	long long int	val;

	sf->str += base_conv(sf->str, "0123456789ABCDEF", 16, &val);
	if (!(sf->flags & SF_FLAG_STAR))
		*va_arg(*sf->args, unsigned int *) = (unsigned int)val;
	return (SF_OK);
}
