//****************************************
//File Name:06
//Author:Li Haoran
//Date:20199.11.14
//Student ID:2019218211
//****************************************
#include<stdio.h>

int main(void)
{
     int a[3][4], b[3][4], *p, *q;
     int i, j;

     printf("�������һ������:\n");
     for(i = 0;i < 3;i++)
     {
         for(j = 0;j < 4;j++)
         {
             scanf("%d", &a[i][j]);
         }
     }
     printf("������ڶ�������:\n");
     for(i = 0;i < 3;i++)
     {
         for(j = 0;j < 4;j++)
         {
             scanf("%d", &b[i][j]);
         }
     }

     for(i = 0;i < 3;i ++)
     {
         for(j = 0;j < 4;j++)
         {
             a[i][j] += b[i][j];
         }
     }

     printf("�Ӻͺ�Ľ��Ϊ:\n");

     for(i = 0;i < 3;i++)
     {
         for(j = 0;j < 4;j++)
         {
             printf("%d\t", a[i][j]);
         }
         printf("\n");
     }

}
