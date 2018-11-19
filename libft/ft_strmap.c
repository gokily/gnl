/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:28:35 by gly               #+#    #+#             */
/*   Updated: 2018/11/08 14:56:46 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	if (s == 0 || f == 0)
		return (0);
	if (!(ptr = ft_strnew(ft_strlen((char *)s))))
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(s[i]);
		i++;
	}
	return (ptr);
}
