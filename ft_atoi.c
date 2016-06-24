/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:21:18 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/03/17 11:36:44 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_atoi(const char *s)
{
	int i;
	int res;
	int coeff;

	i = 0;
	res = 0;
	coeff = 1;
	while (*s && ft_isspace(s[i]))
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		coeff = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * coeff);
}
