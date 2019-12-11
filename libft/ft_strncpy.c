/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:48:48 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/19 16:12:54 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *string;

	string = dst;
	while (len > 0 && *src != '\0')
	{
		*string++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*string++ = '\0';
		len--;
	}
	return (dst);
}
