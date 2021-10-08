#include <unistd.h>
#include <stdio.h>

void	pr_int(int num)
{
    char    c;
    int tmp = num;
    int cnt;
    int sum;
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

void	ft_print_comb2(void)
{
    int a = 0;
    int b = 1;
    char    zero = '0';
    char    sp = ' ';
    char    cm = ',';
    while (a <= 98)
    {
        b = a + 1;
        while (b <= 99)
        {
            if (a < 10 && b < 10)
            {
                write(1, &zero, 1);
                pr_int(a);

                write(1, &sp, 1);

                write(1, &zero, 1);
                pr_int(b);
            }
            else if (a < 10 && b >= 10)
            {
                write(1, &zero, 1);
                pr_int(a);

                write(1, &sp, 1);

                pr_int(b);
            }
            else if (a >= 10 && b < 10)
            {
                pr_int(a);

                write(1, &sp, 1);

                write(1, &zero, 1);
                pr_int(b);
            }
            else if (a >= 10 && b >= 10) 
            {
                pr_int(a);

                write(1, &sp, 1);

                pr_int(b);
            }
            if (a == 98 && b == 99)
            {  
            }
            else
            {
                write(1, &cm, 1);
                write(1, &sp, 1);
            }
            b++;
        }
        a++;
    }
}
int main(void)
{
    ft_print_comb2();
    //pr_int(78);
}