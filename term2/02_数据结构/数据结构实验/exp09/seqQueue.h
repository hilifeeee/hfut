//seqQueue.h
//˳��ѭ�����еĶ��������ʵ��

#include "iostream"

//----------------------------------------------------------------------
//������ط���
#define MAXLEN 100
//typedef int elementType;
typedef int eleType;
using namespace std;
//----------------------------------------------------------------------
//˳����д洢�ṹ����
typedef struct sQueue
{
	eleType data[MAXLEN];
	int front,rear;
}seqQueue;


//----------------------------------------------------------------------
//1. ��ʼ��˳�����
void initialQueue(seqQueue* Q) //�����ſ��ô�ֵ������
{
	Q->front=0;  //��ջ
	Q->rear=0;
}
//----------------------------------------------------------------------
//2. �жӿ�
bool queueEmpty(seqQueue &Q)
{
	if(Q.front==Q.rear)
		return true;  //�ӿգ�����true
	else
		return false;  //�Ӳ���
}
//----------------------------------------------------------------------
//3. �ж���
bool queueFull(seqQueue &Q)
{
	if(((Q.rear+1) % MAXLEN)==Q.front)
		return true;  //����������true
	else
		return false;  //����������false
}
//----------------------------------------------------------------------
//4. ȡ��ͷԪ��
bool getFront(seqQueue &Q, eleType &x)
{
	if(queueEmpty(Q))
		return false; //�ӿ�
	else
	{
		x=Q.data[(Q.front+1) % MAXLEN];  //frontָʾ����һ����Ԫ���Ƕ�ͷԪ��
	               //Ϊ��Ҫȡģ�أ�
	    return true;
	}
}
//----------------------------------------------------------------------
//5. ��ӣ����룩
bool enQueue(seqQueue* Q, eleType x)
{
	if(queueFull(*Q))
		return false;    //��������
	else
	{
		Q->rear=((Q->rear)+1) % MAXLEN;  //����rear
		Q->data[Q->rear]=x;  //��������x
		                     //2�����ɷ�δ1���أ�
		return  true;
	}
}
//----------------------------------------------------------------------
//6. ���ӣ�ɾ����
bool outQueue(seqQueue* Q,eleType &x)
{
	if(queueEmpty(*Q))
		return false;  //�ն��У�û��Ԫ�ؿɹ����ӣ�
	else
	{
		Q->front=(Q->front+1) % MAXLEN;
		x=Q->data[Q->front];
		return true;
	}
}

//��ӡ��Ԫ��
void printQueue(seqQueue &Q)
{
	int i;
	if(Q.front==Q.rear)
		cout<<"�ն��С�";
	else
	{
		cout<<"����Ԫ������"<<(Q.rear-Q.front+MAXLEN)%MAXLEN<<"��"<<endl;
		cout<<"����Ԫ�أ�";
		i=(Q.front+1)%MAXLEN;   //iָ��һ��Ԫ��
		while(i!=Q.rear)
		{
			cout<<Q.data[i]<<"\t";
			i=(i+1)%MAXLEN;		
		}
		cout<<Q.data[Q.rear]<<"\t";  //��ӡ��βԪ��				
	}
	cout<<endl<<endl;
}

//����ѭ��ѹ��Ԫ��
void createSeqQueue(seqQueue &Q)
{		
	eleType x;
	
	cout<<"����������Ԫ��(������-9999�˳�):"<<endl;
	cout<<"x=";
	cin>>x;

	while(x!=-9999 && (Q.rear+1)%MAXLEN!=Q.front)   //�ǽ��������Ҷ�δ����ѭ�����
	{
		Q.rear=(Q.rear+1)%MAXLEN;   //��βѭ������
		Q.data[Q.rear]=x;

		cout<<"x=";
		cin>>x;
	}
	if((Q.rear+1)%MAXLEN!=Q.front)
		cout<<"�����������ٽ���Ԫ����ӡ�"<<endl;
}

//�����ѭ����ӿ�ʼ------------------------------------------------------------------
//���������ѭ��˳�����
void rndCQueue(seqQueue &Q)
{
	int i;
	int n,m;
	Q.front=0;  //��Ϊ�ն�
	Q.rear=0;

	cout<<"������Ҫ�����������������n=";
	cin>>n;
	
	if(n>=MAXLEN)
	{
		cout<<"��Ҫ����������������������˳����г���"<<MAXLEN-1<<"������˳�����ʧ�ܡ�"<<endl;
		return;	
	}	
	cout<<"����������������С����������100��������������100��m=";
	cin>>m;    
	
	srand((unsigned)time(NULL));	//�������������
	//srand((unsigned)GetTickCount());	//�������������
	for(i=0;i<n;i++)                //�����д�����
	{
		Q.rear=(Q.rear+1)%MAXLEN;
		Q.data[Q.rear]=rand()%m;
	}
	cout<<endl;
}
//�����ѭ����ӽ���------------------------------------------------------------------
