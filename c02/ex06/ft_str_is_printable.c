int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32) && (str[i] > 126))
			return (0);
		else
			i++;
	}
	return (1);
}
