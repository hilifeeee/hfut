/*-----------------------------------------------
  Filename: LifeGame.C
  Purpose:
  Date:   2019.12.02
  Author: Li Haoran
 ----------------------------------------------*/
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

#define High 25                     //��Ϸ�����С
#define Width 25
//����ȫ�ֱ���
int cells[High][Width];         //ϸ������1��0

void HideCursor(void);        //���ع��
void goto_xy(int x,int y);     //����ƶ���(x,y)λ��
void start(void);             //���ݳ�ʼ��
void show(void);              //��ʾ��Ϸ�Ľ���
void update(void);            //���¿��ƺ���


int main(void)
{
    int i;
    //��ʼ����
    the:
        printf("   ������Ϸ\t\n");
        printf("  1.��ʼ��Ϸ\n");
        printf("  0.�˳���Ϸ\n");
        printf("������(1/0):\t");
        scanf("%d", &i);
        if(i != 1 && i != 0)
        {
            printf("���������������һ�飡\n");
            system("CLS");
            goto the;
        }

    //ϵͳ�ж�
    switch(i)
    {
    case 1:
        start();
        while(1)
        {
            show();
            update();

        }
    case 0: exit(0);
    }
    return 0;
}

void HideCursor(void)        //���ع��
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void goto_xy(int x,int y) //����ƶ���(x,y)λ��
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void start(void)  //���ݳ�ʼ��
{

    srand(time(NULL));
    int i,j;
    for(i=0;i<High;i++)
    {
        for(j=0;j<Width;j++)
        {
            cells[i][j]=(rand() % 2);//��rand()����ʹϸ���ĳ�ʼ״̬���
        }
    }
    HideCursor();
}
void show(void)     //��ʾ��Ϸ�Ľ���
{
    goto_xy(0,0);
    int i,j;
    for(i=1;i<High;i++)
    {
        for(j=1;j<Width;j++)
        {
            if(cells[i][j]==1)
                printf("��");
            else
                printf("��");
        }
        printf("\n");
    }
    Sleep(250);            //����ˢ���ٶ�
}
void update(void)       //���¿��ƺ���
{
    int i,j;
    int NeighborCells;
    int temp[High][Width];
    //�ж�ϸ������
    for(i=1;i<High;i++)
    {
        for(j=1;j<Width;j++)
        {   //����ϸ��������NeighborCells
            NeighborCells=(cells[i-1][j-1]+cells[i-1][j]+cells[i-1][j+1]+cells[i][j-1]+cells[i][j+1]+cells[i+1][j-1]+cells[i+1][j]+cells[i+1][j+1]);
            //�ж�״̬
            if(NeighborCells==3)            //��Χ��3����ϸ��ʱ����ϸ����
                temp[i][j]=1;
            else if(NeighborCells==2)       //��Χ��2����ϸ��ʱ����ϸ��״̬����
                temp[i][j]=cells[i][j];
            else
                temp[i][j]=0;
        }
    }
    //ת��Ϊ��̬�����
    for(i=1;i<High;i++)
        for(j=1;j<Width;j++)
            cells[i][j]=temp[i][j];
}

