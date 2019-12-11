/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:00:27 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/19 16:07:50 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char string1;
	unsigned char string2;

	while (n--)
	{
		string1 = *(unsigned char*)s1;
		string2 = *(unsigned char*)s2;
		if (string1 != string2)
			return (string1 - string2);
		s1++;
		s2++;
	}
	return (0);
}
