//****************************************
//File Name:
//Author:
//Date:
//Student ID:
//****************************************
#include<stdio.h>

int main(void)
{
    float fSum, fA, fB, fC, fD;
    printf("��ֱ�������,˵,��,д�ĳɼ�:\n");
    scanf("%f%f%f%f", &fA, &fB, &fC, &fD);

    fSum = (fA + fB + fC + fD)/4;
    if(fA<5.00f||fB<5.00f||fC<5.00f||fD<5.00f)
        printf("������˼�ɼ�δ�ϸ�");
    else
    {
        //��������
        if(fSum - (int)fSum >= 0.50f)
            fSum ==(int)fSum;
        else if(fSum - (int)fSum >= 0.25f)
            fSum == (int)fSum + 0.50f;

        if(fSum >=6.00f)
            printf("��ϲ����������˼�ɼ��ϸ��ˣ�");
        else
            printf("������˼�ɼ�δ�ϸ�");
    }
    return 0;
}
