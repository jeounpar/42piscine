/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 02:14:00 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/25 02:14:00 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include <stdio.h>

int	check_char(t_map *arr)
{
	// line 의 수가 1보다 작은지 검사
	if (arr->info.line < 1)
		return (-1);
	// 첫행에 중복 문자 검사
	if ((arr->info.empty == arr->info.obstacle)
	|| (arr->info.obstacle == arr->info.filled)
	|| (arr->info.filled == arr->info.empty))
		return (-1);
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
			// 출력 불가능한 문자 & 첫 행에 없는 문자 & 각 행의 길이가 같은지 검사
			if ((c < 33 || c > 126) || (c != arr->info.empty && c != arr->info.obstacle))
				return (-1);
			len++;
		}
		if (c == '\n' && cnt == 1)
			max_num = len;
		if (c == '\n' && cnt > 1)
			if (len % max_num != 0)
				return (-1);
	}
	close(fd);
	// 모든 행의 길이 검사 && 입력으로 주어진 행의 개수와 일치하는지  & 최소 한개의 상자 검사
	if (len % cnt != 0 || cnt != line || len < 1) 
		return (-1);
	arr->info.row_size = len / cnt;
	return (1);
}

int	first_line(t_map **arr, char *filename, int idx)
{
	int		len;
	int		fd;
	int		tmp;
	char	*firstline_data;

	fd = open(filename, O_RDONLY);
	if (fd == -1) // file open 실패
		return (-1);	
	len = firstline_length(fd);
	firstline_data = read_firstline(filename, len);
	ft_atoi(firstline_data, &tmp);
	if (len - tmp < 3)
		return (-1);
	if (firstline_data[0] == '\0') //첫번째 행에 어떠한 문자도 없을 때
		return (-1);
	arr[idx] = init_map(firstline_data);
	if (check_char(arr[idx]) == -1)
		return (-1);
	if (row_size(filename, arr[idx]->info.line, arr[idx]) == -1)
		return (-1);
	return (1);
}
