#include"head.h"

// <1>β�巨������������ӡ���������
void createList(node *&L)
{
	int x;
	node* u;
	node* r;
	L = (node*)malloc(sizeof(node));
	L->next = NULL;
	r = L;
	printf("����������������-1��������\n");
	scanf("%d",&x);
	while(x != -1)
	{
		u = (node*)malloc(sizeof(node));;
		u->data = x;
		u->next = NULL;
		r->next = u;
		r = u;
		scanf("%d",&x);
	}
	printf("β�巨����ɹ���\n");	
	u = L;
	printList(u);
} 

// <2>ͷ�巨������������ӡ��������� 
 void createListH(node* L)
{
	node* u;
	int x;
	L = (node*)malloc(sizeof(node));
	L->next = NULL;
	printf("�������������ݣ�����-1�˳�����\n");
	scanf("%d",&x);
	while(x != -1)
	{
		u = (node*)malloc(sizeof(node));
		u->data = x;
		u->next = L->next;
		L->next = NULL;
		scanf("%d",&x);
	}
	printf("ͷ�巨����ɹ���\n");
} 

// <3>���ٵ�����
 void destroyList(node* L)
{
	node *p,*u;
	p = L;
	while(p)
	{
		u = p->next;
		p = NULL;
		p = u;	
	}	
	L = NULL;
} 

// <4>�������ȡ�
 int listLength(node *L)
{
	int len = 0;//��Ʊ������泤��
	node* p = L->next;//�ӹ�ͷ��� 
	while(p != NULL)
	{
		len++;
		p = p->next;	
	} 
	
	return len;//���ؼ���ֵ 
}

// <5>�������е�i��Ԫ�أ����������������ڣ�����
 node* getElement(node* L,int i)
{
	node* p = L->next;
	int j = 1;
	while(j!=i && p!=NULL)
	{//ѭ������һ����� 
		p = p->next;
		j++;
	}
	
	return p; //��j == iʱ��pΪĿ��ڵ�
//		���򷵻�p== null����ų�����Χ 
}
// <6>�ڵ�i�����ǰ����ֵΪx�Ľ�㡣
void listInsert(node* L ,int i,int x) 
{
	
	node* p = L;
	node* s;
	int k = 0;
	while(k != i-1 && p != NULL)
	{
		p = p->next;
		k++;
	}
	if(p == NULL)
		printf("Error!\n"); 
	else
	{
		s = (node*)malloc(sizeof(node)); //����һ���½ڵ�
		s->data = x;
		s->next = p->next;
		p->next = s; 
	}
} 
// <7>�����в���Ԫ��ֵΪx�Ľ�㣬�ɹ����ؽ��ָ�룬ʧ�ܱ���
 node* locate(node* L,int x)
{
	node*p = L->next;
	while(p != NULL)
	{
		if(p->data == x)
		{
			return p;//���ҳɹ�������Ŀ��ڵ�ָ�� 
		}
		else
		{
			p = p->next;//ָ����Ƶ���һ���ڵ� 
		}
	} 
	return NULL;// ����ʧ�ܣ����� ��ָ�� 
} 
// <8>ɾ���������е�i��Ԫ�ؽ�㡣
 void listDelete(node* L,int i)
{
	node* u;
	node* p = L;
	int k = 0;
	while(k != i-1 && p != NULL)
	{//����ai-1�ڵ� 
		p = p->next;
		k++;
	}
	if(p == NULL || p->next == NULL)
	{//ɾ����λ��i������Χ��ɾ��ʧ�� 
		printf("�ڵ㲻����\n"); 
	}
	else//��ʱpָ��ai-1 
	{
		u = p->next;//uָ��ai 
		p->next = u->next;//ai-1 ��nextָ��ai+1 
		u = NULL;//ɾ���ڵ�ai 
        printf("ɾ���ɹ���\n");	//ɾ���ɹ� 
	}
}
// <9>��һ����������ĵ�����L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�
 void orderInsert(node* L, int x)
 {
 	node *p = L;
 	int i = 1;
 	while(p != NULL)
 	{
 		if(p->data < x)
		 {
		 	p = p->next;
 			i++;	
		 }	
 		else
		{
 			listInsert(L,i,x);
			break;	
		}
	}
 }
// <10>����������е��������ż������ֽ⿪��Ԫ��ֵΪ������ż������
//�ֱ�����µĵ������У�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������
void doubleList(node* L,node* A,node* B)
{
	node* p = L;
	while(p != NULL)
	{//���в�� 
		if(p->data % 2 == 1)
			orderInsert(A,p->data);
		else 
			orderInsert(B,p->data);
		p = p->next;	
	} 	
//	��ʼ����
	printList(L);
	printList(A);
	printList(B);	

} 
// <11>������������������L1��L2�еĹ���Ԫ�أ������µĵ�����L3��
 void publicList(node* L1,node* L2,node* L3)
 {
	node* p = L1;
	node* q = L2;
	int i = 1;
	while(p != NULL)
	{
		while(q != NULL)
		{
			if(p->data == q->data)
			{
				listInsert(L3,i,p->data);
				i++;
			}
			q = q->next;
		}
		p = p->next;
	}
 }
// <12>ɾ���������������е��ظ�Ԫ�أ�Ҫ��ʱ��������á�
 void Delete(node *L)
 {
	node* p;
	p = L;
	int i = 0;
	while(p != NULL)
	{
		if(p->data == p->next->data)
		{
			listDelete(p,i);
		}
		p = p->next;
		i++;
	}
 }
// <13>������������L1��L2���������½�㣬����ԭ�����2����кϲ���
// ��ʹ�úϲ����Ϊһ�����ϣ��ϲ�����L1��ͷ�����Ϊͷ��㣬ɾ��L2��ͷ��㣬Ҫ��ʱ��������á�
 node* mergeList(node* L1,node* L2)
 {
 	node *p = L1;
 	node *q = L2;
 	while(p->next != NULL)
 		p = p->next;
 	p->next = q;
 	q = NULL;
 	free(L2);
 	
 	return p;
 }
 
 int main(void)
{//����
	node *L = NULL;
	createList(L);
	printList(L);
	return 0;	
} 
 
 
 
 
