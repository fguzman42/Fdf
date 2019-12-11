/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:10:47 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/25 22:38:26 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	if (n > ft_strlen(s1))
		return (ft_strdup(s1));
	while (s1[i] && n > 0)
	{
		str[i] = s1[i];
		i++;
		n--;
	}
	str[i] = '\0';
	return (str);
}
