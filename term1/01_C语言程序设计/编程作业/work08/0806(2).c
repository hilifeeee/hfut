//****************************************
//File Name:0806
//Author:Li Haoran
//Date:2019.12.18
//Student ID:2019218211
//****************************************
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int key;
    char ch;
    FILE *fp, *fp1;

    printf("��������Կ:");
    scanf("%d", &key);

    fp = fopen("Cyb.dat","rb");
    fp1 = fopen("out.txt","w");

    if(fp1 == NULL ||fp == NULL)
    {
        printf("error!\n");
        exit(0);
    }

    while(ch = fgetc(fp) != EOF)
    {
        if(ch >= 'a' &&ch <= 'z')
        {
           ch += key;
           if(ch > 'z')
                ch -= 26;
        }
        if(ch >= 'A' && ch <= 'Z')
        {
            ch += key;
            if(ch > 'Z')
                ch -= 26;
        }
        fputc(ch,fp1);
    }
    printf("�����ı���д��out.txt�ļ���.\n");

    fclose(fp);
    fclose(fp1);
}
