//****************************************
//File Name:06
//Author:Li Haoran
//Date:20199.11.14
//Student ID:2019218211
//****************************************
#include<stdio.h>
#include<string.h>

int main(void)
{
    char str1[80], str2[80];
    char *p, *q;
    p = str1;
    q = str2;

    printf("�������һ���ַ���:\n");
    gets(str1);
    printf("������ڶ����ַ���:\n");
    gets(str2);

    while(*p)
    {
        p++;
    }
    while(*p++ = *q++);

    printf("%s",str1);

    return 0;
}
