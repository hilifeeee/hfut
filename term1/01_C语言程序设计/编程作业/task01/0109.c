/* example1-9 */
#include<stdio.h>
#include<math.h>

int main(void)
{
    float x, y, dDistance, dAngle;

    printf("������x��ֵ:");
    scanf("%f", &x);
    printf("������y��ֵ:");
    scanf("%f", &y);

    dDistance = sqrt((x * x)+(y * y));
    dAngle = atan(y / x);

    printf("The Distance is:%f\n", dDistance);
    printf("The Angle is:%f rad\n", dAngle);

    return 0;
}




