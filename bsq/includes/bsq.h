/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:11:38 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/24 19:14:00 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_map{
	int		line;
	char	empty;
	char	obstacle;
	char	filled;
	int		row_size;
	char 	**map;
}	t_map;

int		ft_atoi(char *str, int *idx);
int		firstline_length(char *filename);
int		row_size(char *filename, int len);
int		open_file(char *filename);
int		skip_fristline(int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*read_firstline(char *filename, int len);
char	**map_data(char *filename, t_map *map);
void	pr_error(void);
t_map	*init_map(char *str);

#endif
