/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:57:09 by gly               #+#    #+#             */
/*   Updated: 2018/11/09 18:19:07 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	**line;
	char	str[1] = "";
	
	ft_putendl("Start the test");
	if (ac < 2)
		return (0);
	ft_putendl("Opening file");
	line = malloc(sizeof(char **));
	*line = malloc(sizeof(char *));
	ft_putendl(av[1]);
	fd = open(av[1], O_RDONLY);
	ft_putnbr(fd);
	ft_putendl(" is the fd");

	get_next_line(fd, line);
	ft_putendl("getting next line");
	ft_putendl(*line);
	ft_putendl("");

	get_next_line(fd, line);
	ft_putendl("getting next line");
	ft_putendl(*line);
	ft_putendl("");

	get_next_line(fd, line);
	ft_putendl("getting next line");
	ft_putendl(*line);
	ft_putendl("");

	get_next_line(fd, line);
	ft_putendl("getting next line");
	ft_putendl(*line);
	ft_putendl("");

	return (1);
}	
