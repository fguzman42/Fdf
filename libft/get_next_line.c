/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:19:37 by fguzman           #+#    #+#             */
/*   Updated: 2019/10/22 11:56:08 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strnjoin(char *s1, char *s2, int code)
{
	char *result;

	result = ft_strjoin(s1, s2);
	if (code == 1)
		free(s1);
	if (code == 2)
		free(s2);
	if (code == 3)
	{
		free(s1);
		free(s2);
	}
	return (result);
}

static int		process(int bytes_read, char **result, char *buffer, char **l)
{
	char	*nl;

	nl = NULL;
	if (bytes_read > 0)
	{
		if (*result == NULL)
			*result = ft_strdup(buffer);
		else
			*result = ft_strnjoin(*result, buffer, 1);
	}
	if (*result != NULL && ft_strchr(*result, '\n') != NULL)
	{
		nl = ft_strchr(*result, '\n');
		nl[0] = '\0';
		*l = ft_strdup(*result);
		nl = ft_strdup(nl + 1);
		free(*result);
		*result = nl;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				br;
	static char		*r[4864];
	char			*temp;
	int				exit;

	if (fd < 0 || line == NULL || read(fd, &buffer, 0) < 0)
		return (-1);
	if (r[fd] != NULL && ft_strchr(r[fd], '\n') != NULL)
	{
		temp = ft_strchr(r[fd], '\n');
		temp[0] = '\0';
		*line = ft_strdup(r[fd]);
		temp = ft_strdup(&temp[1]);
		free(r[fd]);
		return ((r[fd] = temp) == 0 ? 1 : 1);
	}
	while ((br = read(fd, &buffer, BUFF_SIZE)) > 0 &&
			(buffer[br] = '\0') == 0)
		if ((exit = process(br, &r[fd], buffer, line)) == 1)
			return (1);
	if (br == 0 && r[fd] && ft_strlen(r[fd]) > 0 && (*line = r[fd]) == *line)
		return ((r[fd] = NULL) == NULL) ? 1 : 1;
	return (0);
}
