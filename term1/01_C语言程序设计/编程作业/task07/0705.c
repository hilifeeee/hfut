//****************************************
//File Name:0705
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include<stdio.h>

int PrimeNumber(int n);

int main(void)
{
    int i, Number = 0;

    for(i = 100;i <= 200;i++)
    {
        if(PrimeNumber(i))
            Number++;
    }

    printf("100��200֮���������%d��\n", Number);

    return 0;
}

int PrimeNumber(int n)
{
    int i;

    for(i = 2;i < (n / 2);i++)
    {
        if(n % i == 0)
            return(0);
    }

    return 1;
}
