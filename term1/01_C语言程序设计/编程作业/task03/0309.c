//****************************************
//File Name:
//Author:
//Date:
//Student ID:
//****************************************
#include<stdio.h>

int main(void)
{
    int i, iNum = 0;
    printf("�밴�س���ʼ");
    getchar();
    //��һ��forѭ��
    for(i = 0;i < 10000;i++)
    {
        if(i % 3 == 0)
            iNum += i;
    }
    printf("forѭ���Ľ����:%d\n", iNum);

    //�ڶ���whileѭ��
    i = 0;
    iNum = 0;
    while(i <
           10000)
    {
        if(i % 3 == 0)
            iNum += i;
        i++;
    }
    printf("whileѭ���Ľ����:%d\n", iNum);

    //������do whileѭ��
    i = 0;
    iNum = 0;
    do{
        if(i % 3 == 0)
            iNum += i;
        i++;
    }while(i < 10000);
    printf("do whileѭ���Ľ����:%d\n", iNum);

    return 0;
}
