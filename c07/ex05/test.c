/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:42:32 by jeounpar          #+#    #+#             */
/*   Updated: 2021/10/22 19:42:34 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_ok(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i] || c == '\0')
			return (1);
		i++;
	}
	return (0);
}

int		cnt_word(char *str, char *charset)
{
	int		count;
	char	*previous;
	char	*next;

	count = 0;
	previous = str;
	next = str;
	while (1)
	{
		if (is_ok(*str, charset))
			next = str;
		if (next - previous > 1)
			count++;
		if (*str == '\0')
			break ;
		previous = next;
		str++;
	}
	return (count);
}

void	words_malloc(char *str, char *charset, char **words)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	while (str[i] != '\0')
	{
		if (!is_ok(str[i], charset))
		{
			j++;
			if (is_ok(str[i + 1], charset))
			{
				words[idx] = (char *)malloc((j + 1) * sizeof(char));
				idx++;
				j = 0;
			}
		}
		i++;
	}
}

void	wr_words(char *str, char *charset, char **words)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	while (str[i] != '\0')
	{
		if (!is_ok(str[i], charset))
		{
			words[idx][j] = str[i];
			j++;
			if (is_ok(str[i + 1], charset))
			{
				words[idx][j] = '\0';
				idx++;
				j = 0;
			}
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		cnt;
	char	**words;

	cnt = cnt_word(str, charset);
	words = (char **)malloc((cnt + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	words_malloc(str, charset, words);
	wr_words(str, charset, words);
	words[cnt] = 0;
	return (words);
}


int main(void)
{
	// int i = 0;
	ft_split("Hello.,World,.!!KOKO!ZZZ.Hello.Good.World!KK!ZORO,Good,..", ",.!");
	// while (words[i] != 0)
	// {
	// 	printf("%s\n", words[i]);
	// 	i++;
	// }
	return (0);
}