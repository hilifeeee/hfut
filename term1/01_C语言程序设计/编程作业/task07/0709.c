//****************************************
//File Name:0709
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include"traingle.h"

int main(void)
{
    int a, b;
    double result, ra, rb;
    printf("������sin�Ķ���:\n");
    scanf("%d", &a);
    printf("������cos�Ķ���:\n");
    scanf("%d", &b);

    ra = sinX(a);
    rb = cosX(b);
    result = ra + rb;

    printf("sin%d = %f\n", a, ra);
    printf("cos%d = %f\n", b, rb);
    printf("���Ϊ%f\n", result);

    return 0;

}
