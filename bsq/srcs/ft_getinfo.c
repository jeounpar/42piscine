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

int	firstline_length(char *filename)
{
	int		fd;
	int		len;
	char	c;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		pr_error();
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		len++;
	}
	close(fd);
	return (len);
}

char	*read_firstline(char *filename, int len)
{
	int		fd;
	int		i;
	char	c;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		pr_error();
	str = malloc((len + 1) * sizeof(char));
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

t_map	*init_map(char *str)
{
	t_map	*arr;
	int		line;
	int		idx;

	arr = malloc(sizeof(t_map));
	if (arr == NULL)
		return (NULL);
	line = ft_atoi(str, &idx);
	arr->line = line;
	arr->empty = str[idx];
	arr->obstacle = str[idx + 1];
	arr->filled = str[idx + 2];
	free(str);
	return (arr);	
}