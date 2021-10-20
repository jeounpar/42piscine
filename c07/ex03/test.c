#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_all_len(char **strs, int size)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = 0;
	while (i < size)
	{
		tmp = strs[i];
		len += ft_strlen(tmp);
		i++;
	}
	return (len);
}

int		main(void)
{
	char	**strs;

	strs = (char**)malloc(3 * sizeof(strs));
	strs[0] = "123";
	strs[1] = "456";
	strs[2] = "789";
	printf("%d\n", ft_all_len(strs, 3));
	return 0;
}