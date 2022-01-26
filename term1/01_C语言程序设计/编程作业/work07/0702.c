//****************************************
//File Name:0702
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include<stdio.h>

int CommonDivisor(int a,int b);

int main(void)
{
    int a, b, result;

    printf("�������һ������:\n");
    scanf("%d", &a);
    printf("������ڶ�������:\n");
    scanf("%d", &b);

    result = CommonDivisor(a, b);

    if(result == -1)
        printf("��������!");
    else
        printf("%d��%d�����Լ��Ϊ%d\n", a, b, result);

    return 0;
}

int CommonDivisor(int a,int b)
{
    int c, temp;

    if(a <= 0 || b <= 0)
        return(-1);

    if(b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    do
    {
        c = a % b;
        a = b;
        b = c;
    }while(c != 0);

    return(a);

}
