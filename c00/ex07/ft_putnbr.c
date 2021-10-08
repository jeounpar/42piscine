#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int num)
{
    char    c;
    int tmp;
    int cnt;
    int sum;
    // printf("num : %d\n", num);
    if (num < 0)
    {
        num = num * (-1);
        write (1, &"-", 1);
    }
    tmp = num;
    while (num >= 0)
    {
        if (num < 10)
        {
            c = num + '0';
            write (1, &c, 1);
            break;
        }
        cnt = 0;
        while (tmp > 9)
        {
            tmp = tmp / 10;
            cnt ++;
        }
        c = tmp + '0';
        write (1, &c, 1);
        sum = 1;
        for (int i=1; i<=cnt;i++)
        {
            sum = sum * 10;
        }
        num = num - tmp * sum;
        tmp = num;
    }
}

int main(void)
{
    ft_putnbr(-123456789);
    write (1, &"\n", 1);
    ft_putnbr(123456789);
}