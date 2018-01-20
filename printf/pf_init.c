/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 17:31:31 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:22:15 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	pf_hash(t_variable *v, __int128 n, int fd)
{
	int		tot;

	tot = 0;
	if (n != 0 || v->type == 'p')
	{
		if (v->type == 'x' || v->type == 'p')
			tot += ft_putstr_fd("0x", fd);
		if (v->type == 'X')
			tot += ft_putstr_fd("0X", fd);
		if (v->type == 'o' || v->type == 'O')
			tot += ft_putchar_fd('0', fd);
	}
	if ((v->type == 'o' || v->type == 'O') && (n == 0 && v->prec >= 0))
		tot += ft_putchar_fd('0', fd);
	return (tot);
}

int			pf_int_init(t_variable *v, __int128 n, int base, char *map)
{
	int i;

	v->arg = ft_i128toa((n < 0 ? -n : n), base, map);
	v->arg_len = ft_strlen(v->arg);
	if (v->prec > 0)
		v->flag.zero = 0;
	v->prec = (v->prec > 0 ? v->prec - v->arg_len : v->prec);
	v->len -= (v->prec > 0 ? (v->prec + v->arg_len) : v->arg_len);
	(v->prec == 0 && n == 0 ? v->len++ : 0);
	(v->prec < 0 ? v->prec = -1 : 0);
	if (v->flag.hash || v->type == 'p')
	{
		if (((v->type == 'x' || v->type == 'X') && n > 0) || v->type == 'p')
			v->len -= 2;
		else if (v->type == 'o' || v->type == 'O')
			v->len >= 0 ? v->len-- : v->prec--;
	}
	i = v->len;
	if (v->flag.plus || v->flag.space || n < 0)
		i--;
	return (i);
}

int			pf_int_nminus(t_variable *v, __int128 n, int i, int fd)
{
	int tot;
	int prec;

	tot = 0;
	prec = v->prec;
	if ((v->flag.plus || n < 0) && v->flag.zero)
		tot += (n >= 0 ? ft_putchar_fd('+', fd) : ft_putchar_fd('-', fd));
	else if ((v->flag.space || v->flag.hash) && n >= 0 && v->flag.zero)
		tot += (!v->flag.space || v->type == 'p' ?
				pf_hash(v, n, fd) : ft_putchar_fd(' ', fd));
	while (i-- > 0)
		tot += (v->flag.zero && v->prec < 0 ?
				ft_putchar_fd('0', fd) : ft_putchar_fd(' ', fd));
	if ((v->flag.plus || n < 0) && !v->flag.zero)
		tot += (n >= 0 ? ft_putchar_fd('+', fd) : ft_putchar_fd('-', fd));
	else if ((v->flag.space || v->flag.hash) && n >= 0 && !v->flag.zero)
		tot += (!v->flag.space || v->type == 'p' ?
				pf_hash(v, n, fd) : ft_putchar_fd(' ', fd));
	while (prec-- > 0)
		tot += ft_putchar_fd('0', fd);
	tot += (v->prec == 0 && n == 0 ? 0 : ft_putstr_fd(v->arg, fd));
	return (tot);
}

int			pf_int_minus(t_variable *v, __int128 n, int i, int fd)
{
	int tot;
	int prec;

	tot = 0;
	prec = v->prec;
	if (v->flag.plus || n < 0)
		tot += (n >= 0 ? ft_putchar_fd('+', fd) : ft_putchar_fd('-', fd));
	else if ((v->flag.space || v->flag.hash) && n >= 0)
		tot += (v->flag.space ? ft_putchar_fd(' ', fd) : pf_hash(v, n, fd));
	while (prec-- > 0)
		tot += ft_putchar_fd('0', fd);
	tot += (v->prec == 0 && n == 0 ? 0 : ft_putstr_fd(v->arg, fd));
	while (i-- > 0)
		tot += ft_putchar_fd(' ', fd);
	return (tot);
}
