int ft_iterative_factorial(int nb)
{
    int n;

    n = 1;
    if (nb < 0)
        return (0);
    else if (nb <= 1)
        return (1);
    else
    {
        while (nb > 0)
        {
            n *= nb;
            nb--;
        }
    }
    return (n);
}