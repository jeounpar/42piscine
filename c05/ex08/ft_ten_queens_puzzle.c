void    init_arr(int **arr)
{
    int i;
    int j;

    i = 0;
    while (i < 10)
    {
        j = 0;
        while (j < 10)
        {
            arr[i][j] = 0;
            j++;
        }
        i++;
    }
    
}

void    
int ft_ten_queens_puzzle(void)
{
    int arr[10][10];

    init_arr(arr);
}