//****************************************
//File Name:0706
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include<stdio.h>

int scale(char str[]);

int main(void)
{
    char str[80];
    int i, result;

    printf("������˽����ַ���:\n");
    gets(str);

    result = scale(str);

    if(result == -1)
        printf("�������!\n");
    else
        printf("ת�����ʮ������Ϊ:%d\n", result);

    return 0;
}

int scale(char str[])
{
    int i, j = 1, result = 0;

    for(i = 0;str[i];i++)
    {
        if(str[i] <'0'||str[i] > '7')
            return(-1);
    }

    for(i = 0;str[i];i++)
    {
        str[i] -= '0';
        result += str[i];
        result *= j;
        j *= 8;
    }
    return (result);
}
