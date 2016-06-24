/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:06:20 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 18:57:42 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	pf_collect_len(t_variable *v, va_list args)
{
	if (v->len <= -1)
		while (v->len_star > 0)
		{
			if ((v->len = va_arg(args, int)) < 0)
			{
				v->len *= -1;
				v->flag.minus = 1;
			}
			v->len_star--;
		}
	else
		while (v->len_star > 0)
		{
			va_arg(args, int);
			v->len_star--;
		}
}

int		pf_check_len(char *str, t_variable *var)
{
	int i;
	int len;

	i = 0;
	while ((len = ft_atoi(str + i)) || str[i] == '*')
	{
		var->len = len;
		if (len > 0)
			i++;
		while ((len /= 10) > 0)
			i++;
		if (str[i] == '*')
		{
			var->len_star++;
			var->len = -1;
			i++;
		}
	}
	return (i);
}
