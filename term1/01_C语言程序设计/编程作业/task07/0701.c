//****************************************
//File Name:0701
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include<stdio.h>

long long int factorial(int n);

int main(void)
{
    int n;
    long long int result;

    printf("����������:\n");
    scanf("%d", &n);

    result = factorial(n);
    if(result == -1)
        printf("����Ĳ�������\n");
    else
        printf("%d�Ľ׳���:%lld\n", n, result);

    return 0;
}

long long int factorial(int n)
{
    int i;
    long long int result = 1;

    if(n < 0)
        return(-1);
    else if(n == 0)
        return 1;
    else
    {
        for(i = 1;i <= n;i++)
        {
            result *= i;
        }
        return(result);
    }

}
