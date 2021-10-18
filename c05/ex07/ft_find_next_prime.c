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