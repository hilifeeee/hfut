#include <iostream>
#include "head.h"

using namespace std;

int main(int argc, char* argv[])
{
	int nMenu;  //�˵�����
	int dh;
	int i;

    elementType Org[MaxLen];  //���δ�����ԭʼ����
	elementType A[MaxLen];    //�������� 
	elementType T[MaxLen];    //��Ŷ�·�鲢�������
	elementType x;
	int arrLen;   //��������A[]��Ԫ�ظ���

	do
	{
		//�����˵�
		cout<<"--------�����㷨���˵�-----------"<<endl;
		cout<<"|  0--�˳�                      |"<<endl;
		cout<<"|  1--����̨���������          |"<<endl;
		cout<<"|  2--��������������          |"<<endl;		
		cout<<"|  3--��ӡ�����                |"<<endl;
		cout<<"*-------------------------------*"<<endl;
		cout<<"*  4--ϣ�������㷨              *"<<endl;
		cout<<"*  5--��������                  *"<<endl;
		cout<<"*  6--������                    *"<<endl;
		cout<<"*  7--mod3����                  *"<<endl;
		cout<<"*-------------------------------*"<<endl;
		cout<<"��ѡ�����(0-7)��";
		cin>>nMenu;
		switch(nMenu)
		{
		case 0:  //�˳�����
			cout<<"��ǰѡ��������˳���"<<endl;
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;
		case 1:  //����̨���������
			cout<<"��ǰѡ�����������̨���������"<<endl;
			
			cSortList(Org);  //�������У����浽Org[]����

			memcpy(A,Org, sizeof(Org));

			printList(Org,A);
			
			if(listLen==0)
				cout<<"<-- �������ʧ�ܣ� -->"<<endl;
			else
				cout<<"<-- ��������ɹ��� -->"<<endl;
			
			break;
		case 2:    //��������������
			cout<<"��ǰѡ���������������������"<<endl;
			
			srnd(Org);  //�������У����浽Org[]����

			memcpy(A,Org, sizeof(Org));

			printList(Org,A);
			
			if(listLen==0)
				cout<<"<-- �������ʧ�ܣ� -->"<<endl;
			else
				cout<<"<-- ��������ɹ��� -->"<<endl;			
			break;
		case 3:
			if(listLen==0)
			{
				cout<<endl<<"�����������δ���������ܴ�ӡ��"<<endl<<endl;
				break;
			}

			printList(Org,A);  //��ӡԭʼ���������

			break;
					
		case 4:  //ϣ������
			if(listLen==0)
			{
				cout<<endl<<"�����������δ������"<<endl<<endl;
				break;
			}
			memcpy(A,Org, sizeof(Org));   //ԭʼ�����ݸ��������

			ShellSort(A);                 //ϣ�������㷨

			printList(Org,A);             //��ӡԭʼ���������
			cout<<endl<<"ϣ��������ɡ�"<<endl<<endl;

			break;					
							
		case 5:  //��������
			if(listLen==0)
			{
				cout<<endl<<"�����������δ������"<<endl<<endl;
				break;
			}
			memcpy(A,Org, sizeof(Org));   //ԭʼ�����ݸ��������

			QuickSort (A, 1, listLen );   //���������㷨

			printList(Org,A);             //��ӡԭʼ���������
			cout<<endl<<"����������ɡ�"<<endl<<endl;

			break;	
							
		case 6:  //������
			if(listLen==0)
			{
				cout<<endl<<"�����������δ������"<<endl<<endl;
				break;
			}
			memcpy(A,Org, sizeof(Org));   //ԭʼ�����ݸ��������

			HeapSort(A,listLen);          //�������㷨

			printList(Org,A);             //��ӡԭʼ���������
			cout<<endl<<"��������ɡ�"<<endl<<endl;

			break;			
	
		case 7:  //mod3����
			if(listLen==0)
			{
				cout<<endl<<"�����������δ������"<<endl<<endl;
				break;
			}
			
			SortBy3(A,listLen);
			printList(Org,A);              //��ӡԭʼ���������
			cout<<endl<<"����������ɡ�"<<endl<<endl;

			break;							
		default:
			cout<<"����ѡ���������0��14֮��ѡ��==>"<<endl;
			break;
		}
	
		system("pause");
		system("cls"); 
	}while(nMenu!=0);  //ѭ����ʾ�˵���nMenu==0 �˳�
	
	return 0;
}
