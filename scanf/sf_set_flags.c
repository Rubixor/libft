/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:11:28 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/05 13:02:03 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sf_set_flags(t_scanf *sf)
{
	int		i;

	i = SF_COUNT_MODIFS;
	while (i--)
	{
		if (!(ft_strncmp(sf->format, g_sf_mod[i].mod, g_sf_mod[i].mod_len)))
		{
			sf->flags |= g_sf_mod[i].flag;
			sf->format += g_sf_mod[i].mod_len;
		}
	}
}
