//****************************************
//File Name:06
//Author:Li Haoran
//Date:20199.11.14
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
    char str[80], a, *p;

    printf("�������ַ���:\n");
    gets(str);
    printf("������Ҫɾȥ���ַ�:\n");
    scanf("%c", &a);

    for(p = str;*p;p++)
    {
        if(*p != a)
        {
            printf("%c", *p);
        }
    }

    return 0;
}
