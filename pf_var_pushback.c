/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_var_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:46:06 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/16 16:32:04 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_variable	*pf_var_pushback(t_variable **var, t_variable *item)
{
	t_variable *tmp;

	tmp = *var;
	if (!tmp)
		*var = item;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = item;
	}
	return (item);
}
