//****************************************
//File Name:0506.c
//Author:Li Haoran
//Date:2019.11.08
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
    float fNum[10];
    int i, j, k,temp;

    printf("������10�����������ݣ�\n");
    for(i = 0;i < 10;i++)
    {
        scanf("%f", &fNum[i]);
    }
    for(i = 0;i < 10;i++)
    {
        k = i;
        for(j = i;j < 10;j++)
        {
            if(fNum[j] >fNum[k]);
                k = j;
        }
        if(k != i)
        {
            temp = fNum[k];
            fNum[k] = fNum[i];
            fNum[i] = temp;
        }
    }

    printf("�������к�Ϊ:\n");
    for(i = 0;i < 10;i++)
    {
        printf("%f\n", fNum[i]);
    }

    return 0;
}
