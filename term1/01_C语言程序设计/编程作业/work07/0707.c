//****************************************
//File Name:0707
//Author:Li Haoran
//Date:2019.11.23
//Student ID:2019218211
//****************************************
#include<stdio.h>
#include<stdlib.h>

void Transpose(int **p, int row, int col);

int main(void)
{
    int row = 0, col = 0;
    int **array = NULL;
    int i, j;

    printf("����������:\n");
    scanf("%d", &row);
    printf("����������:\n");
    scanf("%d", &col);

    if(row != col)
    {
        printf("�����������������\n");
        return 0;
    }
    array = (int**)malloc(sizeof(int*)*row);
    for(i = 0;i < row;i++)
    {
        array[i] = (int*)malloc(sizeof(int)*col);
    }

    printf("����������Ԫ��:\n");
    for(i = 0;i < row;i++)
    {
        for(j = 0;j < col;j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("ԭ����Ϊ:\n");
    for(i = 0;i < row;i++)
    {
        for(j = 0;j < col;j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    printf("ת�ƺ�Ϊ:\n");
    Transpose(array, row, col);

    return 0;
}

void Transpose(int **p, int row, int col)
{
    int i, j, temp;
    for(i = 0;i < row;i++)
    {
        for(j = 0;j < i;j++)
        {
            temp = p[i][j];
            p[i][j] = p[j][i];
            p[j][i] = temp;
        }
    }
    for(i = 0;i < row;i++)
    {
        for(j = 0;j < col;j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

}
