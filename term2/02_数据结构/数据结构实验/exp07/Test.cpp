#include <stdio.h>
#include "AVLTree.h"

int main (void) 
{
	int i;
	int nMenu;

	elementType x;


	btNode* T=NULL;
	btNode* p;
	
    do
	{
		//�����˵�
		cout<<"*********ƽ����������Գ���*********"<<endl;
		cout<<"*       0--�˳�                    *"<<endl;
		cout<<"*       1--����ƽ�������          *"<<endl;
		cout<<"*       2--����ƽ�������          *"<<endl;
		cout<<"*       3--��ӡƽ�������          *"<<endl;
		cout<<"*----------------------------------*"<<endl;
		cout<<"*       4--�����������ݹ����      *"<<endl;			
		cout<<"*       5--������                *"<<endl;
		cout<<"*       6--ɾ�����                *"<<endl;
		cout<<"************************************"<<endl;
		cout<<"��ѡ�����(0-8)��";
		cin>>nMenu;
		switch(nMenu)
		{
		case 0:  //�˳�����
		
			cout<<"��ǰѡ��������˳���"<<endl;
			cout<<"<-- �����˳� -->"<<endl;  //ѡ���˳�
			break;
			
		case 1:  //����ƽ�������--����
		
			system("cls");  //�����Ļ
			if(T!=NULL)  //��ֹ�ظ�����������ڴ�й¶
			{
				cout<<"�������Ѿ����ڣ��������´��������������ٴ�����"<<endl;
				break;
			}
			CreateAVLTree(T);   //����������������
			cout<<"�ɹ�������������"<<endl;
			break;
			
		case 2:    //����ƽ�������
		
			system("cls");  //�����Ļ
			if (T!=NULL)
				DestroyBt(T);
			cout<<"�ɹ����ٶ�������"<<endl;
			break;
			
		case 3:    //��ӡƽ�������
		
			system("cls");  //�����Ļ
			if(T==NULL)
			{
				cout<<"<--������Ϊ������-->"<<endl;
				break;
			}
			cout<<"�������";
			preTraverse(T);   //�ݹ��������
			cout<<endl;
			cout<<"�������";
			inTraverse(T);    //�ݹ��������
			cout<<endl;
			cout<<"�������";
			postTraverse(T);  //�ݹ�������
			cout<<endl;
			cout<<endl;
			break;
			
    	case 4:  //�ݹ����
			system("cls");  //�����Ļ
			cout<<"���������Ԫ��ֵ(����):"<<endl;
			cout<<"x=";
			cin>>x;

			cout<<"�����������ݹ���ң�";
			p=Search(T,x);
			if(p)
				cout<<"�ɹ���Ŀ����ֵΪ��"<<p->data<<"��"<<endl;
			else
				cout<<"ʧ�ܡ�"<<endl;
			break;

		case 5:  //�����������ݹ������
		
			system("cls");  //�����Ļ
			cout<<"���������������(������-9999�˳�):"<<endl;
			cout<<"x=";
			cin>>x;			
			while(x!=-9999 )
			{
				p=new btNode;
				p->data=x;
				p->lChild=NULL;
				p->rChild=NULL;
				
				InsertNode(T,x);

				cout<<"x=";
				cin>>x;
			}
			inTraverse(T);
			cout<<endl<<endl;
			break;
			
		case 6:  //ƽ�������ɾ�����
			system("cls");  //�����Ļ
			
			cout<<"�������ɾ�����Ԫ��ֵ(����):"<<endl; 
			cout<<"x=";
			cin>>x;
			if(delNode(T,x))
				cout<<"ɾ�����ɹ���"<<endl;
			else
				cout<<"ɾ�����ʧ�ܡ�"<<endl;			
			cout<<endl;

			setBf(T,x);
			break;
			
		default:
			cout<<"����ѡ���������0��6֮��ѡ��==>"<<endl;
			break;
		}
		
		system("pause");
		system("cls");
	}while(nMenu != 0);  //ѭ����ʾ�˵���nMenu==0 �˳�

    if (T!=NULL)
        DestroyBt(T);    //���ٶ�����
        
	return 0;
}
