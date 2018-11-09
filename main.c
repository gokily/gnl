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
	
	puts("Start the test");
	if (ac < 2)
		return (0);
	puts("Opening file");
	line = malloc(sizeof(char **));
	*line = malloc(sizeof(char *));
	puts(av[1]);
	fd = open(av[1], O_RDONLY);
	ft_putnbr(fd);
	puts(" is the fd");

	get_next_line(fd, line);
	puts("getting next line");
	ft_putendl(*line);

	get_next_line(fd, line);
	puts("getting next line");
	ft_putendl(*line);

	get_next_line(fd, line);
	puts("getting next line");
	ft_putendl(*line);

	get_next_line(fd, line);
	puts("getting next line");
	ft_putstr(*line);

	return (1);
}	
