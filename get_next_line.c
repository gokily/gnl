/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:21:17 by gly               #+#    #+#             */
/*   Updated: 2018/11/09 18:18:50 by gly              ###   ########.fr       */
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

t_list	*ft_lstsrc_fd(t_list **lst_fdrst, int fd)
{
	t_fdrst	*fdrst;
	t_list	*lst_elem;

	if (*lst_fdrst != NULL)
	{
		lst_elem = *lst_fdrst;
		while (lst_elem)
		{
			if (lst_elem->content->fd == fd)
				return (lst_elem);
			lst_elem = lst_elem->next;
		}
	}
	if (!(fdrst = (t_fdrst *)malloc(sizeof(t_fdrst))))
		return (NULL);
	fdrst->fd = fd;
	if (!(fdrst->rst = (char *)malloc(sizeof(char))))
	{
		free(fdrst);
		return (NULL);
	}
	if (!(lst_elem = ft_lstnew(fdrst, sizeof(t_fdrst *))))
	{
		free(fdrst->rst);
		free(fdrst);
		return (NULL);
	}
	if (*lst_fdrst != NULL)
		lst_elem->next = *lst_fdrst;
	*lst_fdrst = lst_elem;
	return (lst_elem);
}		
		
int		ft_writeline(char *read, char **line, t_list *lst_elem)
{
	char	*pt;

	if ((pt = ft_strchr(read, '\n')))
	{
		if (!(lst_elem->content->rst = ft_strdup(pt + sizeof(char))))
			return (-1);
		if(!(*line = ft_strjoinfree(*line, ft_strsub(read, 0, pt - read))))
		{
			free(lst_elem->content->rst);
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
	static t_list	**lst_fdrst;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*pt;
	t_list			*lst_elem;
	int				n;

	free(*line);
	*line = (char *)malloc(sizeof(char *));
	*lst_fdrst = NULL;
	if(!(lst_elem = ft_lstsrc_fd(lst_fdrst, fd)))
		return (-1);
	ft_putendl("In get_next_line");
	if (lst_elem->content->rst != 0 && ft_strlen(lst_elem->content->rst))
	{
		ft_putendl("rst not empty");
		ft_putstr("rst is ");
		ft_putnbr(ft_strlen(lst_elem->content->rst));
		ft_putstr(" char long and is: ");
		ft_putendl(lst_elem->content->rst);
		n = ft_writeline(lst_elem->content->rst, line, lst_elem);
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
