/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 10:32:30 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/07 16:05:00 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_check_flags(char *str, t_variable *var)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
			var->flag.plus = 1;
		else if (str[i] == '#')
			var->flag.hash = 1;
		else if (str[i] == '0')
			var->flag.zero = 1;
		else if (str[i] == '-')
			var->flag.minus = 1;
		else if (str[i] == ' ')
			var->flag.space = 1;
		else
			return (i);
		i++;
	}
	return (i);
}
