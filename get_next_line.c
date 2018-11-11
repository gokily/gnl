/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:21:17 by gly               #+#    #+#             */
/*   Updated: 2018/11/11 10:35:13 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*pt;

	if (!(pt = ft_strjoin(s1, s2)))
		return (0);
	free(s1);
	return (pt);
}

t_fdlst	*ft_lstsrc_fd(t_fdlst **lst_fdrst, int fd)
{
	t_fdlst	*lst_elem;

	if (*lst_fdrst != NULL)
	{
		lst_elem = *lst_fdrst;
		while (lst_elem)
		{
			if (lst_elem->fd == fd)
				return (lst_elem);
			lst_elem = lst_elem->next;
		}
	}
	if (!(lst_elem = (t_fdlst *)malloc(sizeof(t_fdlst))))
		return (NULL);
	lst_elem->fd = fd;
	if (!(lst_elem->rst = (char *)malloc(sizeof(char))))
		return (NULL);
	lst_elem->rst = NULL;
	lst_elem->next = *lst_fdrst != NULL ? *lst_fdrst : NULL;
	if (*lst_fdrst == NULL && !(*lst_fdrst = malloc(sizeof(t_fdlst *))))
		return (NULL);
	*lst_fdrst = lst_elem;
	return (lst_elem);
}

int		ft_writeline(char *read, char **line, t_fdlst *lst_elem)
{
	char	*pt;

	if ((pt = ft_strchr(read, '\n')))
	{
		if (!(lst_elem->rst = ft_strdup(pt + sizeof(char))))
			return (-1);
		if (!(*line = ft_strjoinfree(*line, ft_strsub(read, 0, pt - read))))
		{
			free(lst_elem->rst);
			return (-1);
		}
		return (1);
	}
	if (!(*line = ft_strjoinfree(*line, read)))
		return (-1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_fdlst	*lst_fdrst = 0;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_fdlst			*lst_elem;
	int				n;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = (char *)malloc(sizeof(char *));
	if (!(lst_elem = ft_lstsrc_fd(&lst_fdrst, fd)))
		return (-1);
	if (lst_elem->rst != 0 && ft_strlen(lst_elem->rst))
	{
		n = ft_writeline(lst_elem->rst, line, lst_elem);
		if (n != 0)
			return (n);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		n = ft_writeline(buff, line, lst_elem);
		if (n != 0)
			return (n);
	}
	return (0);
}
