#include<stdio.h>
#include<string.h>

int main(void)
{
    int i, flag = 1;
    char str[80];
    printf("������ʮ�����ַ���:");
    gets(str);

    for(i = 0;i < strlen(str);i++)
    {
        if(str[i] == '-'||str[i] == '+')
        {
            if(i != 0)
            {
                printf("�������");
                break;
            }
        }
        else if(str[i] > '9' || str[i] < '0')
        {
            printf("�������");
            flag = 0;
            break;
        }
    }

    if(flag == 1)
    {
        if(str[0] != '+')
        {
            puts(str);
        }
        else
        {
            for(i = 1;str[i] < strlen(str);i++)
                printf("%c", str[i]);
        }
    }
    return 0;
}
