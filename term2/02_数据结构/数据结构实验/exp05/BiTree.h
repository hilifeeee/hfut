#include <string.h>
#include <iostream>

#define NODENUM  100       //�����������
typedef char elementType;  //elementType ����Ϊ�ַ�����
//typedef int elementType;  //elementType ����Ϊ��������

typedef struct biNode
{
	elementType data;
	struct biNode* lChild, * rChild;
}btNode, * BiTree;

using namespace std;

//�������
void preTraverse(btNode* T)
{
	if (T)
	{
		cout << T->data << " ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		preTraverse(T->lChild);     //�������������
		preTraverse(T->rChild);     //�������������
	}
}
//�������
void inTraverse(btNode* T)
{
	if (T)
	{
		inTraverse(T->lChild);      //�������������
		cout << T->data << " ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		inTraverse(T->rChild);      //�������������
	}
}
//�������
void postTraverse(btNode* T)
{
	if (T)
	{
		postTraverse(T->lChild);      //�������������		
		postTraverse(T->rChild);      //�������������
		cout << T->data << " ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
	}
}

//��Ԫ��ֵ���ؽڵ�
void btSearch(btNode* T, elementType x, btNode*& pR)
{
	//pR--���ص�Ŀ����ָ��
	if (T)
	{
		if (T->data == x)
			pR = T;
		else
		{
			btSearch(T->lChild, x, pR);  //�ݹ�����������
			btSearch(T->rChild, x, pR);  //�ݹ�����������
		}
	}
}

//��������߶ȣ���ȣ�
int btHeight(btNode* T)
{
	int lh, rh;
	if (!T)
		return 0;
	else
	{
		lh = btHeight(T->lChild);   //���������߶�
		rh = btHeight(T->rChild);   //���������߶�
		//return (lh>rh?lh:rh)+1;  //����д��
		if (lh > rh)
			return lh + 1;
		else
			return rh + 1;
	}
}

//��������
bool getNodeLevel(btNode* T, elementType x, int& nLevel, int nLevelTemp)
{
	//nLevel ����Ŀ�������
	//nLevelTemp  ���浱ǰ������
	if (!T)
	{
		nLevel = 0;
		return false;
	}
	if (T->data == x)
	{
		nLevel = nLevelTemp;
		return true;
	}
	if (getNodeLevel(T->lChild, x, nLevel, nLevelTemp + 1))
	{
		cout << T->data << ", ";
		return true;
	}
	if (getNodeLevel(T->rChild, x, nLevel, nLevelTemp + 1))
	{
		cout << T->data << ", ";
		return true;
	}
	return false;
}

void  exp02(btNode* T,int& nLevel, int nLevelTemp)
{
	if (T)
	{
		exp02(T->lChild,nLevel,nLevelTemp);      //�������������
		cout << T->data << " ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		getNodeLevel(T,T->data,nLevel,nLevelTemp);
		cout << "���ֵ��" << nLevel << endl; 
		exp02(T->rChild,nLevel,nLevelTemp);      //�������������
	}
}
//��˫�׽�㣬����˫�׽��ָ��
void getParent(btNode* T, elementType x, btNode*& pParent)
{
	if (T->data == x)
	{
		cout << "Ŀ����Ϊ����㣬�޸���㡣" << endl;;
		return;
	}
	if ((T->lChild && T->lChild->data == x) || (T->rChild && T->rChild->data == x))
	{
		pParent = T;  //ȡ�ø��ڵ�ָ�룬����
		return;
	}
	if (T->lChild)
		getParent(T->lChild, x, pParent);  //�ݹ�����������
	if (T->rChild)
		getParent(T->rChild, x, pParent);  //�ݹ�����������
}
//���ӽ��
int getChildren(btNode* T, elementType x, btNode*& pL, btNode*& pR)
{
	//pL,pR�ֱ𷵻����Һ��ӽ��ָ��
	btNode* p;
	pL = NULL;
	pR = NULL;
	if (T == NULL)
		return 0;       //����������
	btSearch(T, x, p);      //�������x
	if (p == NULL)
		return 1;       //x��������
	if (p->lChild)
	{
		pL = p->lChild;   //��������ָ��
	}
	if (p->rChild)
		pR = p->rChild;   //�����Һ���ָ��
	return 2;
}
//���ֵܽ��
int getSibling(btNode* T, elementType x, btNode*& pL, btNode*& pR)
{
	//pL�������ֵ�ָ�룬pR�������ֵ�ָ��
	btNode* p = NULL;
	pL = NULL;
	pR = NULL;
	if (T == NULL)
		return 0;   //����
	getParent(T, x, p);
	if (p == NULL)
	{
		if (T->data == x)
			return 1;   //xΪ�����
		else
			return 2;   //x��������
	}

	if (p->lChild && p->lChild->data == x)
	{
		pR = p->rChild;
		return 3;    //���ֵܿ��ܴ���
	}

	if (p->rChild && p->rChild->data == x)
	{
		pL = p->lChild;
		return 4;   //���ֵܿ��ܴ���
	}
}

//�������ܽ����
void getNodeNumber(btNode* T, int& num)
{                  //��������������������
	if (T)
	{
		num++;    //���������
		getNodeNumber(T->lChild, num);    //�ۼ����������
		getNodeNumber(T->rChild, num);    //�ۼ����������
	}

}

int getNodeNumber1(btNode* T)
{
	if (T == NULL)
		return 0;
	else
		return (1 + getNodeNumber1(T->lChild) + getNodeNumber1(T->rChild));
}
//��Ҷ�ӽ����
void getLeafNumber(btNode* T, int& num)
{
	if (T)
	{
		if (T->lChild == NULL && T->rChild == NULL)
			num++;
		getLeafNumber(T->lChild, num);
		getLeafNumber(T->rChild, num);
	}
}
//��1�Ƚ����
void get1DegreeNumber(btNode* T, int& num)
{
	if (T)
	{
		if ((T->lChild && T->rChild == NULL) || (T->lChild == NULL && T->rChild))
			num++;
		get1DegreeNumber(T->lChild, num);
		get1DegreeNumber(T->rChild, num);
	}
}
//��2�Ƚ����
void get2DegreeNumber(btNode* T, int& num)
{
	if (T)
	{
		if (T->lChild && T->rChild)
			num++;
		get2DegreeNumber(T->lChild, num);
		get2DegreeNumber(T->rChild, num);
	}
}
//������������
void swapTree(btNode* T) 
{
	btNode* temp;
	if (T)
	{
		//�ݹ� 
		swapTree(T->lChild);
		swapTree(T->rChild);
		//�������� 
		temp = T->lChild;
		T->lChild = T->rChild;
		T->rChild = temp; 
	}
} 
//�ж�����
bool isEmpty(btNode* T)
{
	if (T != NULL)
		return false;
	else
		return true;
}

//���ٶ�����
void destroyBt(btNode*& T)
{
	if (T)
	{
		destroyBt(T->lChild);
		destroyBt(T->rChild);
		delete T;
	}
	T = NULL;
}
//�����ļ�������������ʼ-------------------------------------------------------------------------
//********************** �������ļ����������� ***********************//
//* ��������ɣ���һ�������ݴ��ı��ļ���������                      *//
//* �ڶ���������ݹ鴴��������                                      *//
//* ������2���������                                               *//
//*******************************************************************//

//ɾ���ַ������ַ�������߿ո�
void strLTrim(char* str)
{
	int i, j;
	int n = 0;
	n = strlen(str) + 1;
	for (i = 0; i < n; i++)
	{
		if (str[i] != ' ')  //�ҵ������һ���ǿո�λ��
			break;
	}
	//�Ե�һ���ǿո��ַ�Ϊ���ַ��ƶ��ַ���
	for (j = 0; j < n; j++)
	{
		str[j] = str[i];
		i++;
	}
}

//���ı��ļ����ݶ��뵽�����У�ͬʱ����ʵ�ʽ������
bool ReadFileToArray(char fileName[], char strLine[NODENUM][3], int& nArrLen)
{
	//���ı��ļ����ݵ����飬�������鼰�䳤��
	FILE* pFile;      //������������ļ�ָ��
	char str[1000];   //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����

	pFile = fopen(fileName, "r");
	if (!pFile)
	{
		cout << "�����ļ�" << fileName << "��ʧ�ܡ�" << endl;
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)  //�������к�ע����
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')               //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //����ע����
			continue;
		else                            //��ע���С��ǿ��У�����ѭ��
			break;
	}
	//ѭ��������str��Ӧ���Ѿ��Ƕ��������ݱ�ʶ"BinaryTree"���ж��ļ���ʽ
	if (strstr(str, "BinaryTree") == NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile);           //�ر��ļ�
		return false;
	}

	nArrLen = 0;     //�����кų�ʼ��Ϊ0
	while (fgets(str, 1000, pFile) != NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //ע���У�������������ȡ��һ��
			continue;

		char* token = strtok(str, " ");   //�Կո�Ϊ�ָ������ָ�һ������
		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ�������������ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}

		strLine[nArrLen][0] = *token;  //��ȡ�������
		token = strtok(NULL, " ");  //��ȡ��һ���Ӵ������˽�����������Ϣ
		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ�������������ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		strLine[nArrLen][1] = *token;  //��ȡ�˽�����������Ϣ����
		token = strtok(NULL, " ");  //��ȡ��һ���Ӵ������˽�����������Ϣ
		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡ�������������ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		strLine[nArrLen][2] = *token;  //��ȡ�˽�����������Ϣ����

		nArrLen++;  //�����кż�1	
	}

	fclose(pFile); //�ر��ļ�
	return true;
}


//�����鴴��������--�����б�����Ƕ��������������У���ÿ������������Ϣ
bool CreateBiTreeFromFile(btNode*& pBT, char strLine[NODENUM][3], int nLen, int& nRow)
{
	//strLine[NODENUM][3]--����ڵ����ݵĶ�ά����
	//nLen--���鳤�ȣ������ڵ����
	//nRow--���鵱ǰ�к�

	if ((nRow >= nLen) || (nLen == 0))
		return false;  //�����Ѿ�������ϣ�����û�����ݣ��˳�

	//�����������ݵݹ鴴������
	pBT = new btNode;
	pBT->data = strLine[nRow][0];
	pBT->lChild = NULL;
	pBT->rChild = NULL;

	int nRowNext = nRow;  //�������εݹ���к�	

	if (strLine[nRowNext][1] == '1')  //��ǰ��������������ݹ鴴��������������һ������
	{
		nRow++;
		CreateBiTreeFromFile(pBT->lChild, strLine, nLen, nRow);
	}

	if (strLine[nRowNext][2] == '1')  //��ǰ��������������ݹ鴴��������������һ������
	{
		nRow++;
		CreateBiTreeFromFile(pBT->rChild, strLine, nLen, nRow);
	}

	return true;
}
