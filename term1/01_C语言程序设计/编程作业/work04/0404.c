#include<stdio.h>

int main(void)
{
    float a[4][5], b[4] = {0};
    int i, j;

    printf("������20����:\n");
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 5;j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 5;j++)
        {
            b[i] += a[i][j];
        }
    }
    for(i = 0;i < 4;i++)
    {
        printf("��%d�еĺ�Ϊ:%f\n", i + 1, b[i]);
    }
    return 0;
}
