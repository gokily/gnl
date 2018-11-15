/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:21:17 by gly               #+#    #+#             */
/*   Updated: 2018/11/13 16:11:14 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*pt;

	if (!(pt = ft_strjoin(s1, s2)))
		return (0);
	ft_strdel(&s1);
	return (pt);
}

t_fdlst	*ft_lstsrc_fd(t_fdlst **lst_fdrst, int fd)
{
	t_fdlst	*fdrst;
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
	if (!(fdrst = malloc(sizeof(t_fdlst))))
		return (NULL);
	if (!(fdrst->rst = ft_strnew(0)))
		return (NULL);
	fdrst->fd = fd;
	fdrst->next = *lst_fdrst != NULL ? *lst_fdrst : NULL;
	*lst_fdrst = fdrst;
	return (fdrst);
}

int		ft_writeline(char *read, char **tmp, t_fdlst *lst_elem)
{
	char	*pt;
	char	*dup;

	if ((pt = ft_strchr(read, '\n')))
	{
		*pt = '\0';
		if (!(dup = ft_strdup(pt + sizeof(char))))
			return (-1);
		ft_strdel(&(lst_elem->rst));
		lst_elem->rst = dup;
		if (!(dup = ft_strdup(read))
				|| !(*tmp = ft_strjoinfree(*tmp, dup)))
		{
			ft_strdel(&(lst_elem->rst));
			return (-1);
		}
		ft_strdel(&dup);
		return (1);
	}
	if (!(*tmp = ft_strjoinfree(*tmp, read)))
		return (-1);
	ft_strdel(&(lst_elem->rst));
	return (0);
}

void	ft_freenode(t_fdlst **lst, int fd)
{
	t_fdlst	*elem;
	t_fdlst *tmp;

	elem = *lst;
	if (elem->fd == fd)
	{
		*lst = elem->next;
		free(elem);
	}
	while (elem->next)
	{
		if (elem->next->fd == fd)
		{
			tmp = elem->next;
			elem->next = elem->next->next;
			free(tmp);
			return ;
		}
		elem = elem->next;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_fdlst	*lst_fdrst = 0;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_fdlst			*lst_elem;

	if (fd < 0 || line == 0 || read(fd, NULL, 0) < 0 || !(*line = ft_strnew(0))
			|| !(lst_elem = ft_lstsrc_fd(&lst_fdrst, fd)))
		return (-1);
	if (lst_elem->rst != 0 && ft_strlen(lst_elem->rst))
	{
		if ((ret = ft_writeline(lst_elem->rst, line, lst_elem)) != 0)
			return (ret);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if ((ret = ft_writeline(buff, line, lst_elem)) != 0)
			return (ret);
	}
	if (ft_strlen(*line))
	{
		return (1);
	}
	ft_freenode(&lst_fdrst, fd);
	return (0);
}
