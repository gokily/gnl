/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:21:17 by gly               #+#    #+#             */
/*   Updated: 2018/11/11 16:01:02 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	if (s2 == 0)
		return (0);
	puts("IN STRJOINFREE");
	printf("s1 is %s and s2 is %s\n", s1, s2);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(ptr = ft_strnew(len)))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len)
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	free((void *)s1);
	return (ptr);
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
		puts("found a \\n !!");
		printf("line is %s\n", *line);
		*pt = '\0';
		if (!(lst_elem->rst = ft_strdup(pt + sizeof(char))))
			return (-1);
		printf("The new rest is %s\n", lst_elem->rst);
		printf("Read is %s\n", read);
		printf("Line now is %s\n", *line);
		if (!(*line = ft_strjoinfree(*line, read)))
			return (-1);
		printf("The new line is %s\n", *line);

		return (1);
	}
	if (!(*line = ft_strjoinfree(*line, read)))
		return (-1);
	ft_strclr(lst_elem->rst);
	free(lst_elem->rst);
	lst_elem->rst = 0;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_fdlst	*lst_fdrst = 0;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_fdlst			*lst_elem;
	int				n;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0 )
		return (-1);
	if (!(lst_elem = ft_lstsrc_fd(&lst_fdrst, fd)))
		return (-1);
	ft_strclr(*line);
	if (lst_elem->rst != 0 && ft_strlen(lst_elem->rst))
	{
		puts("THERE IS A RST");
		ft_putstr("rst is ");
		ft_putnbr(ft_strlen(lst_elem->rst));
		ft_putstr(" char long and is: ");
		ft_putendl(lst_elem->rst);
		n = ft_writeline(lst_elem->rst, line, lst_elem);
		printf("n is %i\n", n);
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
