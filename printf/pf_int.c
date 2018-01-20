/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 20:11:35 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:16:13 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

int		pf_int(t_variable *v, va_list args, int fd)
{
	__int128	n;
	int			i;

	n = (__int128)(va_arg(args, int));
	i = pf_int_init(v, n, 10, "0123456789");
	if (v->flag.minus)
		return (pf_int_minus(v, n, i, fd));
	else
		return (pf_int_nminus(v, n, i, fd));
}

int		pf_uint(t_variable *v, va_list args, int fd)
{
	__int128	n;
	int			i;

	v->flag.space = 0;
	v->flag.plus = 0;
	n = (__int128)(va_arg(args, unsigned int));
	if (v->type == 'O' || v->type == 'o')
		i = pf_int_init(v, n, 8, "01234567");
	else if (v->type == 'x')
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

int		pf_uint32(t_variable *v, va_list args, int fd)
{
	intmax_t	n;
	int			i;

	v->flag.space = 0;
	v->flag.plus = 0;
	n = (intmax_t)(va_arg(args, uint32_t));
	if (v->type == 'O' || v->type == 'o')
		i = pf_int_init(v, (__int128)n, 8, "01234567");
	else if (v->type == 'x')
		i = pf_int_init(v, (__int128)n, 16, "0123456789abcdef");
	else if (v->type == 'X')
		i = pf_int_init(v, (__int128)n, 16, "0123456789ABCDEF");
	else
		i = pf_int_init(v, (__int128)n, 10, "0123456789");
	if (v->flag.minus)
		return (pf_int_minus(v, (__int128)n, i, fd));
	else
		return (pf_int_nminus(v, (__int128)n, i, fd));
}

int		pf_uint64(t_variable *v, va_list args, int fd)
{
	intmax_t	n;
	int			i;

	v->flag.space = 0;
	v->flag.plus = 0;
	n = (intmax_t)(va_arg(args, uint64_t));
	if (v->type == 'O' || v->type == 'o')
		i = pf_int_init(v, (__int128)n, 8, "01234567");
	else if (v->type == 'x')
		i = pf_int_init(v, (__int128)n, 16, "0123456789abcdef");
	else if (v->type == 'X')
		i = pf_int_init(v, (__int128)n, 16, "0123456789ABCDEF");
	else
		i = pf_int_init(v, (__int128)n, 10, "0123456789");
	if (v->flag.minus)
		return (pf_int_minus(v, (__int128)n, i, fd));
	else
		return (pf_int_nminus(v, (__int128)n, i, fd));
}
