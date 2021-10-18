#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    int n;

    n = nb;
    if (nb < 0)
        return (0);
    if (power == 0 || (nb == 0 && power == 0))
        return (1);
    while (power > 1)
    {
        n *= nb;
        power--;
    }
    return (n);
}
int main()
{
    printf("%d\n", ft_iterative_power(3, 4));
    printf("%d\n", ft_iterative_power(0, 0));
    printf("%d\n", ft_iterative_power(0, 5));
    printf("%d\n", ft_iterative_power(1, 7));
    printf("%d\n", ft_iterative_power(2, 0));

    return 0;
}