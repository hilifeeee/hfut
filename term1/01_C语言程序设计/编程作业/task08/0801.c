//****************************************
//File Name:0801
//Author:Li Haoran
//Date:2019.11.30
//Student ID:2019218211
//****************************************
#include<stdio.h>
#include<stdlib.h>

struct stu_node
{
    char Name[10];
    int StudentID;
    float Score[4];
    float S;
    float ave;
};

void List(struct stu_node *a,int n);
void sort(struct stu_node *a,int n);

int main(void)
{
    int n, i, j;
    struct stu_node *a;

    printf("������ѧ������n:\n");
    scanf("%d", &n);
    system("CLS");

    a = (struct stu_node*)malloc(n * sizeof(struct stu_node));
    for(i = 0;i < n;i++)
    {
        printf("�������%d��ѧ����������", i+1);
        scanf("%s", a[i].Name);
        printf("������ѧ�ţ�");
        scanf("%d", &a[i].StudentID);
        printf("���������ſεĳɼ�:\n");
        a[i].S = 0;
        for(j = 0;j < 4;j++)
        {
            scanf("%f", &a[i].Score[j]);
            a[i].S += a[i].Score[j];
        }
        a[i].ave = a[i].S / 4.0f;
        system("CLS");
    }
    printf("ԭ����Ϊ:\n");
    List(a,n);
    sort(a,n);
    printf("���ܷ�����������Ϊ:\n");
    List(a,n);

    return 0;
}

void List(struct stu_node *a,int n)
{
    int i, j;
    printf("����\tѧ��\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ܷ�\tƽ����\n");
    for(i = 0;i < n;i++)
    {
        printf("%s\t",a[i].Name);
        printf("%d\t",a[i].StudentID);
        for(j = 0;j < 4;j++)
            printf("%.1f\t",a[i].Score[j]);
        printf("%.1f\t",a[i].S);
        printf("%.1f\n",a[i].ave);
    }
}

void sort(struct stu_node *a,int n)
{
    int i, j;
    struct stu_node t;
    for(i = 0;i < n-1;i++)
    {
        for(j = i;j < n;j++)
        {
            if(a[i].S < a[j].S)
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

