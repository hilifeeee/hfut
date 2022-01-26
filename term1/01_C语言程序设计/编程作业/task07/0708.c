//****************************************
//File Name:0708
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include<stdio.h>
#include<stdlib.h>

int symmetry(int **p, int n);

int main(void)
{
    int **array = NULL;
    int i, j, n = 0;
    int result = 0;
    printf("�����뷽��Ľ�:\n");
    scanf("%d",&n);

    array = (int**)malloc(sizeof(int*)*n);
    for(i = 0;i < n;i++)
    {
        array[i] = (int*)malloc(sizeof(int)*n);
    }
    printf("����������Ԫ��:\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    result = symmetry(array, n);
    printf("%d", result);

    if(result == 1)
        printf("�������ǶԳ����飡\n");
    else
        printf("�����鲻�ǶԳ����飡\n");

    return 0;
}

int symmetry(int **p, int n)
{
    int i, j;

    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(p[i][j] != p[j][i])
                return 0;
        }
    }
    return 1;
}
