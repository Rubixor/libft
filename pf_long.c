/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:40:42 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:24:00 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_long(t_variable *v, va_list args, int fd)
{
	__int128	n;
	int			i;

	n = (__int128)(va_arg(args, long));
	i = pf_int_init(v, n, 10, "0123456789");
	if (v->flag.minus)
		return (pf_int_minus(v, n, i, fd));
	else
		return (pf_int_nminus(v, n, i, fd));
}

int		pf_ulong(t_variable *v, va_list args, int fd)
{
	__int128	n;
	int			i;

	v->flag.space = 0;
	v->flag.plus = 0;
	n = (__int128)(va_arg(args, unsigned long));
	if (v->type == 'O' || v->type == 'o')
		i = pf_int_init(v, n, 8, "01234567");
	else if (v->type == 'x' || v->type == 'p')
		i = pf_int_init(v, n, 16, "0123456789abcdef");
	else if (v->type == 'X')
		i = pf_int_init(v, n, 16, "0123456789ABCDEF");
	else
		i = pf_int_init(v, n, 10, "0123456789");
	if (v->flag.minus)
		return (pf_int_minus(v, n, i, fd));
	else
		return (pf_int_nminus(v, n, i, fd));
}
