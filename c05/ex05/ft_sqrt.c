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