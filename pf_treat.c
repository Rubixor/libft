/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:44:56 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:43:24 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include "libft.h"

static int	cast_signed(t_variable *v, va_list args, int fd)
{
	pf_collect_len(v, args);
	pf_collect_prec(v, args);
	if (v->type == 'D')
		return (pf_uint64(v, args, fd));
	if (ft_strcmp(v->modif, "l") == 0)
		return (pf_long(v, args, fd));
	if (ft_strcmp(v->modif, "ll") == 0)
		return (pf_longlong(v, args, fd));
	if (v->modif[0] == 'j')
		return (pf_intmaxt(v, args, fd));
	if (ft_strcmp(v->modif, "h") == 0)
		return (pf_short(v, args, fd));
	if (ft_strcmp(v->modif, "hh") == 0)
		return (pf_schar(v, args, fd));
	if (ft_strcmp(v->modif, "z") == 0)
		return (pf_sizet(v, args, fd));
	return (pf_int(v, args, fd));
}

static int	cast_unsigned(t_variable *v, va_list args, int fd)
{
	pf_collect_len(v, args);
	pf_collect_prec(v, args);
	if (v->type == 'o' && v->modif[0] == '\0')
		return (pf_uint32(v, args, fd));
	if (ft_strcmp(v->modif, "l") == 0 || v->type == 'U' || v->type == 'O')
		return (pf_ulong(v, args, fd));
	if (ft_strcmp(v->modif, "ll") == 0)
		return (pf_ulonglong(v, args, fd));
	if (ft_strcmp(v->modif, "h") == 0)
		return (pf_ushort(v, args, fd));
	if (ft_strcmp(v->modif, "hh") == 0)
		return (pf_uchar(v, args, fd));
	if (v->modif[0] == 'j')
		return (pf_uintmaxt(v, args, fd));
	if (ft_strcmp(v->modif, "z") == 0)
		return (pf_ulonglong(v, args, fd));
	return (pf_uint(v, args, fd));
}

static int	other_type(t_variable *v, va_list args, int fd)
{
	int i;

	pf_collect_len(v, args);
	pf_collect_prec(v, args);
	i = v->len - 1;
	if (v->flag.minus)
		ft_putchar_fd(v->type, fd);
	while (i-- > 0)
		v->flag.zero && !v->flag.minus ?
			ft_putchar_fd('0', fd) : ft_putchar_fd(' ', fd);
	if (!v->flag.minus)
		ft_putchar_fd(v->type, fd);
	return (v->len > 0 ? v->len : 1);
}

static int	cast_string(t_variable *v, va_list args, int fd)
{
	pf_collect_len(v, args);
	pf_collect_prec(v, args);
	if (v->type == 'S' || (v->type == 's' && ft_strcmp(v->modif, "l") == 0))
		return (pf_wchar_t(v, args, fd));
	if (v->type == 's')
		return (pf_string(v, args, fd));
	if (v->type == 'C' || (v->type == 'c' && ft_strcmp(v->modif, "l") == 0))
		return (pf_wint_t(v, args, fd));
	if (v->type == 'c')
		return (pf_char(v, args, fd));
	if (v->type == 'p')
	{
		v->flag.hash = 1;
		return (pf_ulong(v, args, fd));
	}
	return (other_type(v, args, fd));
}

int			pf_treat(t_variable *v, va_list args, int fd)
{
	const char	*csigned = "dDi";
	const char	*cunsigned = "oOuUxX";
	const char	*cstring = "cCsSp";

	if (v->flag.space == 1 && v->flag.plus == 1)
		v->flag.space = 0;
	if (v->flag.zero == 1 && v->flag.minus == 1)
		v->flag.zero = 0;
	if (v->type == '\x00')
		return (0);
	if (ft_strchr(csigned, v->type))
		return (cast_signed(v, args, fd));
	if (ft_strchr(cunsigned, v->type))
		return (cast_unsigned(v, args, fd));
	if (ft_strchr(cstring, v->type))
		return (cast_string(v, args, fd));
	return (other_type(v, args, fd));
}
