//***********************************************
//File name:0212
//Author:���Ȼ
//Date:2019.10.20
//Student ID:2019218211
//***********************************************
#include<stdio.h>

int main (void)
{
    float a;
    printf("������a��ֵ:");
    scanf("%f", &a);

    if(a < 0)
        printf("%.2fΪ����", a);
    else if(a > 0)
        printf("%.2fΪ����", a);
    else
        printf("%.2fΪ0", a);

    return 0;
}
