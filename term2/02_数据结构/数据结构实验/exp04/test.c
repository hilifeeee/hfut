#include"head.h"

int main(void)
{
	while(1)
	{
		int key;
		printf("-------��ѡ����-------\n");
		printf("--1.��ʼ������\n");
		printf("--2.�ж��Ƿ�ӿ�\n");
		printf("--3.�ж��Ƿ����\n");
		printf("--4.���\n");
		printf("--5.����\n");
		printf("--6.ȡ��ͷԪ��\n");
		printf("--7.��ǰ������Ԫ�صĸ���\n");
		printf("--8.�Զ���ĺ���\n");
		printf("--\n");
		printf("------------------------\n");
		printf("��������ţ�");
		scanf("%d",&key);
		seqQueue Q; 
		int x;
		switch(key)
		{
			case 1:
				initQueue(Q);
				printf("��ʼ���ɹ���"); 
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 2:
				queueEmpty(Q);
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 3:
				queueFull(Q);
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 4:
				printf("���������Ԫ�أ�");
				scanf("%d",&x);
				enQueue(Q,x);
				printf("��ӳɹ���");
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 5:
				outQueue(Q,x);
				printf("%d",x);
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 6:
				queueFront(Q,x);
				printf("��ͷԪ��Ϊ��%d",&x);
				printf("\n");
				system("pause");
				system("cls");	
				break;
			case 7:
				x = numberOfQueue(Q);
				printf("Ԫ�صĸ���Ϊ��%d",&x);
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 8:
				myQueue();
				printf("\n");
				system("pause");
				system("cls");
				break;							
			default:
				printf("�������"); 
				system("pause");
				system("cls");
		} 		
	}

	return 0;
}
