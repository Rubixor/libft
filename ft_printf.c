/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 10:46:45 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/28 21:43:14 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

static char			*pf_process_format(char *s, t_variable **var)
{
	t_variable		*tmp;

	tmp = pf_newvar();
	pf_var_pushback(var, tmp);
	s += pf_check_flags(s, tmp);
	s += pf_check_len(s, tmp);
	s += pf_check_prec(s, tmp);
	s += pf_check_modif(s, tmp);
	s += pf_check_flags(s, tmp);
	tmp->type = *s;
	return (s);
}

static int			pf_process(const char *str, va_list args, int fd,
		t_variable **var)
{
	char		*s;
	char		*s_origin;

	if (!(s = ft_strdup(str)))
		return (0);
	s_origin = s;
	while (*s && s)
	{
		if ((s = ft_strchr(s, '%')))
		{
			s++;
			s = pf_process_format(s, var);
		}
		else
		{
			free(s_origin);
			return (pf_display(str, *var, args, fd));
		}
		s++;
	}
	free(s_origin);
	return (pf_display(str, *var, args, fd));
}

static void			ft_printf_clean(t_variable *var)
{
	if (!var)
		return ;
	if (var->next)
		ft_printf_clean(var->next);
	if (var->modif)
		free(var->modif);
	if (var->arg)
		free(var->arg);
	free(var);
}

int					ft_printf(const char *format, ...)
{
	int			total;
	va_list		args;
	t_variable	*var;

	var = NULL;
	total = 0;
	va_start(args, format);
	total = pf_process(format, args, 1, &var);
	va_end(args);
	ft_printf_clean(var);
	return (total);
}

int					ft_printf_fd(int fd, const char *format, ...)
{
	int			total;
	va_list		args;
	t_variable	*var;

	var = NULL;
	total = 0;
	va_start(args, format);
	total = pf_process(format, args, fd, &var);
	va_end(args);
	ft_printf_clean(var);
	return (total);
}
