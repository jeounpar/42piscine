#include <stdio.h>
#include <stdlib.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	// printf("%s\n", ft_convert_base("1234", "0123456789", "0123456789ABCDEF"));
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "0123456789ABCDEF"));
	// printf("%s\n", ft_convert_base("1010101", "01", "0123456789ABCDEF"));
	// printf("%s\n", ft_convert_base("-1234", "0123456789", "0123456789ABCDEF"));
	// printf("%s\n", ft_convert_base("10101010", "01", "0123456789ABCDEF"));
	// printf("%s\n", ft_convert_base("1234", "01234567", "0123456789ABCDEF"));
	// printf("%s\n", ft_convert_base("-2147483648", "0123456789", "0123456789"));
	printf("%s\n", ft_convert_base("0", "0123456789", "0123456789"));
	// printf("%s\n", ft_convert_base("-2147483648", "0123456789", "0123456789ABCDEF"));
	return (0);
}