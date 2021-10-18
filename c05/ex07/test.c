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

int ft_find_next_prime(int nb)
{
    int n;

    n = nb;
    while (1)
    {
        if (ft_is_prime(n))
            return (n);
        n++;
    }
}

int main()
{
    printf("%d\n", ft_find_next_prime(3));
    printf("%d\n", ft_find_next_prime(4));
    printf("%d\n", ft_find_next_prime(6));
    printf("%d\n", ft_find_next_prime(8));
    printf("%d\n", ft_find_next_prime(12));
    printf("%d\n", ft_find_next_prime(14));
    printf("%d\n", ft_find_next_prime(18));
    return 0;
}