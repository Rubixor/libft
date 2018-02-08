/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 23:10:56 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/07 19:17:33 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSCANF_H
# define FT_SSCANF_H

# include <stdarg.h>

typedef struct		s_scanf
{
	va_list			*args;
	const char		*str;
	const char		*str_origin;
	const char		*format;
}					t_scanf;

int					sf_run_int(t_scanf *sf);
int					sf_run_str(t_scanf *sf);

void				sf_set_flags(t_scanf *sf);

typedef struct		s_scanf_run
{
	int				letter;
	int				flags;
	int				(*run)(t_scanf *);
}					t_scanf_run;

# define SF_COUNT_CONVS 1

static const t_scanf_run g_sf_run[SF_COUNT_CONVS] = {
	(t_scanf_run){'d', 0, &sf_run_int},
	(t_scanf_run){'s', 0, &sf_run_str}
};

int					ft_sscanf(const char *s, const char *format, ...);

#endif
