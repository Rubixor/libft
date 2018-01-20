/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:47:34 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 19:49:22 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int			pf_display(const char *str, t_variable *var, va_list args, int fd)
{
	size_t	i;
	size_t	j;
	size_t	rab;

	i = 0;
	j = 0;
	rab = 0;
	while (str[i + j])
	{
		if (str[i + j] == '%')
		{
			rab += pf_treat(var, args, fd);
			j++;
			while (var->type && str[i + j] != var->type && str[i + j])
				j++;
			j++;
			if (var->type == '\x00')
				return ((int)(i + rab));
			var = var->next;
		}
		else
			i += ft_putchar_fd(str[i + j], fd);
	}
	return ((int)(i + rab));
}
