/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:00:46 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/21 14:28:14 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numlen(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		p;

	p = 1;
	i = numlen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(char) * numlen(n) + 1)))
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while (n != 0)
	{
		str[i - p] = '0' + (n % 10);
		n = n / 10;
		p++;
	}
	str[i] = '\0';
	return (str);
}
