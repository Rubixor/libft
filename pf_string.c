/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:31:56 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:29:16 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int		pf_string(t_variable *v, va_list args, int fd)
{
	int		i;
	int		len;
	char	*ar;
	int		t;

	t = 0;
	if (!(ar = ft_strdup(va_arg(args, char *))))
		ar = ft_strdup("(null)");
	len = ft_strlen(ar);
	v->prec = (v->prec >= len ? len : v->prec);
	i = v->len - (v->prec >= 0 && v->prec < len ? v->prec : len);
	if (v->flag.minus)
		t += (v->prec >= 0 ? write(fd, ar, v->prec) : ft_putstr_fd(ar, fd));
	while (i > 0)
	{
		if (v->flag.zero && !v->flag.minus)
			t += ft_putchar_fd('0', fd);
		else
			t += ft_putchar_fd(' ', fd);
		i--;
	}
	if (!v->flag.minus)
		t += (v->prec >= 0 ? write(fd, ar, v->prec) : ft_putstr_fd(ar, fd));
	free(ar);
	return (t);
}
