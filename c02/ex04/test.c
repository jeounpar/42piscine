#include <stdio.h>

int	ft_str_is_alpha_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			i++;
		else
			return (0);
	}
	return (1);
}

int main(void)
{
	char str[] ="abcdAfg";

	printf("%d TEST\n", ft_str_is_alpha_lowercase(str));
}
