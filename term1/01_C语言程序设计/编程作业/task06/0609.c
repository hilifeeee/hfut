//****************************************
//File Name:06
//Author:Li Haoran
//Date:20199.11.14
//Student ID:2019218211
//****************************************
#include<stdio.h>
#define N 3
int main(void)
{
    float a[N][N], *p, c = 0;
    int i, j;

    p = a;
    printf("������3*3�Ķ�ά����:\n");
    for(i = 0;i < N;i++)
    {
        for(j = 0;j < N;j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    for(i = 0;i < N;i++)
    {
        for(j = 0;j < N;j++)
        {
            c += a[i][j];
        }
    }


    printf("ƽ����Ϊ��%f\n", c / 9);

    return 0;
}
