/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:40:45 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/11/22 15:01:14 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

static void		find_x(t_mlxtool *tool)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < tool->max_row)
	{
		while (j < tool->max_column)
		{
			if (tool->tab[i][j].x < tool->minx)
				tool->minx = tool->tab[i][j].x;
			if (tool->tab[i][j].x > tool->maxx)
				tool->maxx = tool->tab[i][j].x;
			j++;
		}
		i++;
	}
}

static void		find_y(t_mlxtool *tool)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < tool->max_row)
	{
		while (j < tool->max_column)
		{
			if (tool->tab[i][j].y < tool->miny)
				tool->miny = tool->tab[i][j].y;
			if (tool->tab[i][j].y > tool->maxy)
				tool->maxy = tool->tab[i][j].y;
			j++;
		}
	}
}

void			create_win(t_mlxtool *mlx_tool, char *name)
{
	int sizex;
	int sizey;

	find_x(mlx_tool);
	find_y(mlx_tool);
	sizex = mlx_tool->minx - mlx_tool->maxx;
	sizey = mlx_tool->miny - mlx_tool->maxy;
	mlx_tool->init = mlx_init();
	mlx_tool->win = mlx_new_window(mlx_tool->init, sizex, sizey, name);
	mlx_loop(mlx_tool->init);
}
