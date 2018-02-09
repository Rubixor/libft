/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atonum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:12:15 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/09 19:50:53 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atonum(const char *s, unsigned int *nb)
{
	const char		*s_origin = s;

	while (*s && ft_isdigit(*s))
		*nb = (unsigned int)((*nb * 10) + (unsigned int)(*(s++) - '0'));
	return ((int)(size_t)s - (int)(size_t)s_origin);
}
