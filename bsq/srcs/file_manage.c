/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:19:23 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/25 17:19:24 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		pr_error();
	return (fd);
}

int	skip_fristline(int fd)
{
	char	c;

	while (read(fd, &c, 1))
	if (c == '\n')
		break;
	return (fd);
}
