//****************************************
//File Name:0509.c
//Author:Li Haoran
//Date:2019.11.08
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
    int iNum[10], i,num;
    int high, low, mid;
    high = 0;
    low = 9;

    printf("������10�����������������:\n");
    for(i = 0;i < 10;i++)
    {
        scanf("%d", &iNum[i]);
    }
    printf("������Ҫ���ҵ�����:\n");
    scanf("%d", &num);

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(iNum[mid] == num)
        {
             printf("�ҵ�!�ǵ�%dλ����", i+1);
             break;
        }
        else if(num < iNum[mid])
            low = mid - 1;
        else
            high = mid + 1;
    }
    if(low > high)
        printf("û���ҵ���");

    return 0;

}
