#include<stdio.h>
#include<stdlib.h>

//�ڵ�Ķ��� 
typedef struct slNode
{
	int data;//������ 
	struct slNode* next;//ָ���� ,�������� 
}node;

//1.��ʼ�������� 
node* initialList()
{
	node* p;
	p =(node*)malloc(sizeof(node));//��̬�����ڴ棬��Ϊͷ��� 
	p->next = NULL;
	return p;	//�������� 
} 

//2.���������� 
int listLength(node *L);
//3.���ָ��λ�õ�Ԫ�� 
node* getElement(node* L,int i);

//4.���ָ��Ԫ�ص�λ�� 
node* locate(node* L,int x);

//5.�����½ڵ�
void listInsert(node* L ,int i,int x);

//6.ɾ���ڵ�
void listDelete(node* L,int i);

//7.���������
void destroyList(node* L);

//8.β�巨����
void createList(node *L);

//9.ͷ�巨����
void createListH(node* L); 
 
//���
void printList(node* L)
{
	node* q;
	q = L->next;
	printf("{");
	while(q != NULL)
	{
		printf("%d ",q->data);
		q = q->next;
	}
	printf("}\n");
} 
