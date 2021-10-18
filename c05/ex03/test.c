#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    if (power == 0 || (nb == 0 && power == 0))
        return (1);
    return (nb * ft_recursive_power(nb, power - 1));
}
int main()
{
    printf("%d\n", ft_recursive_power(3, 4));
    printf("%d\n", ft_recursive_power(0, 0));
    printf("%d\n", ft_recursive_power(0, 5));
    printf("%d\n", ft_recursive_power(1, 7));
    printf("%d\n", ft_recursive_power(2, 0));
    printf("%d\n", ft_recursive_power(-2, 0));
    printf("%d\n", ft_recursive_power(-5, 2));
    printf("%d\n", ft_recursive_power(-3, 3));
    printf("%d\n", ft_recursive_power(9, 2));
    printf("%d\n", ft_recursive_power(-3, 0));
    return 0;
}