/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:48:21 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/09 19:05:46 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sscanf.h"
#include "libft.h"
#include <stdarg.h>

static int		sf_run(t_scanf *sf)
{
	int		i;

	i = SF_COUNT_CONVS;
	sf->format++;
	if (!*sf->format)
		return(-1);
	sf_set_maxlen(sf);
	sf_set_flags(sf);
	while (i--)
	{
		if (*sf->format == g_sf_run[i].letter)
		{
			g_sf_run[i].run(sf);
			return (1);
		}
	}
	return (0); //
}

static int		sscanf_engine(t_scanf *sf)
{
	while (*sf->str)
	{
		if (*sf->format == '%')
			sf->format += sf_run(sf);
		else if (*sf->str == *sf->format)
		{
			sf->str++;
			sf->format++;
		}
		else
			return (1);
	}
	return (0); //
}

int				ft_sscanf(const char *s, const char *format, ...)
{
	t_scanf		sf;
	va_list		args;

	sf.args = &args;
	sf.str = s;
	sf.str_origin = s;
	sf.format = format;
	sf.format_origin = format;
	sf.flags = 0;
	sf.maxlen = 0;
	sf.precision = 0;
	va_start(args, format);
	sscanf_engine(&sf);
	va_end(args);
	//ft_putendl(sf.str);
	//ft_putendl(sf.format);
	return (0);
}
