
#include "fdf.h"
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>//delete

static t_point		*add_point(char *s, int x, int y)
{
	t_point *new;

	if (ft_strisdigit(s) || s[0] == '+' || s[0] == '-') //check positif et negatif (-42)
	{
		if ((new = (t_point *)malloc(sizeof(t_point))))
		{
			new->x = x;
			new->y = y;
			new->z = ft_atoi(s);
		}
	}
	else
	{
		ft_putendl("Error : map invalid.");
		return (NULL);
	}
	return (new);
}

void				parsing(t_point *point, t_mlxtool *mlx_tools, int fd)
{
	char	*line;
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i])
		{
			point->next = add_point(split[i], i, j);
			point = point->next;
			if (i > mlx_tools->max_row)
				mlx_tools->max_row = i;
			i++;
		}
		if (j > mlx_tools->max_column)
			mlx_tools->max_column = j;
		j++;
		//printf("maxRow = %d | maxCollum = %d| \n", mlx_tools->maxRow, mlx_tools->maxCollum);
	}
}
