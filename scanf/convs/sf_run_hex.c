/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:06:36 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/09 16:18:36 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		base_conv(const char *str, const char *map,
	unsigned int base, __intmax_t *dest)
{
	const char	*str_origin = str;
	__intmax_t	c;

	*dest = 0;
	while ((c = ft_strchrpos(map, *str)) >= 0)
	{
		*dest = *dest * base + c;
		str++;
	}
	return ((unsigned int)str - (unsigned int)str_origin);
}

int						sf_run_hex(t_scanf *sf)
{
	__intmax_t	val;

	sf->str += base_conv(sf->str, "0123456789ABCDEF", 16, &val);
	if (!(sf->flags & SF_FLAG_STAR))
		*va_arg(*sf->args, unsigned int *) = (unsigned int)val;
	return (SF_OK);
}
