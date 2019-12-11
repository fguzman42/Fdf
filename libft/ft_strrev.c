/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:31:56 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/24 19:01:58 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strrev returns a string with its characters reversed.
** if the string is empty, it returns NULL
*/

char	*ft_strrev(char *s)
{
	char	*str;
	int		i;
	int		l;

	l = 0;
	i = (ft_strlen(s) - 1);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (i >= 0)
	{
		str[l] = s[i];
		i--;
		l++;
	}
	str[l] = '\0';
	return (str);
}
