/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:49:24 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/22 17:09:01 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *str)
{
	int i;
	int n;
	int flag;

	flag = 1;
	i = 0;
	while (str[i] == '\0' || str[i] == '\t' || str[i] == '\n' || str[i] ==
			'\f' || str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	n = 0;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * flag);
}
