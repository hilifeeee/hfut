//���Ե�������
#include <iostream>
#include "BiTree.h"

int main(int argc, char* argv[])
{	//BiTree BT;
	btNode* T = NULL; //* p;
	btNode* pL, * pR;
	btNode* pParent;
	elementType x;
	int nChoice;
	//elementType InArr[NODENUM];  //InArr[0]����

	char strLine[NODENUM][3]; //�ļ����ݶ��뵽����		
	int  nArrLen = 0;           //����ʵ�ʳ��ȣ��������
	int  nR = 0;
	int i = 0;

	do
	{
		//�����˵�
		cout << "****** ��������������ṹ���Գ��� ******" << endl;
		cout << "*  0--�˳�                             *" << endl;
		cout << "*  1--�ļ�����������                   *" << endl;
		cout << "*  2--��ӡ�����������ֱ���             *" << endl;
		cout << "*  3--����������ڵ�ֵ�������         *" << endl;
		cout << "*  4--��������߶ȣ���ȣ�             *" << endl;
		cout << "*  5--��������                       *" << endl;
		cout << "*  6--��Ҷ�ӽڵ�����                   *" << endl;
		cout << "*  7--���Ϊ2�Ľڵ�����                *" << endl;
		cout << "*  8--��Ԫ��x����ؽڵ�ֵ              *" << endl;
		cout << "*  9--��Ԫ��x�Ĳ��                    *" << endl;
		cout << "*  10--˳�������ת����������          *" << endl;
		cout << "*  11--������������                    *" << endl;
		cout << "*  12--���ٶ�����                      *" << endl;
		cout << "****************************************" << endl;
		cout << "��ѡ�����(0-12)��" << endl;
		cin >> nChoice;
		switch (nChoice)
		{
		case 0:  //�˳�����
			system("cls");  //�����Ļ
			cout << "<-- �����˳� -->" << endl;  //ѡ���˳�
			break;

		case 1:  //�������ļ�����������
			system("cls");  //�����Ļ
			if (T != NULL)  //��ֹ�ظ�����������ڴ�й¶
			{
				cout << "�������Ѿ����ڣ��������´��������������ٴ�����" << endl;
				break;
			}
			char strFileName[100];
			cout << "����������������ļ���(i.e. bt3.btr)��" << endl;
			cin >> strFileName;  //����̨���������ļ���			

			nArrLen = 0;  //���鳤��
			nR = 0;
			if (!ReadFileToArray(strFileName, strLine, nArrLen))
			{
				cout << "<--���ļ�����������ʧ�ܡ�-->" << endl;
				break;  //�ļ��򿪴��󣬷���
			}

			if (nArrLen == 0)
			{
				cout << ("<--�����ļ���û�н�����ݡ�-->") << endl; 
				break;
			}

			if (CreateBiTreeFromFile(T, strLine, nArrLen, nR)) //�ӵ�1�п�ʼ
				cout << "<--�����������ɹ���-->" << endl;
			else
				cout << "<--���ļ�����������ʧ�ܡ�-->" << endl;
			break;

		case 2:  //����������
			system("cls");  //�����Ļ
			cout << "���������������" << endl;
			if (isEmpty(T))
			{
				cout << "<--������Ϊ������-->" << endl;
				break;
			}
			cout << "�������";
			preTraverse(T);   //�ݹ��������
			cout << endl;
			cout << "�������";
			inTraverse(T);    //�ݹ��������
			cout << endl;
			cout << "�������";
			postTraverse(T);  //�ݹ�������
			cout << endl;
			break;

		case 3:	//����������ڵ�ֵ�������
			system("cls");  //�����Ļ
			cout << "����������ڵ�ֵ������������" << endl;
			nR = 0;
			i = 0;
			exp02(T,nR,i);
			break;
			
		case 4:  //��������߶ȣ���ȣ�
			system("cls");  //�����Ļ
			cout << "�������߶ȣ���ȣ���" << btHeight(T) << endl;//����������			
			break;

		case 5:  //������
			system("cls");  //�����Ļ
			nR = 0;
			getNodeNumber(T, nR);     //���ܽ����
			cout << "�������������" << nR << endl;
			break; 

		case 6: //��Ҷ�ӽ����
			system("cls");
			nR = 0;
			getLeafNumber(T, nR);
			cout << "������Ҷ�ӽ������" << nR << endl;
			break;

		case 7: //���Ϊ2�Ľڵ�����
			system("cls");
			nR = 0;
			get2DegreeNumber(T, nR);
			cout << "��������Ϊ2�������" << nR << endl;
			break;

		case 8: //��Ԫ��x����ؽڵ�ֵ
			system("cls");
			cout << "������Ԫ��x��ֵ��" << endl;
			cin >> x;//����Ԫ��x
			getParent(T, x, pParent);
			if (pParent != NULL)
			{
				cout << "�������ĸ���㣺" << pParent->data << endl;
			}
			else
			{
				cout << "�����ڸ��ڵ㣡" << endl;
			}
			getSibling(T, x, pL, pR);
			if (pL != NULL)
			{
				cout << "�����������ֵܽ�㣺" << pL->data << endl;
			}
			else
			{
				cout << "���������ֵܽڵ㣡" << endl;
			}
			if (pR != NULL)
			{
				cout << "�����������ֵܽ�㣺" << pR->data << endl;
			}
			else
			{
				cout << "���������ֵܽڵ㣡" << endl;
			}
			getChildren(T, x, pL, pR);
			if (pL != NULL)
			{
				cout << "�����������ӽ�㣺" << pL->data << endl;
			}
			else
			{
				cout << "���������ӽڵ㣡" << endl;
			}
			if (pR != NULL)
			{
				cout << "���������Һ��ӽ�㣺" << pR->data << endl;
			}
			else
			{
				cout << "�������Һ��ӽڵ㣡" << endl;
			}
			break;

		case 9: //��Ԫ��x�Ĳ��
			system("cls");
			cout << "������Ԫ��x��ֵ��" << endl;
			cin >> x;//����Ԫ��x
			nR = 0;
			getNodeLevel(T, x, nR, i);
			if (nR == 0) 
			{
				cout<<"x="<<x<<" ��㲻�����ϡ�"<<endl;
			} 
			else
			{
				cout << "Ԫ�صĲ��Ϊ��" << nR << endl;	
		    }
			break;

		case 10: //˳�������ת����������
			system("cls");  //�����Ļ
			if (T != NULL)  //��ֹ�ظ�����������ڴ�й¶
			{
				cout << "�������Ѿ����ڣ��������´��������������ٴ�����" << endl;
				break;
			}
			cout << "����������������ļ���(i.e. bt3.btr)��" << endl;
			cin >> strFileName;  //����̨���������ļ���			

			nArrLen = 0;  //���鳤��
			nR = 0;
			if (!ReadFileToArray(strFileName, strLine, nArrLen))
			{
				cout << "<--���ļ�����������ʧ�ܡ�-->" << endl;
				break;  //�ļ��򿪴��󣬷���
			}

			if (nArrLen == 0)
			{
				cout << ("<--�����ļ���û�н�����ݡ�-->") << endl; 
				break;
			}

			if (CreateBiTreeFromFile(T, strLine, nArrLen, nR)) //�ӵ�1�п�ʼ
				cout << "<--�����������ɹ���-->" << endl;
			else
				cout << "<--���ļ�����������ʧ�ܡ�-->" << endl;
			break;
			
		case 11: //������������
			system("cls");
			if (isEmpty(T))
			{
				cout << "<--������Ϊ������-->" << endl;
				break;
			}
			swapTree(T);
			cout << "�������������ɹ�" << endl;
			break;

		case 12:  //���ٶ�����
			system("cls");  //�����Ļ
			if (T != NULL)
				destroyBt(T);  //���ٶ�����			
			cout << "<-- �������Ѿ����٣�-->" << endl;
			break;

		}
		system("pause");
		system("cls");
	} while (nChoice != 0);  //ѭ����ʾ�˵���nMenu==0�˳�

	if (T != NULL)
		destroyBt(T);    //���ٶ�����

	return 0;
}
