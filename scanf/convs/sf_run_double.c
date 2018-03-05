/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:38:11 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/05 17:44:41 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		sf_run_double(t_scanf *sf)
{
	if (!(sf->flags & SF_FLAG_STAR))
	{
		*va_arg(*sf->args, double *) = ft_atod(sf->str);
		/*while (ft_isdigit(*sf->str))
			sf->str++;
		if (*sf->str == '.')
			sf->str++;
		while (ft_isdigit(*sf->str))
			sf->str++;*/
		return (SF_OK);
	}
	//sf->str += len;
	return (SF_OK);
}
