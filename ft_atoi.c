/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:21:18 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/05 13:55:26 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int res;
	int coeff;

	res = 0;
	coeff = 1;
	while (*s && ft_isspace(*s))
		s++;
	if (!*s)
		return (0);
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		coeff = -1;
		s++;
	}
	while (*s && ft_isdigit(*s))
	{
		res = res * 10 + *s - '0';
		s++;
	}
	return (res * coeff);
}
