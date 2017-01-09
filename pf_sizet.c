/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_sizet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 18:41:44 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:25:43 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>

int		pf_sizet(t_variable *v, va_list args, int fd)
{
	intmax_t	n;
	int			i;

	v->flag.space = 0;
	v->flag.plus = 0;
	n = (size_t)(va_arg(args, unsigned long));
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
