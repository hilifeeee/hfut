//****************************************
//File Name:0805
//Author:Li Haoran
//Date:2019.12.15
//Student ID:2019218211
//****************************************
#include<stdio.h>
#include<stdlib.h>

struct stu_node
{
    char cName[10];
    char cProf[5];
    int iClass;
    int iStudentID;
    float S[3];
    float S1;
    float ave;
}stu[10];//struct the student

int main(void)
{
    FILE *fp;
    int i, j;
    struct stu_node temp, a[10];
    struct stu_node *buffer;

    for(i = 0;i < 10;i++)
    {
        printf("�������%d��ѧ������Ϣ:\n",i+1);
        printf("������ѧ������:\n");
        scanf("%s",stu[i].cName);
        printf("������ѧ��רҵ:\n");
        scanf("%s",stu[i].cProf);
        printf("������ѧ���༶:\n");
        scanf("%d", &stu[i].iClass);
        printf("������ѧ��:\n");
        scanf("%d", &stu[i].iStudentID);
        printf("���������ųɼ�:\n");
        for(j = 0;j < 3;j++)
        {
            scanf("%f", &stu[i].S[j]);
            stu[i].S1 += stu[i].S[j];
        }
        stu[i].ave = stu[i].S1 / 3;
        getchar();
        system("cls");
    }//input the node

    if((fp = fopen("StuInf.csv","w")) == NULL)
    {
        printf("��ʧ��!\n");
        exit(0);
    }
    //input the file
    fwrite(stu,sizeof(struct stu_node),10,fp);
    fclose(fp);

    if((fp = fopen("StuInf.csv","r")) == NULL)
    {
        printf("��ʧ��!\n");
        exit(0);
    }
    //output the file
    fread(a,sizeof(struct stu_node),10,fp);
    for(i = 0;i < 2;i++)
    {
        printf("%s,", a[i].cName);
        printf("%s,",a[i].cProf);
        printf("%d,", a[i].iClass);
        for(j = 0;j < 3;j++)
        {
            printf("%f,", a[i].S[j]);
        }
        printf("%f,", a[i].S1);
        printf("%f\n", a[i].ave);
    }

    return 0;
}
