/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:47:52 by snicolet          #+#    #+#             */
/*   Updated: 2017/06/16 17:30:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int		ft_sscanf(const char *s, const char *format, ...);
{
	va_list		args;
	t_scanf		sf;

	sf.args = &args;
	sf.str = s;
	sf.str_origin = s;
	va_start(args, format);
	va_end(args);
}
