//****************************************
//File Name:0510.c
//Author:Li Haoran
//Date:2019.11.08
//Student ID:2019218211
//****************************************
#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[80];
    int i, iFlag = 0;

    printf("�������ַ���:");
    gets(str);

    for(i = 0;i < (strlen(str) / 2) - 1;i++)
    {
        if(str[i] != str[strlen(str)-i-1])
        {
            printf("���ַ������ǻ���\n");
            iFlag = 1;
            break;
        }
    }
    if(iFlag == 0)
        printf("���ַ����ǻ���\n");

    return 0;
}
