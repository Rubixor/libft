/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:48:21 by mdenoyel          #+#    #+#             */
/*   Updated: 2017/06/12 16:04:29 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sscanf.h"
#include <stdarg.h>

int		ft_sscanf_engine(t_scanf *sf, const char *format)
{
	(void)sf;
	return (0);
}

int		ft_sscanf(const char *s, const char *format, ...)
{
	t_scanf		sf;
	va_list		args;

	sf.args = &args;
	sf.str = s;
	sf.str_origin = s;
	va_start(args, format);
	ft_sscanf_engine(&sf, format);
	va_end(args);
	return (0);
}
