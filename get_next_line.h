/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:54:51 by gly               #+#    #+#             */
/*   Updated: 2018/11/09 13:24:01 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_fdrest
{
	int			fd;
	char		*rest;
}				t_fdrest;

int				get_next_line(const int fd, char **line);

#endif
