/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wchart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 16:36:45 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:46:33 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <wchar.h>

static int	wchar_t_11(unsigned int val, int mask, unsigned char octet, int fd)
{
	unsigned char	o1;
	unsigned char	o2;
	int				i;

	i = 0;
	o2 = (val << 26) >> 26;
	o1 = ((val >> 6) << 27) >> 27;
	octet = (mask >> 8) | o1;
	i += write(fd, &octet, 1);
	octet = (mask << 24) >> 24 | o2;
	i += write(fd, &octet, 1);
	return (i);
}

static int	wchar_t_16(unsigned int val, int mask, unsigned char octet, int fd)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	int				i;

	i = 0;
	o3 = (val << 26) >> 26;
	o2 = ((val >> 6) << 26) >> 26;
	o1 = ((val >> 12) << 28) >> 28;
	octet = (mask >> 16) | o1;
	i += write(fd, &octet, 1);
	octet = ((mask << 16) >> 24) | o2;
	i += write(fd, &octet, 1);
	octet = ((mask << 24) >> 24) | o3;
	i += write(fd, &octet, 1);
	return (i);
}

static int	wchar_t_other(unsigned int val, int mask, unsigned char oc, int fd)
{
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;
	int				i;

	i = 0;
	o4 = (val << 26) >> 26;
	o3 = ((val >> 6) << 26) >> 26;
	o2 = ((val >> 12) << 26) >> 26;
	o1 = ((val >> 18) << 29) >> 29;
	oc = (mask >> 24) | o1;
	i += write(fd, &oc, 1);
	oc = ((mask << 8) >> 24) | o2;
	i += write(fd, &oc, 1);
	oc = ((mask << 16) >> 24) | o3;
	i += write(fd, &oc, 1);
	oc = ((mask << 24) >> 24) | o4;
	i += write(fd, &oc, 1);
	return (i);
}

static int	wt_help(int size, unsigned int val, unsigned char octet, int fd)
{
	if (size <= 7)
		return (write(fd, &val, 1));
	else if (size <= 11)
		return (wchar_t_11(val, 49280, octet, fd));
	else if (size <= 16)
		return (wchar_t_16(val, 14712960, octet, fd));
	else
		return (wchar_t_other(val, 4034953344, octet, fd));
}

int			pf_wchar_t(t_variable *v, va_list args, int f)
{
	int				i;
	wchar_t			*c;
	int				t;
	unsigned char	octet;
	int				len;

	t = 0;
	i = v->prec;
	octet = '\0';
	if (!(c = va_arg(args, wchar_t *)))
		return (write(f, "(null)", (v->prec < 0 || v->prec > 6) ? 6 : v->prec));
	len = ft_wcslen(c);
	c--;
	if (v->flag.minus)
		while (c++ && i-- && *c)
			t += wt_help(ft_size_bin(*c), *c, octet, f);
	i = v->len - (v->prec >= 0 && v->prec < len ? v->prec : len);
	while (i-- > 0)
		t += v->flag.zero && !v->flag.minus ?
			ft_putchar_fd('0', f) : ft_putchar_fd(' ', f);
	if (!v->flag.minus)
		while (c++ && v->prec-- && *c)
			t += wt_help(ft_size_bin(*c), *c, octet, f);
	return (t);
}
