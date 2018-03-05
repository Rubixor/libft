/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:35:32 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/05 18:04:22 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		dec_len(const char *s)
{
	unsigned int	len;

	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	return (len);
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
	d_len = dec_len(s);
	p_dec = (double)dec;
	while (d_len--)
		p_dec /= 10;
	while (p_dec > 1)
		p_dec--;
	return ((double)p_ent + p_dec);
}
