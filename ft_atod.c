/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:35:32 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/05 14:24:50 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		dec_len(unsigned int dec)
{
	unsigned int	len;

	len = 0;
	while (dec /= 10)
		len++;
	return (len + 1);
}

double					ft_atod(const char *s)
{
	int				p_ent;
	double			p_dec;
	unsigned int	dec;
	unsigned int	d_len;

	p_ent = ft_atoi(s);
	while (*s != '.')
		s++;
	s++;
	ft_atonum(s, &dec);
	d_len = dec_len(dec);
	p_dec = (double)dec;
	while (d_len--)
		p_dec /= 10;
	return ((double)p_ent + p_dec);
}
