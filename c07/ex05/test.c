#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

char    *wr_str(char *dest, char *str, int st, int ed)
{
	int i;

	i = 0;
	printf("\nstart : %d, end : %d\n", st, ed);
	while (st < ed)
	{
		dest[i] = str[st];
		i++;
		st++;
	}
	dest[ed - st + 1] = '\0';
	printf("%s\n", dest);
	return (dest);
}

char	**wr_arr(char *str, char *charset, char **arr)
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
			wr_str(arr[index], str, i, i + j);
			i = i + j;
			printf("index : %d\n", index);
			index++;
		}
	}
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	int		cnt;
	char	**arr;

	cnt = str_count(str, charset);
	arr = (char **)malloc((cnt + 1) * sizeof(char));
	if (arr == NULL)
		return (0);
	printf("cnt : %d\n", cnt);
	arr[cnt] = 0;
	wr_arr(str, charset, arr);
	//printf("%s\n", arr[0]);
	return (arr);
}



int main(void)
{
	char **str;

	str = ft_split("aba1234a123bb12aaa1aba", "ab");
	printf("%s\n", str[1]);
	return 0;
}