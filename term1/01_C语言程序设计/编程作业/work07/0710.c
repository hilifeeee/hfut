//****************************************
//File Name:0708
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include<stdio.h>
#include<stdlib.h>

void statistics(char *p, int iCount[4]);

int main(void)
{
    char str[80];
    int iCount[4] = {0};

    printf("�������ַ���:\n");
    gets(str);

    statistics(str,iCount);
    printf("��д��ĸ��%d��\n", iCount[0]);
    printf("Сд��ĸ��%d��\n", iCount[1]);
    printf("������%d��\n", iCount[2]);
    printf("�����ַ���%d��\n", iCount[3]);

    return 0;
}

void statistics(char *p, int iCount[4])
{
    for(;*p;p++)
    {
        if(*p >= 'A' && *p <= 'Z')
            iCount[0] += 1;
        else if(*p >= 'a' && *p <= 'z')
            iCount[1] += 1;
        else if(*p >='0' && *p <= '9')
            iCount[2] += 1;
        else
            iCount[3] += 1;
    }
}
