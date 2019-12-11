/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:16:20 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/19 16:07:34 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;
	unsigned char	a;

	i = 0;
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	a = (unsigned char)c;
	while (n > 0)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == a)
			return (&cdst[i + 1]);
		i++;
		n = n - 1;
	}
	return (NULL);
}
