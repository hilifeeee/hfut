//****************************************
//File Name:0507.c
//Author:Li Haoran
//Date:2019.11.08
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
    float fNum[10];
    int i, j, temp;

    printf("������ʮ������:\n");
    for(i = 0;i < 10;i++)
    {
        scanf("%f", &fNum[i]);
    }
    for(i = 0;i < 5;i++)
    {
        j = 9 - i;
        temp = fNum[i];
        fNum[i] = fNum[j];
        fNum[j] = temp;
    }
    printf("�����\n");
    for(i = 0;i < 10;i++)
    {
        printf("a[%d] = %f\n", i, fNum[i]);
    }
}
