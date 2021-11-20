/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:14:00 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/27 21:54:50 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	check_char(t_map *arr)
{
	if (arr->info.line < 1)
		return (-1);
	if ((arr->info.empty == arr->info.obstacle)
		|| (arr->info.obstacle == arr->info.filled)
		|| (arr->info.filled == arr->info.empty))
		return (-1);
	return (1);
}

int	get_maxnum(char c, int *max_num, int cnt, int len)
{
	if (c == '\n' && cnt == 1)
		*max_num = len;
	if (c == '\n' && cnt > 1)
		if (len % *max_num != 0)
			return (-1);
	return (1);
}

int	check_nums(int cnt, int len, int line, t_map *arr)
{
	if (cnt < 1 || len % cnt != 0 || cnt != line || len < 1)
		return (-1);
	arr->info.row_size = len / cnt;
	return (1);
}

int	row_size(char *filename, int line, t_map *arr)
{
	int		fd;
	int		cnt;
	int		len;
	int		max_num;
	char	c;

	fd = open(filename, O_RDONLY);
	cnt = -1;
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			cnt++;
		if (cnt != -1 && c != '\n')
		{
			if ((c < 33 || c > 126)
				|| (c != arr->info.empty && c != arr->info.obstacle))
				return (-1);
			len++;
		}
		if (get_maxnum(c, &max_num, cnt, len) < 0)
			return (-1);
	}
	close(fd);
	return (check_nums(cnt, len, line, arr));
}

int	first_line(t_map **arr, char *filename, int idx)
{
	int		len;
	int		fd;
	int		tmp;
	char	*firstline_data;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	len = firstline_length(fd);
	firstline_data = read_firstline(filename, len);
	if (len < 4 || firstline_data[0] == '\0')
		return (-1);
	if (ft_atoi(firstline_data, &tmp, len - 3) < 1)
		return (-1);
	arr[idx] = init_map(firstline_data, len - 3);
	if (check_char(arr[idx]) == -1)
		return (-1);
	if (row_size(filename, arr[idx]->info.line, arr[idx]) == -1)
		return (-1);
	return (1);
}
