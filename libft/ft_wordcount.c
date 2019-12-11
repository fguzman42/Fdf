/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:50:40 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/24 17:09:14 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *s, char c)
{
	int wc;
	int i;

	i = 0;
	wc = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
				if (s[i] == c || s[i] == '\0')
					wc++;
			}
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	if (wc == 0)
		wc++;
	return (wc);
}
