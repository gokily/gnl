/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:57:09 by gly               #+#    #+#             */
/*   Updated: 2018/11/19 11:19:35 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		main(int ac, char **av)
{
	int		fd1;
	char	*line;
	int		ret;

	line = 0;
	ft_putendl("Start the test");
	if (ac < 2)
		return (0);
	ft_putendl("Opening file");
	ft_putendl(av[1]);
	fd1 = open(av[1], O_RDONLY);
	ft_putnbr(fd1);
	ft_putendl(" is the fd");

	while ((ret = get_next_line(fd1, &line)))
	{
		ft_putendl("getting next line");
		ft_putendl(line);
		free(line);
	}
//	while (1)
//		;
	return (1);
}	
