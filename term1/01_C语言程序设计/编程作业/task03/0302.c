//****************************************
//File Name:
//Author:
//Date:
//Student ID:
//****************************************
#include<stdio.h>

int main(void)
{
    int iMonth;
    do
    {
        printf("�������·�:");
        scanf("%d", &iMonth);
        if(iMonth<1||iMonth>12)
            printf("�������");
    }while(iMonth<1||iMonth>12)

    switch(iMonth)
        case 1:printf("����Ӣ����January");break;
        case 2:printf("����Ӣ����February");break;
        case 3:printf("����Ӣ����January");break;
        case 4:printf("����Ӣ����January");break;
        case 5:printf("����Ӣ����January");break;
        case 6:printf("����Ӣ����January");break;
        case 7:printf("����Ӣ����January");break;
        case 8:printf("����Ӣ����January");break;
        case 9:printf("����Ӣ����January");break;
        case 10:printf("����Ӣ����January");break;
        case 11:printf("����Ӣ����January");break;
        case 12:printf("����Ӣ����January");break;


    return 0;

}

