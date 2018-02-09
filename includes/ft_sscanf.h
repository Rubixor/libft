/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 23:10:56 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/02/09 19:36:10 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSCANF_H
# define FT_SSCANF_H

# include <stdarg.h>
# include <stdlib.h>

# define SF_FLAG_LL		(1u << 0)
# define SF_FLAG_L		(1u << 1)
# define SF_FLAG_HH		(1u << 2)
# define SF_FLAG_H		(1u << 3)
# define SF_FLAG_Z		(1u << 4)
# define SF_FLAG_J		(1u << 5)
# define SF_FLAG_STAR	(1u << 6)

# define SF_FLAG_MAXLEN	(1u << 8)
# define SF_FLAG_PREC	(1u << 9)

typedef struct		s_scanf
{
	va_list			*args;
	const char		*str;
	const char		*str_origin;
	const char		*format;
	const char		*format_origin;
	unsigned int	flags;
	unsigned int	padding;
	unsigned int	maxlen;
	unsigned int	precision;
}					t_scanf;

int					sf_run_int(t_scanf *sf);
int					sf_run_str(t_scanf *sf);

void				sf_set_flags(t_scanf *sf);
void				sf_set_maxlen(t_scanf *sf);

typedef struct		s_scanf_run
{
	int				letter;
	unsigned int	flags;
	int				(*run)(t_scanf *);
}					t_scanf_run;

# define SF_COUNT_CONVS 2

static const t_scanf_run g_sf_run[SF_COUNT_CONVS] = {
	(t_scanf_run){'d', 0, &sf_run_int},
	(t_scanf_run){'s', 0, &sf_run_str}
};

typedef struct		s_scanf_modif
{
	const char		*mod;
	size_t			mod_len;
	unsigned int	flag;
	unsigned int	padding;
}					t_scanf_modif;

# define SF_COUNT_MODIFS 7

static const t_scanf_modif g_sf_mod[SF_COUNT_MODIFS] = {
	(t_scanf_modif){"j", 1, SF_FLAG_J, 0},
	(t_scanf_modif){"z", 1, SF_FLAG_Z, 0},
	(t_scanf_modif){"h", 1, SF_FLAG_HH, 0},
	(t_scanf_modif){"hh", 2, SF_FLAG_HH, 0},
	(t_scanf_modif){"l", 1, SF_FLAG_L, 0},
	(t_scanf_modif){"ll", 2, SF_FLAG_LL, 0},
	(t_scanf_modif){"*", 1, SF_FLAG_STAR, 0}
};

int					ft_sscanf(const char *s, const char *format, ...);

#endif
