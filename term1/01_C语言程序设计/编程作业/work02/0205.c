//***********************************************
//File name:0205
//Author:���Ȼ
//Date:2019.10.20
//Student ID:2019218211
//***********************************************
#include<stdio.h>
#include<math.h>

int main(void)
{
    float x, y, z, fDistance;
    float a, b, c;
    printf("������x,y,z:");
    scanf("%f%f%f", &x, &y, &z);

    fDistance = sqrt(x * x + y * y + z * z);
    a = acos(x/fDistance);
    b = acos(y/fDistance);
    c = acos(z/fDistance);

    printf("��ԭ��ľ��� = %f", fDistance);
    printf("��x��ļн�= %f", a);
    printf("��y��ļн�= %f", b);
    printf("��z��ļн�= %f", c);

    return 0;
}

