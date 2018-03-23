/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:32:21 by mdenoyel          #+#    #+#             */
/*   Updated: 2018/03/12 15:16:26 by mdenoyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define GNL_SUCCESS 1
# define GNL_ERROR -1
# define NO_BUFF 2
# define IS_BUFF 3

int		get_next_line(int const fd, char **line);

#endif
