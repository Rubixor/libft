/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_modif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:34:38 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/24 20:02:11 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_next(char c, t_variable *var)
{
	if (c == var->modif[0])
	{
		var->modif[1] = c;
		var->modif[2] = '\0';
		return (2);
	}
	var->modif[1] = '\0';
	return (1);
}

static int	other_modif(char *s, int i, t_variable *v)
{
	while (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' || s[i] == 'z')
	{
		if ((s[i] == 'l' && v->modif[0] == 'h')
				|| (s[i] == 'z' && (v->modif[0] == 'h' || v->modif[0] == 'l'))
				|| s[i] == 'j')
		{
			v->modif[0] = s[i];
			if (v->modif[0] == 'l')
				i += check_next(s[i + 1], v);
			else
			{
				v->modif[1] = '\0';
				i++;
			}
		}
		else
			i++;
	}
	return (i);
}

int			pf_check_modif(char *str, t_variable *var)
{
	int i;

	i = 0;
	if (str[i] == 'h' || str[i] == 'l')
	{
		var->modif[0] = str[i];
		return (other_modif(str, check_next(str[i + 1], var), var));
	}
	if (str[i] == 'j' || str[i] == 'z')
	{
		var->modif[0] = str[i];
		var->modif[1] = '\0';
		return (other_modif(str, 1, var));
	}
	else
		var->modif[0] = '\0';
	return (0);
}
