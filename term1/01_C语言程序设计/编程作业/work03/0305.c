//****************************************
//File Name:
//Author:
//Date:
//Student ID:
//****************************************
#include<stdio.h>

int main(void)
{
    float a, b, c;
    printf("����������������:");
    scanf("%f%f%f", &a, &b, &c);
    if(a+b<=c||b+c<=a||c+a<=b)
        printf("�޷���������Σ�");
    else if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b)
        printf("����������ֱ��������");
    else if(a==b==c)
        printf("�������ǵ���������");
    else if(a==b||a==c||c==a)
        printf("�������ǵȱ�������");
    else
        printf("�������ǲ�����������");

    return 0;

}

