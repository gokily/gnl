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

char	*ft_strjoinfree(char const *s1, char const *s2)
{
	char	*ptr;

	if (!(ptr = ft_strjoin(s1, s2)))
		return (0);
	free((void *)s1);
	return (ptr);
}



static char	*ft_src_rest(char **rest)
{
	int		*ptr;

	if((ptr = ft_strchr(*rest, '\n')))
	{
			

int		get_next_line(const int fd, char **line)
{
	static char *rest = 0;
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*ptr;

	if(!(*line = ft_src_rest(rest)))
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{

			if (!(rest = ft_strdup(ptr + sizeof(char))))
				return (-1);
			if(!(*line = ft_strjoinfree(*line, ft_strsub(buff, 0, ptr - buff))))
			{
				free(rest);
				return (-1);
			}
			return (1);
		}
		if (!(*line = ft_strjoinfree(*line, buff)))
			return (-1);
	}
	return (0);
}
