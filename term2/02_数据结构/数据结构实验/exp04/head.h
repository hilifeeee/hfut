#include<stdio.h>
#define MAXLEN 100
typedef struct
{
 	int data[MAXLEN]; // ���Ԫ��
 	int front; //��ͷָ��
 	int rear; //��βָ��
}seqQueue;

//1.��ʼ������ 
void initQueue(seqQueue Q)
{
	//��ʼ��β��ָ��0������ѭ������ 
	Q.front = 0;
	Q.rear = 0;
}
//2.�жӿ�
void queueEmpty(seqQueue Q)
{
	if(Q.front == Q.rear)
		printf("�ӿգ�\n");
	else
		printf("�ӷǿգ�\n"); 
} 

//3.�ж���
void queueFull(seqQueue Q)
{
	if((Q.rear+1)%MAXLEN == Q.front)
		printf("������\n");
	else
		printf("�ӷ�����\n");	
} 

//4.ȡ��ͷ
void queueFront(seqQueue Q,int x)
{
	if(Q.front == Q.rear)
		printf("�ӿգ�\n");
	else
		x = Q.data[(Q.front+1)%MAXLEN];	
} 

//5.���
void enQueue(seqQueue Q,int x)
{
	if((Q.rear+1)%MAXLEN == Q.front)
		printf("������\n");	
	else
	{
		Q.rear = (Q.rear+1)%MAXLEN;
		Q.data[Q.rear];	
	}	
} 
 
//6.���� 
void outQueue(seqQueue Q,int x)
{
	if(Q.front == Q.rear)
		printf("�ӿգ�\n");
	else
	{
		Q.front = (Q.front+1)%MAXLEN;
		x = Q.data[Q.front];
	}
}
//7.ͳ�ƶ������ݵĸ���
int numberOfQueue(seqQueue Q)
{
	int x;
	if(Q.front > Q.rear)
		x = Q.front - Q.rear;
	else
		x = Q.rear - Q.front;
	return x;
} 
//8.�Զ���
void myQueue()
{
	seqQueue Q;
	initQueue(Q);
	int x;
	while(1)
	{
		printf("���������֣�0�˳���");
		scanf("%d",&x);
		if(x == 0)
			break;
		else if(x%2 == 1)
			enQueue(Q,x);
		else
		{
			outQueue(Q,x);
			printf("��ͷΪ%d\n",&x);			
		}
	}
	printf("������ɣ�\n");	
}  

