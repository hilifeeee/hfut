//****************************************
//File Name:06
//Author:Li Haoran
//Date:20199.11.14
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
    int a[10], *p, max = 0, *q;
    p = a;

    printf("������10������:");
    for(p = a;p < a + 10;p++)
    {
        scanf("%d", p);
    }

    for(p = a;p < a + 10;p++)
    {
        if(*p > max)
        {
            max = *p;
            q = p;
        }
    }

    printf("���ֵΪ%d��λ��Ϊ%d", max, q-a);

    return 0;
}
