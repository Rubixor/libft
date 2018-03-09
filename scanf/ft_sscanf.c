/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:48:21 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/09 18:12:58 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sscanf.h"
#include "libft.h"
#include <stdarg.h>

static void		sf_init(t_scanf *sf, const char *s, const char *format, va_list *args)
{
	sf->args = args;
	sf->str = s;
	sf->str_origin = s;
	sf->format = format;
	sf->format_origin = format;
	sf->flags = 0;
	sf->maxlen = 0;
	sf->precision = 0;
	sf->arg_done = 0;
}

static int		sf_run(t_scanf *sf)
{
	int		i;

	sf->format++;
	if (!*sf->format)
		return(-1);
	i = SF_COUNT_CONVS;
	while (i--)
	{
		if (*sf->format == g_sf_run[i].letter)
		{
			sf_set_maxlen(sf);
			sf_set_flags(sf);
			if (g_sf_run[i].run(sf) == SF_OK)
			{
				sf->arg_done++;
				return (SF_OK);
			}
			break ;
		}
	}
	return (SF_ERROR);
}

static int		sscanf_engine(t_scanf *sf)
{
	while (*sf->format)
	{
		if (*sf->format == '%')
		{
			ft_putendl(sf->format); //
			if (sf_run(sf) == SF_OK)
				sf->format++;
		}
		else if (*sf->str == *sf->format)
		{
			sf->str++;
			sf->format++;
		}
		else
			return (SF_ERROR);
	}
	return (SF_OK);
}

unsigned int	ft_sscanf(const char *s, const char *format, ...)
{
	t_scanf		sf;
	va_list		args;

	sf_init(&sf, s, format, &args);
	va_start(args, format);
	sscanf_engine(&sf);
	va_end(args);
	//ft_putendl(sf.str);
	//ft_putendl(sf.format);
	return (sf.arg_done);
}
