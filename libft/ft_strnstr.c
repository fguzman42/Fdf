/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:22:54 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/27 21:19:07 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int p;

	i = 0;
	p = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		while (haystack[i + p] == needle[p] && len > 0)
		{
			p++;
			len--;
			if (needle[p] == '\0')
				return ((char *)&haystack[i]);
		}
		if (len == 0)
			break ;
		i++;
		len--;
	}
	return (NULL);
}
