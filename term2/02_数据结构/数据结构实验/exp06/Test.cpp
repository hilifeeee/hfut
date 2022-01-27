# include <iostream>
# include "createTree.h"

using namespace std;

//���ٺ����ֵ������ʾ������ɭ�֣�
void destroyTree(csNode *&T)
{
	if(T)
	{
		destroyTree(T->firstChild);
		destroyTree(T->nextSibling);
		delete T;
	}
	T=NULL;
}
//��Ҷ�ӽ����
int leafNum(csNode *T)
{
	if(T==NULL)
		return 0;
	else if(T->firstChild==NULL)  //TΪҶ�ӽ��
		return 1+leafNum(T->nextSibling);
	else
		return leafNum(T->firstChild)+leafNum(T->nextSibling);
}

//��������
int nodeNum(csNode *T)
{
	if(T==NULL)
		return 0;
	else
		return 1+nodeNum(T->firstChild)+nodeNum(T->nextSibling);
}

//������ɭ�֣��߶ȣ���ȣ�
int height(csNode *T)
{
	int h,h1;
	csNode *p;
	if(T==NULL)
		return 0;
	else
	{		
		p=T->firstChild;
		h=height(p);
		if(p)
			p=p->nextSibling;
		while(p)
		{
			h1=height(p);
			if(h<h1)
				h=h1;
			p=p->nextSibling;		
		}
		return 1+h;	
	}
}

//�������ʽ���
void outGList(csNode *T)
{
	if(T)
	{
		cout<<T->data;   //���ʸ����
		if(T->firstChild)
		{
			cout<<"(";
			outGList(T->firstChild);
		}
		if(T->nextSibling)     
		{
			cout<<",";
			outGList(T->nextSibling);	
		}
		else
			cout<<")";			    
	}
}

//���������㼰��κ�
void outPreOrder(csNode *T, int level)
{
	if(T)
	{
		cout<<"("<<T->data<<","<<level<<") ";   //���ʸ����
		outPreOrder(T->firstChild,level+1);     //T�ĺ��Ӳ��ΪT�Ĳ�μ�1
		outPreOrder(T->nextSibling,level);	    //T���ֵܲ����T��ͬ
	}
}


int main(void)
{
    //׼���Ĵ���
    int nChoice;	//ѡ���жϵĿ���
    pTree T1;	//˫�ױ�ʾ������ɭ��
	csNode *T;	//�����ֵ������ʾ����
	int i = 0;
	T1.n = 0;
	T = NULL;
	int nR = 0;

    do {
        	//�����˵�
		cout << "******      ����ɭ�ֲ��Գ���      ******" << endl;
		cout << "*  0--�˳�                             *" << endl;
		cout << "*  1--�ļ���������ɭ��                 *" << endl;
		cout << "*  2--��ӡɭ�ֵ����ֱ���               *" << endl;
		cout << "*  3--��ɭ�ֵĸ߶�                     *" << endl;
		cout << "*  4--��ɭ�ֵĽڵ�����                 *" << endl;
		cout << "*  5--��ɭ��Ҷ�ӽڵ���                 *" << endl;
		cout << "*  6--��ɭ�ֵĶ�                       *" << endl;
		cout << "*  7--��������ڵ�ֵ�����κ�         *" << endl;
		cout << "*  8--���������ʾ����               *" << endl;
		cout << "*  9--��������ɭ�֣�                   *" << endl;
		cout << "****************************************" << endl;
		cout << "��ѡ�����(0-8)��" << endl;
		cin >> nChoice;
        switch (nChoice)
		{
		case 0:  //�˳�����
			system("cls");  //�����Ļ
			cout << "<-- �����˳� -->" << endl;  //ѡ���˳�
			break;
        
        case 1:  //�ļ���������ɭ��
        	system("cls");  //�����Ļ
			if (T != NULL)  //��ֹ�ظ�����������ڴ�й¶
			{
				cout << "ɭ���Ѿ����ڣ��������´��������������ٴ�����" << endl;
				break;
			}
			char strFileName[100];
			cout << "������ɭ�������ļ���(F14.tre)��" << endl;
			cin >> strFileName;  //����̨���������ļ���			 

			if (CreateTreeFromFile(strFileName,T1))
			{
				createCsTree(T,T1);
				cout << "<-- ����ɭ�ִ����ɹ� -->" << endl;	
			}
			else
				cout << "<-- ����ɭ�ִ���ʧ�� -->" << endl;
        	break; 

        case 2:  //��ӡɭ�ֵ����ֱ���
        	system("cls");  //�����Ļ
			cout<<"�������";
			preTraverse(T1);
			cout << endl;
			cout<<"�������";
			postTraverse(T1);
			cout << endl;
			cout<<"��δ���";
//			hieOrder(T);
			cout<<endl;
			break;

		case 3:  //��ɭ�ֵĸ߶�
			system("cls");  //�����Ļ
			nR = height(T);
			cout << "����ɭ�ֵĸ߶ȣ�" << nR << endl;
			break;

		case 4:  //��ɭ�ֵĽڵ�����
			system("cls");  //�����Ļ
			nR = nodeNum(T);
			cout << "����ɭ�ֵĽ������" << nR << endl;
			break;

		case 5:  //��ɭ��Ҷ�ӽڵ���
			system("cls");  //�����Ļ
			nR = leafNum(T);
			cout << "����ɭ�ֵ�Ҷ�ӽ������" << nR << endl;
			break;

		case 6:  //��ɭ�ֵĶ�
			system("cls");  //�����Ļ
			nR = 0;
			nR = height(T);
			cout << "����ɭ�֣��Ķȣ�" << nR << endl;
			break;

		case 7:  //��������ڵ�ֵ�����κ�
			system("cls");  //�����Ļ
			if(T==NULL)
			{
				cout<<"<--����ɭ�֣�Ϊ�ա�-->"<<endl;
				break;
			}
			cout<<"<--����ɭ�֣��������м���Σ�"<<endl;
			outPreOrder(T,1);    //����������ֵ�����
			cout<<endl;
			outGList(T);
			cout<<endl;
			break;

		case 8:  //���������ʾ����
			system("cls");  //�����Ļ
			if(T==NULL)
			{
				cout<<"<--����ɭ�֣�Ϊ�ա�-->"<<endl;
				break;
			}
			cout<<"����ɭ�֣��������ʽ�����"<<endl;
			cout<<"(";       //Ϊ�����һ���������
			outGList(T);     //�������ʽ���
			cout<<endl;
			break;

		case 9:  //��������ɭ�֣�
			system("cls");  //�����Ļ
			if (T!=NULL)
				destroyTree(T);  //���ٶ�����			
			cout<<"<-- ����ɭ�֣��Ѿ����� -->"<< endl;
			break;
        }

		system("pause");
		system("cls");
    } while (nChoice != 0);  //ѭ����ʾ�˵���nMenu==0�˳�

    return 0;
}

int search(int k,int arr[])
{
	int x = k % 11;
	int i;
	for(i = x; (i-1)%x == 0; i++)
	{
		if(k == arr[i])
			return i;
	}
	 return -1;
}
