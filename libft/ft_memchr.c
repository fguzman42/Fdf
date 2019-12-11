/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:44:08 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/19 18:20:34 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *chr;

	if (n != 0)
	{
		chr = (unsigned char*)s;
		while (n != 0)
		{
			if (*chr == (unsigned char)c)
				return ((void*)chr);
			n--;
			chr++;
		}
	}
	return (NULL);
}
