/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:43:55 by gly               #+#    #+#             */
/*   Updated: 2018/11/09 09:53:55 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_end(unsigned char *dst, unsigned char *src, size_t n)
{
	while (n >= 1)
	{
		n--;
		dst[n] = src[n];
	}
	return (dst);
}

static void	*ft_memmove_ft(unsigned char *dst, unsigned char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	tmp = (unsigned char *)src;
	if (dest > src)
		dest = ft_memmove_end(ptr, tmp, n);
	else
		dest = ft_memmove_ft(ptr, tmp, n);
	return (dest);
}
