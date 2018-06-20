/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:32:21 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/06/20 15:18:50 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

#pragma pack(push, 1)

typedef struct		s_gnl
{
	int				fd;
	char			*buff;
	size_t			buff_len;
}					t_gnl

#pragma pack(pop)

/*
** OLD_GET_NEXT_LINE :
*/

# define GNL_SUCCESS 1
# define GNL_ERROR -1
# define NO_BUFF 2
# define IS_BUFF 3

int		get_next_line(int const fd, char **line);

#endif
