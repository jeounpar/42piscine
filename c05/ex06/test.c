#include <stdio.h>

int ft_is_prime(int nb)
{
    int n;
    
    n = 2;
    if (nb < 2)
        return (0);
    while (n <= nb / 2)
    {
        if (nb % n == 0)
            return (0);
        n++;
    }
    return (1);
}

int main()
{
    for (int i = 0; i < 1000; i++)
    {
        if (ft_is_prime(i))
            printf("%d\n", i);
    }
    printf("%d , %d\n", -5, ft_is_prime(-5));
    return 0;
}