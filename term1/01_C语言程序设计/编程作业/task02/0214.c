//***********************************************
//File name:0214
//Author:���Ȼ
//Date:2019.10.20
//Student ID:2019218211
//***********************************************
#include<stdio.h>

int main(void)
{
    char a;
    printf("�������ַ�:\n");
    scanf("%c", &a);

    if(a >= 'a' && a <= 'z')
        printf("%c��Сд��ĸ", a);
    else if(a >= 'A' && a < 'a')
        printf("%c�Ǵ�д��ĸ", a);
    else if(a >= '0' && a <= '9')
        printf("%c������", a);
    else
        printf("%c�������ַ�", a);
}
