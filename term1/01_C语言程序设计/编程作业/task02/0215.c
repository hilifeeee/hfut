//***********************************************
//File name:02
//Author:���Ȼ
//Date:2019.10.20
//Student ID:2019218211
//***********************************************
#include<stdio.h>

int main(void)
{
    int a;
    printf("���������:");
    scanf("%d", &a);

    if(a % 100 == 0)
    {
        if(a % 400 == 0)
            printf("%d������", a);
        else
            printf("%d��ƽ��", a);
    }
    else
    {
        if(a % 4 == 0)
            printf("%d������", a);
        else
            printf("%d��ƽ��", a);
    }
    return 0;

}
