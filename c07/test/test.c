#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define NO_MATCH -1

int		ft_str_length(char *str);
int		compute_number_length(unsigned int number, int radix, bool negative);
bool	is_space(char c);
bool	is_base_valid(char *str);

int		resolve_base(char *base, char match)
{
	int		index;

	index = 0;
	while (base[index])
	{
		if (base[index] == match)
			return (index);
		index++;
	}
	return (NO_MATCH);
}

char	*ft_buffer_base(char *base, unsigned int number, bool negative)
{
	int		index;
	int		radix;
	int		length;
	char	*string;

	radix = ft_str_length(base);
	length = compute_number_length(number, radix, negative);
	//printf("length : %d, radix : %d\n",length, radix);
	if (!(string = (char *)malloc((length + 1) * sizeof(char))))
		return (0);
	if (negative)
		string[0] = '-';
	index = negative ? 1 : 0;
	while (index < length)
	{
		printf("number : %d\n",number % radix);
		string[length - (!negative) - index++] = base[number % radix];
		number /= radix;
	}
	string[length] = '\0';
	return (string);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				radix;
	int				minus;
	int				resolved;
	unsigned int	result;

	if (!is_base_valid(base_from) || !is_base_valid(base_to))
		return (NULL);
	radix = ft_str_length(base_from);
	result = 0;
	minus = 1;
	while (is_space(*nbr))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*(nbr++) == '-')
			minus *= -1;
	}
	while ((resolved = resolve_base(base_from, *nbr)) != NO_MATCH)
	{
		result *= radix;
		result += resolved;
		nbr++;
	}
	minus = result == 0 ? 1 : minus;
	printf("\n\nresult : %d, minus : %d\n", result, minus);
	return (ft_buffer_base(base_to, result, (minus > 0 ? false : true)));
}