#include<stdio.h>

int main(void)
{
    float fScore[10], fAverage = 0.0f;
    int i;

    printf("������ʮλѧ���ĳɼ�:\n");
    for(i = 0;i < 10;i++)
    {
        scanf("%f", &fScore[i]);
    }
    for(i = 0;i < 10;i++)
    {
        fAverage += fScore[i];
    }
    fAverage /= 10;
    printf("ƽ����Ϊ:%.1f", fAverage);

    printf("����ƽ���ֵ�ѧ��Ϊ:\n");
    for(i = 0;i < 10;i++)
    {
        if(fScore[i] > fAverage)
            printf("%d\n", i + 1);
    }

    return 0;
}
