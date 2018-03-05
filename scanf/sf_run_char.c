/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sf_run_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:25:14 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/05 13:02:09 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sf_run_char(t_scanf *sf)
{
	char			*arg;
	unsigned int	maxlen;
	size_t			len;

	arg = va_arg(*sf->args, char *);
	maxlen = ((sf->flags & SF_FLAG_MAXLEN) ? sf->maxlen : 1);
	len = ft_strplen(sf->str, &sf->str[maxlen]);
	ft_strncpy(arg, sf->str, len);
	return (SF_OK);
}
