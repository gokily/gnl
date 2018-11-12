/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:21:17 by gly               #+#    #+#             */
/*   Updated: 2018/11/12 15:38:49 by gly              ###   ########.fr       */
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
	fdrst = malloc(sizeof(t_fdlst));
	fdrst->fd = fd;
	if (!(fdrst->rst = (char *)malloc(sizeof(char))))
	{
		free(fdrst);
		return (NULL);
	}
	fdrst->rst = NULL;
	fdrst->next = *lst_fdrst != NULL ? *lst_fdrst : NULL;
	if (*lst_fdrst == NULL && !(*lst_fdrst = malloc(sizeof(t_fdlst *))))
		return (NULL);
	*lst_fdrst = fdrst;
	return (fdrst);
}		
		
int		ft_writeline(char *read, char **tmp, t_fdlst *lst_elem, int ret)
{
	char	*pt;

	if ((pt = ft_strchr(read, '\n')))
	{
		*pt = '\0';
		if (!(lst_elem->rst = ft_strdup(pt + sizeof(char))))
			return (-1);
		if(!(*tmp = ft_strjoinfree(*tmp, ft_strdup(read))))
		{
			free(lst_elem->rst);
			return (-1);
		}
		return (1);
	}
	if (!(*tmp = ft_strjoinfree(*tmp, read)))
		return (-1);
	return (ret < BUFF_SIZE ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static t_fdlst	*lst_fdrst = 0;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_fdlst		*lst_elem;
	int				n;
	char		*tmp;

	ret = 0;
	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	tmp = malloc(sizeof(char *));
	if(!(lst_elem = ft_lstsrc_fd(&lst_fdrst, fd)))
		return (-1);
	if (lst_elem->rst != 0 && ft_strlen(lst_elem->rst))
	{
		n = ft_writeline(lst_elem->rst, &tmp, lst_elem, ret);
		*line = n == 1 ? tmp : *line;
		if (n != 0)
			return (n);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		n = ft_writeline(buff, &tmp, lst_elem, ret);
		*line = n == 1 ? tmp : *line;
		if (n != 0)
			return (n);
	}
	return (0);
}
