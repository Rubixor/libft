/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_newvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 11:20:43 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/06/28 21:27:26 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

t_variable	*pf_newvar(void)
{
	t_variable *new;

	if (!(new = (t_variable *)malloc(sizeof(t_variable))))
		return (NULL);
	new->flag.plus = 0;
	new->flag.minus = 0;
	new->flag.hash = 0;
	new->flag.zero = 0;
	new->flag.space = 0;
	new->len = 0;
	new->len_star = 0;
	new->prec = -1;
	new->prec_star = 0;
	if (!(new->modif = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	new->modif[0] = '\0';
	new->type = '\0';
	new->arg = 0;
	new->next = NULL;
	new->arg_len = 0;
	return (new);
}
