/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:47:55 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 20:09:03 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	pf_collect_prec(t_variable *v, va_list args)
{
	if (v->prec <= -2)
		while (v->prec_star > 0)
		{
			v->prec = va_arg(args, int);
			v->prec_star--;
		}
	else
		while (v->prec_star > 0)
		{
			va_arg(args, int);
			v->prec_star--;
		}
}

int		pf_check_prec(char *str, t_variable *var)
{
	int prec;
	int i;

	prec = -1;
	if (*str == '.' && (i = 1))
	{
		if (ft_isdigit(*(++str)))
		{
			i++;
			if (ft_atoi(str) >= 0)
				prec = ft_atoi(str);
			var->prec = prec;
			while ((prec /= 10) > 0 && i++)
				str++;
			str++;
		}
		else if (*str == '*')
		{
			var->prec_star++;
			var->prec = -2;
			i++;
		}
		else
			var->prec = 0;
		return (i + pf_check_prec(str, var));
	}
	return (0);
}
