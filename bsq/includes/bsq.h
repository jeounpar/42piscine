/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:11:38 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/26 11:17:52 by ibae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_info
{
	int		line;
	int		row_size;
	char	empty;
	char	obstacle;
	char	filled;
}	t_info;

typedef struct	s_map{
	char 	**map;
	t_info	info;
}	t_map;

typedef struct	s_square
{
	int	max_size;
	int	x_pos;
	int	y_pos;
}	t_square;

int		ft_atoi(char *str, int *idx);
int		firstline_length(int fd);
int		open_file(char *filename);
int		skip_fristline(int fd);
int		first_line(t_map **arr, char *filename, int idx);
int		max_int(int a, int b);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_find_square(char **arr, t_info map_info);
void	ft_printmap(t_map *arr);
char	*read_firstline(char *filename, int len);
char	**map_data(char *filename, t_map *map);
void	pr_error(void);
t_map	*init_map(char *str);

#endif
