/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:18:33 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/28 10:30:33 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_stdin(void)
{
	char	c;
	int		fd;

	fd = open("parkbae.file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (0);
	while (read(0, &c, 1))
		write(fd, &c, 1);
	fd = close(fd);
	return (1);
}

void	ft_std_solve(void)
{
	t_map	**maps;
	char	*filename;

	if (ft_stdin())
	{
		filename = "parkbae.file";
		maps = (t_map **)malloc(sizeof(t_map *));
		if (maps == NULL)
			exit (1);
		if (first_line(maps, filename, 0) != -1)
		{
			maps[0]->map = map_data(filename, maps[0]);
			ft_find_square(maps[0]->map, maps[0]->info);
			ft_printmap(maps[0]);
			free(maps);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}

int	ft_nostd_solve(t_map **maps, int argc, char **argv)
{
	int		i;
	char	*filename;

	i = 0;
	while (i < argc - 1)
	{
		filename = argv[i + 1];
		if (first_line(maps, filename, i) != -1)
		{
			maps[i]->map = map_data(filename, maps[i]);
			ft_find_square(maps[i]->map, maps[i]->info);
			ft_printmap(maps[i]);
		}
		else
			ft_putstr("map error\n");
		if (i != argc - 2)
			write(1, "\n", 1);
		i++;
	}
	free(maps);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	**maps;

	if (argc == 1)
		ft_std_solve();
	else
	{
		maps = (t_map **)malloc((argc - 1) * sizeof(t_map *));
		if (maps == NULL)
			return (0);
		if (!ft_nostd_solve(maps, argc, argv))
			return (0);
	}
	return (0);
}
