//****************************************
//File Name:0514.c
//Author:Li Haoran
//Date:2019.11.08
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
    char str1[80] = {0}, str2[80] = {0}, str3[80] = {0};
    int i;

    printf("�������ַ���1:");
    gets(str1);
    printf("�������ַ���2:");
    gets(str2);

    for(i = 0;i < strlen(str1);i++)
    {
        str3[i] = str1[i];
    }
    for(i = strlen(str1);i < strlen(str1) + strlen(str2);i++)
    {
        str3[i] = str2[i - strlen(str1)];
    }

    printf("���Ӻ�Ľ��Ϊ:\n");
    puts(str3);

    return 0;
}
