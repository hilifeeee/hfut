//****************************************
//File Name:
//Author:
//Date:
//Student ID:
//****************************************
#include<stdio.h>

int main(void)
{
    int iYear, iMonth, iDay;
    printf("���������:");
    scanf("%d", &iYear);
    printf("�������·�:");
    scanf("%d", &iMonth);

    if(iMonth == 2)
    {
        if(iYear%100==0&&iYear%400!=0||iYear%4==0)
            printf("������29��");
        else
            printf("������28��");
    }
    else
    {
        if(iMonth==4||iMonth==6||iMonth==9||iMonth==11)
            printf("������30��\n");
        else
            printf("������31��\n");
    }


    return 0;
}
