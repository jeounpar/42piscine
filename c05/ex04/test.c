#include <stdio.h>

int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    else if (index == 0)
        return (0);
    else if (index < 3)
        return (1);
    return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

int main()
{
    for (int i = 0; i < 11; i++)
    {
        printf("%d\n", ft_fibonacci(i));
    }
    printf("%d\n", ft_fibonacci(-5));
    return 0;
}