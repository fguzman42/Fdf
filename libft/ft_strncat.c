/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 18:07:08 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/19 16:12:11 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	l;
	char	*string;

	i = 0;
	l = 0;
	string = s1;
	while (s1[l] != '\0')
		l++;
	while (s2[i] != '\0' && i < n)
	{
		s1[l] = s2[i];
		l++;
		i++;
	}
	s1[l] = '\0';
	s1 = string;
	return (s1);
}
