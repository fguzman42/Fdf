/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:05:25 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/23 17:04:19 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			start;
	size_t			end;

	i = 0;
	start = 0;
	end = 0;
	if (!s)
		return (0);
	while (s[start] == '\t' || s[start] == ' ' || s[start] == '\n')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	i = ft_strlen(s) - 1;
	while ((s[i] == '\t' || s[i] == ' ' || s[i] == '\n') && (i != 0))
	{
		end++;
		i--;
	}
	str = ft_strsub(s, start, (ft_strlen(s) - (start + end)));
	return (str);
}
