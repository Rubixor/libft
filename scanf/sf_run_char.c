/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:25:14 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/26 15:27:15 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sf_run_char(t_scanf *sf)
{
	const char		*arg = va_arg(*sf->args, const char *);
	unsigned int	len;

	len = ((sf->flags &= SF_FLAG_MAXLEN) ? sf->maxlen : 1);
	while (len && *sf->str && *sf->str == *arg)
	{
		len--;
		sf->str++;
		arg++;
	}
	if (!*arg)
		return (SF_OK);
	return (SF_ERROR);
}
