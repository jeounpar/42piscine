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

#include "bsq.h"
#include <stdio.h>

int	row_size(char *filename, int row)
{
	int		fd;
	int		cnt;
	int		len;
	char	c;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		pr_error();
	cnt = -1;
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			cnt++;
		else if (cnt != -1 && c != '\n')
			len++;
		else if (c != '\n' && (c < 33 || c > 126)) // 출력 가능한 문자 검사
			return (-1);
	}
	close(fd);
	// 모든 행의 길이 검사 && 입력으로 주어진 행의 개수와 일치하는지 검사
	if (len % cnt != 0 || cnt != row) 
		return (-1);
	return (len / cnt);
}
