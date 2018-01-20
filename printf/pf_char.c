/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:30:57 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:17:46 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		pf_char(t_variable *v, va_list args, int fd)
{
	int		i;
	char	c;
	int		t;

	c = (char)va_arg(args, int);
	t = 0;
	if (v->flag.minus)
		t += ft_putchar_fd(c, fd);
	i = v->len - 1;
	while (i-- > 0)
		t += v->flag.zero && !v->flag.minus ?
			ft_putchar_fd('0', fd) : ft_putchar_fd(' ', fd);
	if (!v->flag.minus)
		t += ft_putchar_fd(c, fd);
	return (t);
}

int		pf_schar(t_variable *v, va_list args, int fd)
{
	signed char	n;
	int			i;

	n = (signed char)(va_arg(args, int));
	i = pf_int_init(v, (__int128)n, 10, "0123456789");
	if (v->flag.minus)
		return (pf_int_minus(v, (__int128)n, i, fd));
	else
		return (pf_int_nminus(v, (__int128)n, i, fd));
}

int		pf_uchar(t_variable *v, va_list args, int fd)
{
	unsigned char	n;
	int				i;

	v->flag.space = 0;
	v->flag.plus = 0;
	n = (unsigned char)(va_arg(args, unsigned int));
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
