/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:19:23 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/26 11:28:08 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	skip_fristline(int fd)
{
	char	c;

	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
	}
	return (fd);
}

int	max_int(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
