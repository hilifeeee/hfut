//****************************************
//File Name:0505.c
//Author:Li Haoran
//Date:2019.11.08
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
    int iNum[10], i, j;
    int temp;

    printf("������ʮ����������:\n");
    for(i = 0;i < 10;i++)
    {
        scanf("%d", &iNum[i]);
    }
    for(i = 0;i < 10;i++)
    {
        for(j = 0;j < 10 - i - 1;j++)
        {
            if(iNum[j] > iNum[j+1])
            {
                temp = iNum[j+1];
                iNum[j+1] = iNum[j];
                iNum[j] = temp;
            }
        }
    }

    printf("�����Ľ��Ϊ��\n");
    for(i = 0;i < 10;i++)
    {
        printf("%d\n", iNum[i]);
    }

}
