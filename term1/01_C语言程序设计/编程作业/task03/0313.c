//****************************************
//File Name:
//Author:
//Date:
//Student ID:
//****************************************
#include<stdio.h>

int main(void)
{
    float e, i, n, fPrecision, fItem;
    e =0;
    fPrecision = 1e-6;
    fItem = 1.0f;

    printf("����������(���ʹ���Դ�����������0):");
    scanf("%f", &n);

    if(n == 0)
    {
        for(i = 1;fItem >= fPrecision; i++)
        {
            fItem *= 1 / i;
            e += fItem;
        }
    }
    else
    {
        for(i = 1;i < n;i++)
        {
            fItem *= 1 / i;
            e += fItem;
        }
    }
    e += 1;
    printf("e��ֵΪ:%12f", e);

    return 0;
}
