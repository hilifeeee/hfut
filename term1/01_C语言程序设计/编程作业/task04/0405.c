#include<stdio.h>

int main(void)
{
    char str[80];
    int i, iNum = 0;

    printf("�������ַ���:\n");
    gets(str);
    for(i = 0;str[i] != '\0';i++)
    {
        if((int)str[i] % 10 == 3)
        {
            iNum++;
        }

    }
    printf("ASCII��ֵ��λ�������ַ���%d��", iNum);

    return 0;
}
