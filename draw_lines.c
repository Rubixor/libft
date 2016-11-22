/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:54:01 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/11/21 13:36:05 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../libft/includes/libft.h"

void	draw_line_1(int x1, int y1, int x2, int y2, void *init, void *win)
{
	int		x;
	int		y;

	x = x1;
	while (x++ <= x2)
	{
		y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
		mlx_pixel_put(init, win, x, y, 0x00FF0000);
	}
}

void	draw_line_2(int x1, int y1, int x2, int y2, void *init, void *win)
{
	int		x;
	int		y;

	y = y1;
	while (y-- >= y2)
	{
		x = x1 + ((x2 - x1) * (y - y1)) / (y2 - y1);
		mlx_pixel_put(init, win, x, y, 0x00FF0000);
	}
}

int		draw_line(int x1, int y1, int x2, int y2, void *init, void *win)
{
	if (x1 <= x2 && (x2 - x1) >= ft_abs(y2 - y1))
		draw_line_1(x1, y1, x2, y2, init, win);
	else if (x1 > x2 && (x1 - x2) >= ft_abs(y1 - y2))
		draw_line_1(x2, y2, x1, y1, init, win);
	else if (y1 > y2 && (x2 - x1) <= ft_abs(y2 - y1))
		draw_line_2(x1, y1, x2, y2, init, win);
	else if (y1 <= y2 && (x1 - x2) <= ft_abs(y1 - y2))
		draw_line_2(x2, y2, x1, y1, init, win);
	return (0);
}
