/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:18:33 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/26 11:10:21 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdio.h>

void    ft_stdin(void)
{
    // char    c;
    // int     fd;

    // fd = open("parkbae", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// while (read(0, &c, 1))
	// {
	// 	write(fd, &c, 1);
	// }
	// fd = close(fd);
	int		ret;
	char	*buf;
	int		fd;

	fd = open("./std_input.txt", O_RDWR | O_CREAT, 0644);
	buf = (char*)malloc(51 * sizeof(char));
	while ((ret = read(0, buf, 50)))
		write(fd, buf, ret);
	close(fd);
	free(buf);
}

int	main(int argc, char **argv)
{
	t_map	**maps;
	char	*filename;
	int		i;

	i = 0;
	if (argc < 2)
		ft_stdin();
	else
		maps = (t_map **)malloc((argc - 1) * sizeof(t_map *));
	while (argc >= 2 && i < argc - 1)
	{
		filename = argv[i + 1];
		if (first_line(maps, filename, i) != -1)
		{
			maps[i]->map = map_data(filename, maps[i]);
			ft_find_square(maps[i]->map, maps[i]->info);
			for (int x = 0; x < maps[i]->info.line; x++)
				printf("%s\n",maps[i]->map[x]);
		}
		else
			ft_putstr("map error\n");
		i++;
	}
	return (0);
}
