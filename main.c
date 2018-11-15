/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:57:09 by gly               #+#    #+#             */
/*   Updated: 2018/11/15 11:40:27 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	char	*line;
	
	line = 0;
	free(line);
	free(NULL);
	ft_putendl("Start the test");
	if (ac < 2)
		return (0);
	ft_putendl("Opening file");
	ft_putendl(av[1]);
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	ft_putnbr(fd1);
	ft_putendl(" is the fd");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd1, &line));
	ft_putendl(line);
	ft_putendl("");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd1, &line));
	ft_putendl(line);
	ft_putendl("");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd1, &line));
	ft_putendl(line);
	ft_putendl("");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd1, &line));
	ft_putendl(line);
	ft_putendl("");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd1, &line));
	ft_putendl(line);
	ft_putendl("");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd1, &line));
	ft_putendl(line);
	ft_putendl("");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd2, &line));
	ft_putendl(line);
	ft_putendl("");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd2, &line));
	ft_putendl(line);
	ft_putendl("");

	ft_putendl("getting next line");
	line = malloc(sizeof(char *));
	ft_putnbr(get_next_line(fd2, &line));
	ft_putendl(line);
	ft_putendl("");

	return (1);
}	
