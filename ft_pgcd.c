/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 10:16:07 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/05/31 10:54:22 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pgcd(int n1, int n2)
{
	int		i;
	int		save;

	i = 1;
	save = 0;
	while (i <= n1 && i <= n2)
	{
		if (n1 % i == 0 && n2 % i == 0)
			save = i;
		i++;
	}
	return (save);
}