/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:00:42 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/26 20:59:26 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sf_run_str(t_scanf *sf)
{
	const char		*arg = va_arg(*sf->args, const char *);

	while (*sf->str && *sf->str == *arg)
	{
		sf->str++;
		arg++;
	}
	if (!*arg)
		return (SF_OK);
	return (SF_ERROR);
}
