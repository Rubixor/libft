/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:18:20 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/11/22 15:07:35 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void		init_tool(t_mlxtool *tool)
{
	tool->max_row = 0;
	tool->max_column = 0;
	tool->minx = 2147483647;
	tool->maxx = -2147483648;
	tool->miny = 2147483647;
	tool->maxy = -2147483648;
}

int				main(int ac, char **av)
{
	t_point		point;
	t_mlxtool	*tool;
	int			fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			tool = (t_mlxtool *)malloc(sizeof(t_mlxtool));
			init_tool(tool);
			parsing(&point, tool, fd);
			create_tab(&point, tool);
			close(fd);
			create_win(tool, "FdF");
		}
		//else
			//erreur;
	}
	//	mlx_pixel_put(init, win, 200, 200, 0x00FFFFFF);
}
