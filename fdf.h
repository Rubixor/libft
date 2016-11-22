/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 12:44:23 by mdenoyel          #+#    #+#             */
/*   Updated: 2016/11/22 14:03:14 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct				s_point
{
	int						x;
	int						y;
	int						z;
	struct s_point			*next;
}							t_point;

typedef struct				s_tab
{
	int						x;
	int						y;
	int						z;
	int						exist;
}							t_tab;

typedef struct				s_mlxtool
{
	void					*init;
	void					*win;
	int						max_row;
	int						max_column;
	t_tab					**tab;
	int						minx;
	int						maxx;
	int						miny;
	int						maxy;
}							t_mlxtool;

void						parsing(t_point *p, t_mlxtool *mlx_tools, int fd);

void						create_tab(t_point *point, t_mlxtool *mlx_tools);

int							draw_line();

void						create_win(t_mlxtool *mlx_tool, char *name);

#endif
