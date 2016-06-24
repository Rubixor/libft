/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wintt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:12:52 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:47:45 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <wchar.h>
#include <unistd.h>

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

int			pf_wint_t(t_variable *v, va_list args, int fd)
{
	unsigned int	val;
	int				size;
	unsigned char	octet;
	int				i;
	int				t;

	v->flag.plus = 0;
	v->flag.space = 0;
	i = 0;
	t = 0;
	octet = '\0';
	val = (unsigned int)va_arg(args, wint_t);
	size = ft_size_bin(val);
	if (v->flag.minus)
		t += wt_help(size, val, octet, fd);
	i = v->len - 1;
	while (i-- > 0)
		t += v->flag.zero && !v->flag.minus ?
			ft_putchar_fd('0', fd) : ft_putchar_fd(' ', fd);
	if (!v->flag.minus)
		t += wt_help(size, val, octet, fd);
	return (t);
}
