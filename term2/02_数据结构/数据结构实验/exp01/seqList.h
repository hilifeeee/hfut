#include <stdio.h>

#define MAXLEN 100  //����������� 

typedef int elementType; //������������

typedef struct sList
{
	elementType list[MAXLEN];
	int listLen;
} seqList;//��װ���Ա� ������typedef 

//1.��ʼ�� 
void initialList(seqList L)
{
	L.listLen = 0;
}

//2.����� 
int length(seqList L)
{
	return L.listLen;
}

//3.�����ȡԪ�� 
int getElement(seqList L, int i)
{
	if(i < 1 || i > L.listLen)
	{
		printf("���ݳ���\n");
		return -1;
	}
		
	else
	{
		return L.list[i-1];
	}		
}

//4.��ֵ����Ԫ�� 
int listLocate(seqList L, elementType x)
{
	int i;
	for(i = 0; i < L.listLen; i++)
		if(L.list[i] == x)
			return i+1;
    return 0; 
}

//5.����Ԫ�� 
int listInsert(seqList *L, elementType x, int i)
{
	int j;
	if(L->listLen == MAXLEN)
		return 0; 
	else if(i < 1 || i > L->listLen + 1)
		return 1;  
	else
	{
		for(j = L->listLen-1; j >= i-1; j--)
		{
			L->list[j+1]=L->list[j];   //ѭ�����Ʊ�Ԫ��
		}	
		L->list[i-1] = x;   //����Ԫ�� x
		L->listLen++;     //������1  
		return 2;         //�ɹ����룬����ֵ2  
	}
}

//6.ɾ��Ԫ�� 
int listDelete(seqList *L, int i)
{
	int j;
	if(L->listLen <= 0)
		return 0; //�ձ���0
	else if(i < 1 || i > L->listLen)
		return 1;  //��Ų�����Ч��Χ
	else
	{
		for(j = i; j < L->listLen; j++ )
			L->list[j-1]=L->list[j]; //ѭ��ǰ�Ʊ�Ԫ��
		L->listLen--;  //�޸ı���
		return 2;  //�ɹ�ɾ��������ֵ2.
	}
}
