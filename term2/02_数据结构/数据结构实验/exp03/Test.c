#include "head.h"
#include<stdlib.h>

int main (void)
{
	while(1)
	{
		int key;
		printf("-------��ѡ����-------\n");
		printf("--1.ʮ����ת16����\n");
		printf("--2.�ж���ʽ���źϷ���\n");
		printf("------------------------\n");
		printf("��������ţ�");
		scanf("%d",&key);
		int x;
		char *str;
		switch(key)
		{
			case 1:		
				printf("������ʮ��������");
				scanf("%d",&x);
				numberBaseSwitch(x);
				printf("\n");
				system("pause");
				system("cls");
				break;
			case 2:
				printf("��������ʽ��");	
				scanf("%s",str);
				printf("��ʽ��");
				isValid(str);
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
