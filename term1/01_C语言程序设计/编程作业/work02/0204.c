//***********************************************
//File name:0204
//Author:���Ȼ
//Date:2019.10.20
//Student ID:2019218211
//***********************************************
#include<stdio.h>
#define PI 3.14159

int main(void)
{
    float fAngle, r, fArea;
    printf("����������Ͱ뾶��");
    scanf("%f%f", &fAngle, &r);

    fArea = (fAngle / 360) * PI * r * r;

    printf("���ε������:%f", fArea);

    return 0;
}
