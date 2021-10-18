#include <stdio.h>

int ft_sqrt(int nb)
{
    int n;

    n = 1;
    if(nb <= 0)
        return (0);
    else
    {
        while (n * n <= nb)
        {
            if (n > 46340)
                return (0);
            else if (n * n == nb)
                return (n);
            n++;
        }
    }
    return (0);
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", ft_sqrt(i));
    }
    printf("%d\n", ft_sqrt(-5));
    return 0;
}