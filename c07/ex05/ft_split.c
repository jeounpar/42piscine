/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:08:08 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/21 10:08:11 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	str_count(char *str, char *cs)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if(str_sep(str[i + 1], cs)&& !str_sep(str[i], cs))
			cnt++;
		i++;
	}
	return (cnt);
}

void	wr_str(char *dest, char *str, char *charset, int st)
{
	int	i;

	i = st;
	while (sep_word(str[i], charset) == 0)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

void	**wr_arr(char *str, char *charset, char **arr, int cnt)
{
	int	i;
	int	j;
	int index;

	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (str_sep(str[i], charset))
			i++;
		else
		{
			j = 0;
			while (!str_sep(str[i + j], charset))
				j++;
			arr[index] = (char *)malloc((j + 1) * sizeof(char));
			if (arr[index] == NULL)
				return (0);
			wr_str(arr[index], str, charset, i);
			i = i + j;
			index++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		cnt;
	char	**arr;

	cnt = str_count(str, charset);
	arr = (char **)malloc((cnt + 1) * sizeof(char));
	if (arr == NULL)
		return (0);
	arr[cnt] = 0;
	wr_arr(str, charset, arr, cnt);
	return (arr);
}