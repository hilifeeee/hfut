//seqStack.h
//--˳��ջ�Ķ��������ʵ��
//--�˴�Ϊ�˼��ݣ���Щ���������޸�

#include "iostream"

//-----------------------------------------------------------------------
//�������
#define MAXLEN 100
typedef int SeleType;
//-----------------------------------------------------------------------
//˳��ջ�洢����
typedef struct sStack
{
	SeleType data[MAXLEN];
	int top;
}seqStack;
//-----------------------------------------------------------------------
//1. ջ��ʼ��
void initialStack(seqStack &S)
{
	S.top=-1;
}
//-----------------------------------------------------------------------
//2. �ж�ջ��
bool stackEmpty(seqStack &S) //��ֵ��ָ�롢����
{
	if(S.top==-1)
		return true;
	else
		return false;
}
//-----------------------------------------------------------------------
//3. ȡջ��Ԫ��
bool getTop(seqStack &S, SeleType &x)
{
	if(stackEmpty(S))
		return false; //��ջ������false
	else
	{
		x=S.data[S.top];
		return true;  //ȡ��ջ��������true��ȡ�õ�ֵ�� x ���ݡ�
	}
}
//-----------------------------------------------------------------------
//4. �ж�ջ��
bool stackFull(seqStack &S)
{
	if(S.top==MAXLEN-1)
		return true; //ջ��������true
	else
		return false; //ջδ��������false
}

//-----------------------------------------------------------------------
//5. ��ջ
bool push(seqStack &S, SeleType x)
{
	if(stackFull(S))
		return false; //ջ����������ջ������false
	else
	{
		S.top++; //����ջ��
		S.data[S.top]=x; //������ջ
		return true;
	}
} 
//-----------------------------------------------------------------------
//6. ��ջ
bool pop(seqStack &S, SeleType &r) //r���ص�����Ԫ��
{
	if(stackEmpty(S)) //��ջ��ûԪ�س�ջ������false
		return false;
	else
	{
		r=S.data[S.top];
		S.top--;
		return true;
	}
}

//��ӡջԪ��
void printStack(seqStack &S)
{
	int i;
	if(S.top==-1)
		cout<<"��ջ��";
	else
	{
		cout<<"ջ��Ԫ������"<<S.top+1<<"��"<<endl;
		cout<<"ջԪ�أ�";
		for(i=0;i<=S.top;i++)
		{
			cout<<S.data[i]<<"\t";			
		}		
	}
	cout<<endl<<endl;
}

//����ѭ��ѹ��Ԫ��
void createSeqStack(seqStack &S)
{		
	SeleType x;
	
	cout<<"����������Ԫ��(������-9999�˳�):"<<endl;
	cout<<"x=";
	cin>>x;

	while(x!=-9999 && S.top!=MAXLEN-1)   //�ǽ���������ջδ����ѭ����ջ
	{
		S.top++;         //����ջ��
		S.data[S.top]=x; //������ջ

		cout<<"x=";
		cin>>x;
	}
	if(S.top==MAXLEN-1)
		cout<<"ջ����������ѹ��Ԫ�ء�"<<endl;
}

//�����ѭ��ѹ��Ԫ�ؿ�ʼ------------------------------------------------------------------
//���������˳��ջ
void rndCStack(seqStack &S)
{
	int i;
	int n,m;
	S.top=-1;  //��Ϊ��ջ
	cout<<"������Ҫ�����������������n=";
	cin>>n;
	
	if(n>MAXLEN)
	{
		cout<<"��Ҫ����������������������˳��ջ����"<<MAXLEN<<"������˳��ջʧ�ܡ�"<<endl;
		return;	
	}	
	cout<<"����������������С����������100��������������100��m=";
	cin>>m;    
	
	srand((unsigned)time(NULL));	//�������������
	//srand((unsigned)GetTickCount());	//�������������
	for(i=0;i<n;i++)                //�����д�������A[]
	{
		S.top++;
		S.data[i]=rand()%m;
	}
	cout<<endl;
}
//�����ѭ��ѹ��Ԫ�ؽ���------------------------------------------------------------------
