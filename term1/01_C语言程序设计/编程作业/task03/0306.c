//****************************************
//File Name:
//Author:
//Date:
//Student ID:
//****************************************
#include<stdio.h>

int main(void)
{
    int iNum,iMonth,iCount,iPrice;

    printf("�������·�:");
    scanf("%d", &iMonth);
    printf("������������Ʊ��:");
    scanf("%d", &iNum);
    printf("����������Ʊ�ļ۸�:");
    scanf("%d", &iPrice);


    if(iMonth==4||iMonth==5||iMonth==9||iMonth==10)
    {
        if(iNum<20)
            iCount = iNum * iPrice * 0.9f;
        else
            iCount = iNum * iPrice * 0.8f;
    }
    else
    {
        if(iNum<20)
            iCount = iNum * iPrice * 0.8f;
        else
            iCount = iNum * iPrice * 0.6f;
    }

    return 0;
}
