//****************************************
//File Name:0211.c
//Author:Li Haoran
//Date:2019.11.08
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
    char str[80], x;
    int i, iNum = 0;

    printf("�������ַ���:\n");
    gets(str);
    printf("����������ַ�:\n");
    scanf("%c", &x);

    for(i = 0;str[i] != '\0';i++)
    {
       if(str[i] == x)
            iNum += 1;
    }
    if(iNum == 0)
        printf("û���ҵ�!\n");
    else
        printf("%c���ַ����г�����%d��", x, iNum);

    return 0;

}
