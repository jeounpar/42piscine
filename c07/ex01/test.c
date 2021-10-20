#include <stdlib.h>
#include <stdio.h>


int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	size = max - min;
	if (min >= max)
		return (0);
	arr = (int *)malloc(size * sizeof(int));
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}

int main(void)
{
	int *arr;

	arr = ft_range(-5, 5);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("%d\n", sizeof(arr));
	free(arr);
	return 0;
}