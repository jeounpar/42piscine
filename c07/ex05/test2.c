#include <stdlib.h>

int		sep_word(char c, char *charset)
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

int		word_cnt(char *str, char *charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (sep_word(str[i + 1], charset) == 1
			&& sep_word(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (sep_word(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_arr(char **arr, char *str, char *charset)
{
	int i;
	int j;
	int idx;

	idx = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_separator(str[i + j], charset) == 0)
				j++;
			arr[idx] = (char*)malloc(sizeof(char) * (j + 1));
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		cnt;

	cnt = word_cnt(str, charset);
	arr = (char**)malloc((cnt + 1) * sizeof(char *));
    if (arr == NULL)
        return (0);
    arr[cnt] = 0;
	write_arr(arr, str, charset);
	return (arr);
}