#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int		main(void)
{
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("0", "01"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("abcd1", "0123456789abcdef"));
	fflush(stdout);
}