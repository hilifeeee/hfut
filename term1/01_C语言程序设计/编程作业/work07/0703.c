//****************************************
//File Name:0703
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include<stdio.h>

int num(char str[]);

int main(void)
{
    char str[80];
    int result = 0;

    printf("�������ַ���:\n");
    gets(str);

    result = num(str);

    if(result == 0)
        printf("���ַ�����û������!\n");
    else
        printf("���ַ�������%d������\n", result);

    return 0;
}
int num(char str[])
{
    int num = 0;
    char *p;
    p = str;

    for(p = str;*p;p++)
    {
        if(*p >= '0' && *p <= '9')
           num++;
    }

    return(num);
}
