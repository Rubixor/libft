/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 23:10:56 by mdenoyel          #+#    #+#             */
/*   Updated: 2017/06/12 16:14:08 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSCANF_H
# define FT_SSCANF_H

# include <stdarg.h>

typedef struct		s_scanf
{
	va_list			*args;
	const char		*str;
	const char		*str_origin;
}					t_scanf;

#endif
