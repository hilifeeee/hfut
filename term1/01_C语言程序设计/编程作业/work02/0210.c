//***********************************************
//File name:0210
//Author:���Ȼ
//Date:2019.10.20
//Student ID:���Ȼ
//***********************************************
#include<stdio.h>

int main(void)
{
    int a, b, temp;
    printf("������a,b:");
    scanf("%d%d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    printf("a = %d\nb = %d\n", a, b);;

    return 0;

}
