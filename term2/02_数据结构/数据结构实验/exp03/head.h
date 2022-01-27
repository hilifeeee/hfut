#include <stdio.h>

#define MAXLEN 100
//MAXLEN ������� 
typedef struct
{
	int data[MAXLEN];//������ 
	int top;//��ʾջ��Ԫ�ص�λ�� 
}seqStack;

typedef struct lsNode
{
	int data; //��ջ���������
	struct lsNode *next; //��ջ���ָ����
} node;


//(1)��ʼ�� 
void initStack(seqStack *S)
{
	S->top = -1;
}

//(2)��ջ�� 
void stackEmpty(seqStack *S)
{
	if (S->top == -1)
		printf("ջ�գ�\n");

	else
		printf("ջ�ǿ�!\n");
}

//(3)��ջ�� 
void stackFull(seqStack S)
{
	if (S.top == MAXLEN - 1)//�ж�ջ�������� 
		printf("ջ����\n");
	else
		printf("ջ������\n");
}

//(4)ȡջ��Ԫ�� 
int stackTop(seqStack* S)
{
	int x;
	if (S->top == -1)
		printf("ջ�գ�\n");
	else
	{
		x = S->data[S->top];//����x����ջ��Ԫ�� 
		return x;	
	}
}

//(5)��ջ
void push(seqStack* S, int x)
{
	if (S->top == MAXLEN - 1)
		printf("ջ����\n");
	else
	{
		S->top++;//ջ��ָ����� 
		S->data[S->top] = x; //Ԫ��x��ջ 
	}
}

//(6)��ջ 
int pop(seqStack* S)
{
	int x;
	if (S->top == -1)
		printf("ջ�գ�����ɾ��\n");
	else
	{
		x = S->data[S->top];//ȡջ��Ԫ����x 
		S->top--;//ջ����1��ɾ����ջ��Ԫ�� 
	}
	return x;
}
//<1>����˳��ջʵ�ֽ�10������ת��Ϊ16��������
void numberBaseSwitch(int N)
{
	int mod;
	int x = 0;
	seqStack S;
	initStack(&S);
	while(N != 0)
	{
		mod = N % 16; 
//		printf("%d\n",mod);
		push(&S,mod);
		N = N / 16;
	}
	printf("16������Ϊ��");
	while(S.top != -1)
	{
		x = pop(&S);
		switch(x)
		{
			case 10: printf("A");break;
			case 11: printf("B");break;
			case 12: printf("C");break;
			case 13: printf("D");break;
			case 14: printf("E");break;
			case 15: printf("F");break;
			default: printf("%d",x);
		}

	}
}

//
char leftOfRight(char c)
{
   if (c == ')') return '(';
   if (c == ']') return '[';
    return '{';
}
void isValid(char str[])
{	   
	seqStack left;
	initStack(&left);
	char c;
	int i = 0;
	while(str[i] != '\0')
	{
		c = str[i];
		if(c == '(' || c == '[' || c == '{')
			push(&left,str[i]);
		else
		{
			if(left.top != -1 && leftOfRight(c) == (char)pop(&left))	
				pop(&left);
			else
			{
				printf("���ִ���\n");
				break;
			}
		} 			
	}	
	printf("δ���ִ���\n");
}

void initialStack(node *top)
{
	top = NULL;
}

void getTop(node * top, int x)
{
	if(top == NULL)
		printf("ջ�գ�\n");
	else
	{
		x=top->data; //ȡջ��Ԫ�أ��ò���x����
		printf("ȡֵ�ɹ���\n");
	} 
}
void pushP(node * top, int x)
{
	node* s;
	s->data = x;
	s->next = top;
	top = s;
}

void popP(node * top, int x)
{ 
	node* u;
	if(top==NULL)
		printf("ջ�գ�\n");
	else
	{
		x=top->data; //ȡջ��Ԫ�أ��ɱ���x����
		u=top; //ջ��ָ�뱣�浽u
		top=top->next; //ջ��ָ�����һ��Ԫ�ؽ��
		printf("����ջ�ɹ���"); 
	}
}
//�����ֵ��㷨һ�£����õĺ�����һ�� 
