/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:09:07 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/06/20 11:56:23 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

// static void	*ft_realloc_me(void *src, size_t size, size_t newsize)
// {
// 	void		*ptr;
//
// 	if (newsize < size)
// 		size = newsize;
// 	ptr = malloc(newsize);
// 	ft_memcpy(ptr, src, size);
// 	free(src);
// 	return (ptr);
// }

static int	ft_process(char **buf, char **line, char **tmp)
{
	char	*tmp2;
	char	*tmp3;

	if (*buf)
	{
		if ((tmp2 = ft_strchr(*buf, '\n')))
		{
			*tmp2 = '\0';
			*line = ft_strjoin(*tmp, *buf);
			*tmp2 = '\n';
			return (IS_BUFF);
		}
		tmp3 = ft_strjoin(*tmp, *buf);
		if (*tmp)
			free(*tmp);
		*tmp = tmp3;
	}
	return (NO_BUFF);
}

static int	ft_help(char *tmp, char **buf, char **line)
{
	if (!(*tmp))
	{
		ft_memdel((void**)(buf));
		*line = NULL;
		return (0);
	}
	ft_memdel((void**)(buf));
	*line = tmp;
	return (0);
}

static char	**ft_lst_chr(int const fd, t_list **list)
{
	t_list	*i;

	i = *list;
	while ((i) && (i->content_size != (size_t)fd))
		i = i->next;
	if (i)
		return ((char **)(&(i->content)));
	i = ft_lstnewlink(NULL, (size_t)fd);
	ft_lstadd(list, i);
	return ((char **)&i->content);
}

int			old_get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	char			**buf;
	ssize_t			rd;
	char			*tmp;

	if ((fd < 0) || (line == NULL))
		return (GNL_ERROR);
	buf = ft_lst_chr(fd, &list);
	tmp = (char *)malloc(sizeof(char));
	*tmp = '\0';
	while ((ft_process(buf, line, &tmp)) == NO_BUFF)
	{
		*buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		if (*buf)
		{
			if ((rd = read(fd, *buf, BUFF_SIZE)) < 0)
				return (GNL_ERROR);
			(*buf)[rd] = '\0';
			if (rd == 0)
				return (ft_help(tmp, buf, line));
		}
	}
	ft_strcleanc(buf, '\n');
	return (GNL_SUCCESS);
}
