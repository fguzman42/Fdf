/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:59:37 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/19 16:08:34 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	i = 0;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (source < dest)
	{
		while ((int)--len >= 0)
			*(dest + len) = *(source + len);
	}
	else
	{
		while (i < len)
		{
			*(dest + i) = *(source + i);
			i++;
		}
	}
	return (dest);
}
