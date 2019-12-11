/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:07:34 by fguzman           #+#    #+#             */
/*   Updated: 2019/03/19 16:06:41 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*container;
	t_list	*remainder;

	container = *alst;
	while (container)
	{
		remainder = container->next;
		del((container->content), (container->content_size));
		free(container);
		container = remainder;
	}
	*alst = NULL;
}
