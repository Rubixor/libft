/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:46:45 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 20:03:28 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

static int			pf_process(const char *str, va_list args, int fd)
{
	t_variable	*var;
	t_variable	*tmp;
	char		*s;

	var = NULL;
	if (!(s = ft_strdup(str)))
		return (0);
	while (*s && s)
	{
		if (ft_strchr(s, '%'))
		{
			s = ft_strchr(s, '%') + 1;
			tmp = pf_newvar(&var);
			s += pf_check_flags(s, tmp);
			s += pf_check_len(s, tmp);
			s += pf_check_prec(s, tmp);
			s += pf_check_modif(s, tmp);
			s += pf_check_flags(s, tmp);
			tmp->type = *s;
		}
		else
			return (pf_display(str, var, args, fd));
		s++;
	}
	return (pf_display(str, var, args, fd));
}

int					ft_printf(const char *format, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, format);
	total = pf_process(format, args, 1);
	va_end(args);
	return (total);
}

int					ft_printf_fd(int fd, const char *format, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, format);
	total = pf_process(format, args, fd);
	va_end(args);
	return (total);
}
