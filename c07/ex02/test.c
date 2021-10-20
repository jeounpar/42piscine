#include <stdlib.h>
#include <stdio.h>


int ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*tmp;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	tmp = (int *)malloc(size * sizeof(int));
	if (tmp == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp[i] = min;
		min++;
		i++;
	}
	*range = tmp;
	return (size);
}

int main(void)
{
	int *arr;

	ft_ultimate_range(&arr, 1, 10);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	free(arr);
	return 0;
}