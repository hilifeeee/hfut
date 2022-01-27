#include"seqList.h"
#include<String.h> 
//<1>��˳����е�i��Ԫ�أ����������������ڣ�����
//��seqList.h���о���ʵ�� 
//int getElement(seqList *L, int i, elementType &x); 

//<2>�ڵ�i��Ԫ��λ�ò���ֵΪx��Ԫ�ء�
//��seqList.h���о���ʵ�� 
//int listInsert( seqList *L, int i, elementType x); 

//<3>ɾ��˳����е�i��Ԫ�ؽ�㡣
//��seqList.h���о���ʵ��
//int listDelete(seqList *L, int i);

//<4>��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�
int orderlistInsert(seqList *L, int x) 
{
	int i = L->listLen - 1;
	
	if (i >= MAXLEN - 1) 
	{
		printf("˳�������");
		return 0;	
	} 
	else
	{
		while(i >= 0 && L->list[i] > x)
		{	 
			L->list[i+1]=L->list[i];
			 i--; 
		}
		L->list[i+1]=x;
		L->listLen++;
		return 1;
	}
} 

//<5>���洢������˳���̣���������ż�����Ϊ2���±�
//Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա���������

int DoubleList(seqList *L,seqList *A,seqList *B)
{
	int i;
	if(L->listLen <= 0) 
	{
		printf("���Ϸ��ı�ֵ"); 
	} 
	for (i = 0;i < L->listLen; i++)
	{
		if(L->list[i] % 2 == 1){
			A->list[A->listLen] = L->list[i];
			A->listLen++;
		} 	
		else
		{
			B->list[B->listLen] = L->list[i];
			B->listLen++;
		}
	}
	return 1;	
}

//<6>��������������˳���L1��L2�еĹ���Ԫ��
//�������µ�˳���L3��

int publicList(seqList *A,seqList *B,seqList *C)
{
	int ai = 0,bi = 0;
	int temp;
	
	for (ai = 0;ai < A->listLen; ai++)
	{
		temp = 0;
		for (bi = temp;bi < B->listLen;bi++)
		{
			if (A->list[ai] == B->list[bi])
			{
				C->list[C->listLen - 1] = A->list[ai];
				C->listLen++; 
				temp = bi; 
			}
			else if(A->list[ai] < B->list[bi])
			{
				temp = bi;
				break;
			}
		}	
	}
	return 1;
}

//<7>ɾ����������˳����е��ظ�Ԫ�أ�
//��ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ���������

int deleteList(seqList *L) 
{
	int i = 0;
	int time = 0;

	if (L->listLen <= 0 || L == NULL)
	{
		return 0;
	}
	for (i = L->listLen;i >= 0;i--)
	{
		if(L->list[i] == L->list[i-1])
		{
			listDelete(L,i);
			time += L->listLen - i;
		}
	}

	return time; 
}

//�Զ��庯�� 
//�����ʼ��˳���
void Initial(seqList *A,int *A1,int n) 
{
	int i = 0;
	A->listLen = n;
	if(A->listLen <= 0 || A->listLen > MAXLEN)
		printf("���ݳ���");
	for(i = 0;i < A->listLen; i++)
	{
		A->list[i] = A1[i];
	} 	
} 

//ɾ������
void Delete(seqList *A) 
{
	int i = 0;
	while(A->listLen != 0) 
	{
		listDelete(A,i);
	}
	
}
//ѭ�����˳���
void printList(seqList *L) 
{
	int i;
	printf("{");
	for (i = 0;i < L->listLen;i++) 
	{
		printf("%d  ",L->list[i]);
	}
	printf("}\n"); 
	
}  


//���Ժ��� 
int main (void) 
{
	int i = 0;
	int element;
	int result;	
	seqList A, B, C;
	
	initialList(A);
	initialList(B);
	initialList(C);


//<1>��˳����е�i��Ԫ�أ����������������ڣ�����
//	ʵ��������ݻ���Ҫ��
//	��һ�����ݣ�˳�����n��10��i�ֱ�Ϊ5��n��0��n+1��n+2
//	�ڶ������ݣ�˳�����n=0��i�ֱ�Ϊ0��2

	int T1[] = {0,1,2,3,4,5,6,7,8,9};
	int T2[] = {0};
	int n = sizeof(T1) / 4;
	Initial(&A,T1,n);
	
	printList(&A);
	
	printf("����1���ݣ����ҵ�iλԪ��\n"); 
	element = getElement(A, 5);
	printf("element = %d\n",element);
	
	element = getElement(A, n);
	printf("element = %d\n",element);
	
	element = getElement(A, 0);
	
	element = getElement(A, n+1);
		 
	element = getElement(A, n+2);
	
	A.listLen = 0;
	element = getElement(A, 0);
	
	element = getElement(A, 2);

//<2>�ڵ�i��Ԫ��λ�ò���ֵΪx��Ԫ�ء�
//ʵ��������ݻ���Ҫ��
//��һ�����ݣ�˳�����n��10��x=100,  i�ֱ�Ϊ5,n,n+1,0,1,n+2
//�ڶ������ݣ�˳�����n=0��x=100��i=5
	int x = 100;
	Initial(&A,T1,n);
	//ʹ�ò���1��˳���Aʵ�ֲ���2 
	listInsert(&A,x,5); 
	
	printf("\n\n");
	printf("����2���ݣ���i��Ԫ��λ�ò���ֵΪx��Ԫ��\n");
	 
	printList(&A);
	
	Initial(&A,T1,n);
	listInsert(&A,x,n); 
	printList(&A);
	
	Initial(&A,T1,n);
	listInsert(&A,x,n+1); 
	printList(&A);
	
	Initial(&A,T1,n);
	listInsert(&A,x,0); 
	printList(&A);
	
	Initial(&A,T1,n);
	listInsert(&A,x,1); 
	printList(&A);	
	
	Initial(&A,T1,n);
	listInsert(&A,x,n+2); 
	printList(&A);
	
	
//<3>ɾ��˳����е�i��Ԫ�ؽ��
//ʵ��������ݻ���Ҫ��
//��һ�����ݣ�˳�����n��10��i�ֱ�Ϊ5,n,1,n+1,0 
//�ڶ������ݣ�˳�����n=0�� i=5

	printf("\n\n");
	printf("����3���ݣ�ɾ��˳����е�i��Ԫ�ؽ��\n");
//i = 5
	Initial(&A,T1,n);
	printf("ɾ��ǰ��");
	printList(&A);
	listDelete(&A,5);
	printf("ɾ����");
	printList(&A); 
	printf("\n");
//i = n
	Initial(&A,T1,n);
	printf("ɾ��ǰ��");
	printList(&A);
	listDelete(&A,n);
	printf("ɾ����");
	printList(&A);
	printf("\n");
//i = 1
	Initial(&A,T1,n);
	printf("ɾ��ǰ��");
	printList(&A);
	listDelete(&A,1);
	printf("ɾ����");
	printList(&A);
	printf("\n");
//i = n + 1
	Initial(&A,T1,n);
	printf("ɾ��ǰ��");
	printList(&A);
	listDelete(&A,n+1);
	printf("ɾ����");
	printList(&A);
	printf("\n");
//i = 0
	Initial(&A,T1,n);
	printf("ɾ��ǰ��");
	printList(&A);
	listDelete(&A,0);
	printf("ɾ����");
	printList(&A);
	printf("\n");
//n = 0, i = 5
	Initial(&A,T2,1);
	printf("ɾ��ǰ��");
	printList(&A);
	listDelete(&A,5);
	printf("ɾ����");
	printList(&A);


//<4>��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�
//ʵ��������ݻ���Ҫ��
//˳���Ԫ��Ϊ ��10,20,30,40,50,60,70,80,90,100��,
//x�ֱ�Ϊ25��85��110��8

	printf("\n\n");
	printf("����4���ݣ�˳���L�в���һ��ֵΪx��Ԫ��\n");
	
	int T3[] = {10,20,30,40,50,60,70,80,90,100};
	Initial(&A,T3,n);
	printList(&A); 
	
	orderlistInsert(&A,25);
	printList(&A);
	
	orderlistInsert(&A,85);
	printList(&A);
	
	orderlistInsert(&A,110);
	printList(&A);
	
	orderlistInsert(&A,8); 
	printList(&A);

//<5>���洢������˳���̣���������ż�����Ϊ2���±�Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������
//ʵ��������ݻ���Ҫ��
//��һ�����ݣ�˳���Ԫ��Ϊ ��1,2,3,4,5,6,7,8,9,10,20,30,40,50,60��
//�ڶ������ݣ�˳���Ԫ��Ϊ ��10,20,30,40,50,60,70,80,90,100��

	printf("\n\n");
	printf("����5���ݣ�������ż�����Ϊ2���±�\n");
	int T4[] = {10,20,30,40,50,60,70,80,90,100};
	Initial(&A,T4,10);
	Initial(&B,T2,1);
	Initial(&C,T2,1);	
	printList(&A);
	DoubleList(&A,&B,&C);
	printf("��ֺ�\n");
	printList(&B);
	printList(&C); 
	printf("\n"); 
	
	int T5[] = {1,2,3,4,5,6,7,8,9,10,20,30,40,50,60};
	Initial(&A,T5,15);
	Initial(&B,T2,1);
	Initial(&C,T2,1);
	printList(&A);
	DoubleList(&A,&B,&C);
	printf("��ֺ�\n");
	printList(&B);
	printList(&C);

//<6>��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�
//ʵ��������ݻ���Ҫ�� 
//��һ��
//��һ��˳���Ԫ��Ϊ ��1��3��6��10��15��16��17��18��19��20��
//�ڶ���˳���Ԫ��Ϊ ��1��2��3��4��5��6��7��8��9��10��18��20��30��
//�ڶ���
//��һ��˳���Ԫ��Ϊ ��1��3��6��10��15��16��17��18��19��20��
//�ڶ���˳���Ԫ��Ϊ ��2��4��5��7��8��9��12��22��
//������
//��һ��˳���Ԫ��Ϊ ����
//�ڶ���˳���Ԫ��Ϊ ��1��2��3��4��5��6��7��8��9��10��
	printf("\n\n");
	printf("����6���ݣ�˳���L1��L2�еĹ���Ԫ��\n");
	int T6[] = {1,3,6,10,15,16,17,18,19,20};//10
	int T7[] = {1,2,3,4,5,6,7,8,9,10,18,20,30};//13
	int T8[] = {1,3,6,10,15,16,17,18,19,20};//10
	int T9[] = {2,4,5,7,8,9,12,22};//8
	int T10[] = {1,2,3,4,5,6,7,8,9,10};//10
	
	Initial(&A,T6,10);
	Initial(&B,T7,13);
	Initial(&C,T2,1);
	printList(&A);
	printList(&B); 
	publicList(&A,&B,&C);
	printList(&C);
	printf("\n");	
	
	Initial(&A,T8,10);
	Initial(&B,T9,8);
	Initial(&C,T2,1);
	printList(&A);
	printList(&B); 
	publicList(&A,&B,&C);
	printList(&C);
	printf("\n");
	
	Initial(&A,T10,10);
	Initial(&B,T2,1);
	Initial(&C,T2,1);
	printList(&A);
	printList(&B); 
	publicList(&A,&B,&C);
	printList(&C);

//<7>ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ��������á�
//ʵ��������ݻ���Ҫ��
//��һ�����ݣ�˳���Ԫ��Ϊ ��1,2,3,4,5,6,7,8,9��
//�ڶ������ݣ�˳���Ԫ��Ϊ ��1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9��
//���������ݣ�˳���Ԫ��Ϊ ��1,2,3,4,5,5,6,7,8,8,9,9,9,9,9�� 
	printf("\n\n");
	printf("����7���ݣ�\n");
	
	int time = 0;
	int T11[] = {1,2,3,4,5,6,7,8,9};//9
	int T12[] = {1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9};//17
	int T13[] = {1,2,3,4,5,5,6,7,8,8,9,9,9,9,9};//15

	Initial(&A,T11,9);
	printList(&A);
	time = deleteList(&A);
	printList(&A);
	printf("time = %d", time);
	printf("\n");
	
	Initial(&A,T12,17);
	printList(&A);
	time = deleteList(&A);
	printList(&A);
	printf("time = %d", time);
	printf("\n");
	
	Initial(&A,T13,15);
	printList(&A);
	time = deleteList(&A);
	printList(&A);
	printf("time = %d", time);
	printf("\n");
	
	return 0;
}
