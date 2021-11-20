/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:44:47 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/25 00:44:48 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	firstline_length(int fd)
{
	int		n;
	char	c;

	n = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		n++;
	}
	close(fd);
	return (n);
}

char	*read_firstline(char *filename, int len)
{
	int		fd;
	int		i;
	char	c;
	char	*str;

	fd = open(filename, O_RDONLY);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		exit (1);
	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		str[i] = c;
		i++;
	}
	str[len] = '\0';
	close(fd);
	return (str);
}

t_map	*init_map(char *str, int len)
{
	t_map	*arr;
	int		line;
	int		idx;

	arr = malloc(sizeof(t_map));
	if (arr == NULL)
		exit (1);
	line = ft_atoi(str, &idx, len);
	arr->info.line = line;
	arr->info.empty = str[idx];
	arr->info.obstacle = str[idx + 1];
	arr->info.filled = str[idx + 2];
	free (str);
	return (arr);
}
