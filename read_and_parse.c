/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 03:45:35 by fguzman           #+#    #+#             */
/*   Updated: 2019/11/13 16:54:47 by fguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				numbers_only(char *argv)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]))
		{
			len += 1;
			while (argv[i] != '\0' && ft_isdigit(argv[i]))
				i += 1;
		}
		else if (argv[i] != ' ' && argv[i] != '-')
			ft_puterror("invalid characters or read error", 5);
		if (argv[i] == '\0')
			break ;
		i += 1;
	}
	return (len);
}

char			*number_split(char *argv)
{
	int		i;
	int		x;
	char	*tmp;
	int		neg;

	x = 0;
	i = 0;
	neg = 0;
	tmp = NULL;
	if (argv[x] == '-')
	{
		neg = x;
		x++;
	}
	if (ft_isdigit(argv[x]))
	{
		i = x;
		while (ft_isdigit(argv[i]))
			i++;
		if ((neg + 1) == x)
			x = neg;
		tmp = ft_strsub(argv, x, i);
	}
	return (tmp);
}

int				*lines(char *argv, int *size)
{
	int		i;
	int		x;
	char	*tmp;
	int		*lines;

	x = 0;
	i = 0;
	if (!(lines = (int *)malloc(sizeof(int) * numbers_only(argv))))
		ft_puterror("memory allocation error", 1);
	while (argv[x])
	{
		tmp = number_split(&argv[x]);
		x = x + ft_strlen(tmp);
		lines[i] = ft_atoi(tmp);
		i++;
		while (argv[x] == ' ')
			x++;
		free(tmp);
	}
	*size = i;
	return (lines);
}

int				count_lines(char *argv)
{
	int		fd;
	int		lines;
	char	*buff;
	int		i;
	int		x;

	x = 0;
	i = 0;
	lines = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterror("Usage: ./fdf {map path}", 2);
	while (get_next_line(fd, &buff) == 1)
	{
		if (x == 0)
			i = numbers_only(buff);
		x = numbers_only(buff);
		if (x != i)
			ft_puterror("lines don't match", 4);
		lines++;
		free(buff);
	}
	if (lines == 0)
		ft_puterror("Usage: ./fdf {map path}", 2);
	return (lines);
}

t_coords		tdia(char *argv)
{
	int				fd;
	char			*line;
	int				y;
	t_coords		temp;

	y = 0;
	temp.height = count_lines(argv);
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_puterror("Usage: ./fdf {map path}", 2);
	if (!(temp.rows = (int **)malloc(sizeof(int *) * temp.height)))
		ft_puterror("error allocating memory", 1);
	while (get_next_line(fd, &line) == 1)
	{
		temp.rows[y] = lines(line, &temp.size);
		y++;
		free(line);
	}
	if (close(fd) < 0)
		ft_puterror("error closing file wtf?", 1);
	return (temp);
}
