/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:09:07 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/06/20 15:18:17 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** fd_lst->content_size	=> the current fd
** fd_lst->content		=> the buffer linked to the fd
*/

static char		*buff_join(const int fd, t_gnl *gnl, int rd_buff, ssize_t *rd)
{
	char	*tmp;

	if ((*rd = read(fd, rd_buff, BUFF_SIZE)) < 1)
		return (NULL);
	rd_buff[*rd] = '\0';
	gnl->buff_len = ft_strlen(gnl->buff);
	if ((tmp = (char *)malloc(sizeof(char) * gnl->buff_len)))
		ft_strcpy(ft_memset(tmp, 0, gnl->buff_len), gnl->buff);
	free(gnl->buff);
	if (!(gnl->buff = tmp))
		return (NULL);
}

static char		**get_buff(const int fd, t_list **lst)
{
	t_list	*l;

	l = *lst;
	while (l && (l->content_size != (size_t)fd))
		l = l->next;
	if (l)
		return ((char **)(&(l->content)));
	if (!(l = ft_lstnewlink(NULL, (size_t)fd)))
		return (NULL);
	ft_lstadd(lst, l);
	return ((char **)(&(l->content)));
}

static int		get_err(const int fd, t_list **fd_lst, t_gnl *gnl, char **line)
{
	if ((fd < 0) || (!line))
		return (EXIT_FAILURE);
	if (BUFF_SIZE <= 0)
		return (EXIT_FAILURE);
	if (!(*(gnl->buff) = get_buff(fd, fd_lst)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*fd_lst = NULL;
	t_gnl			gnl;
	char			*current;
	ssize_t			rd;
	int				rd_buff;

	if (get_err(fd, &fd_lst, &gnl, line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	current = gnl->buff;
	while (current && (!(current = ft_strchr(current, '\n'))))
		current = buff_join(fd, &gnl, rd_buff, ssize_t rd);
}
