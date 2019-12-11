/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:24:41 by fguzman           #+#    #+#             */
/*   Updated: 2019/10/17 16:24:58 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	c;
	char			*str;

	c = 0;
	if (!s || !(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (c < len)
	{
		str[c] = s[start + c];
		c++;
	}
	str[c] = '\0';
	return (str);
}
