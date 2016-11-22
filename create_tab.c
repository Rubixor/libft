#include <stdlib.h>
#include "fdf.h"

void	create_tab(t_point *point, t_mlxtool *mlx_tools)
{
	int i;
	int j;

	i = 0;
	mlx_tools->tab = (t_tab **)malloc(sizeof(t_tab *) * mlx_tools->max_column);
	point = point->next;
	while (i <= mlx_tools->max_row)
	{
		mlx_tools->tab[i] = (t_tab *)malloc(sizeof(t_tab) * mlx_tools->max_row);
		j = 0;
		while (j <= mlx_tools->max_column)
		{
			if (point->y != i)
				mlx_tools->tab[i][j].exist = 0;
			else
				mlx_tools->tab[i][j].exist = 1;
			mlx_tools->tab[i][j].x  = point->x;//changer pour la valeur de x 2d
			mlx_tools->tab[i][j].y  = point->y;//changer pour la valeur de y 2d
			mlx_tools->tab[i][j].z  = point->z;
			j++;
			if (point->next)
				point = point->next;
		}
		i++;
	}
}
