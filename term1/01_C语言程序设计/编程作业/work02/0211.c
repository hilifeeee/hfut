//***********************************************
//File name:0211
//Author:���Ȼ
//Date:2019.10.20
//Student ID:2019218211
//***********************************************
#include<stdio.h>

int main(void)
{
    int a, b, c, d, e;
    printf("������һ����λ��:");
    scanf("%d", &a);

    b = a % 10;
    c = (a / 10) % 10;
    d = (a / 100) % 10;
    e = a / 1000;

    printf("��λΪ:%d\n", b);
    printf("ʮλΪ:%d\n", c);
    printf("��λΪ:%d\n", d);
    printf("ǧλΪ:%d\n", e);

    return 0;

}
