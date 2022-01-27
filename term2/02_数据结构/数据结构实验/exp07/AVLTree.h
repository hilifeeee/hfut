//ƽ����������������ʵ��
#include <iostream> 

using namespace std;

typedef int elementType;


typedef struct avlNode
{
	elementType data;
	int bf;
	struct avlNode *lChild,*rChild;
}btNode, *AvlTree;


//LL�͵���
btNode* LL(btNode* A, btNode* B)  //���ص���������������B
{
	A->lChild=B->rChild;   //B������������ΪA��������
	B->rChild=A;           //AΪB���Һ��� 
	A->bf=0;               //A��ƽ������Ϊ0
	B->bf=0;               //B��ƽ������Ϊ0

	return B;              //BΪ������ĸ����
}

//LR�͵���
btNode* LR(btNode* A, btNode* B)  //���ص���������������ָ��
{
	btNode* C=B->rChild;   //C��ΪB��������
	A->lChild=C->rChild;   //C����������ΪA��������
	B->rChild=C->lChild;   //C����������ΪB��������
	C->lChild=B;           //B��ΪC��������
	C->rChild=A;           //A��ΪC��������
	   //����ƽ������
	   //�����½����뵽C�Ĳ�ͬλ�ã��Ե�����A��B��C��ƽ�����ӽ��е���
	switch(C->bf)
	{
	case 1:  //�½����뵽��C����������
		A->bf=-1;
		B->bf=0;
		break;
	case 0:  //��򵥵�LR�ͣ���B���������գ��²�����ΪC����
		A->bf=0;
		B->bf=0;
		break;
	case -1:  //�½����뵽��C����������
		A->bf=0;
		B->bf=1;
		break;
	}
	C->bf=0;  //����C��ƽ������

	return C;  //CΪ������ĸ����
}


//RR�͵���
btNode* RR(btNode* A, btNode* B)  //���ص���������������ָ��
{
	A->rChild=B->lChild;   //B������������ΪA��������
	B->lChild=A;           //AΪB������
	A->bf=0;
	B->bf=0;

	return B;              //BΪ������ĸ����
}
//RL�͵���
btNode* RL(btNode* A, btNode* B)
{
	btNode* C=B->lChild;  //C��ΪB��������
	A->rChild=C->lChild;  //C����������ΪA��������
	B->lChild=C->rChild;  //C����������ΪB��������
	C->lChild=A;          //A��ΪC������
	C->rChild=B;          //B��ΪC���Һ���
	    //����ƽ������
	    //�����½����뵽C�Ĳ�ͬλ�ã��Ե�����A��B��C��ƽ�����ӽ��е���
	switch(C->bf)
	{
	case 1:  //�½����뵽��C��������
		A->bf=0;
		B->bf=-1;
		break;
	case 0:  //��򵥵�RL�ͣ���B��������Ϊ�գ��²�����ΪC����
		A->bf=0;
		B->bf=0;
		break;
	case -1:  //�½����뵽��C����������
		A->bf=1;
		B->bf=0;
		break;
	}
	C->bf=0;  //����C��ƽ������

	return C;  //CΪ������ĸ����
}

int InsertNode(btNode *&T, elementType x)
{
	btNode *p,*s;
	btNode *A,*Af,*B;
	int d;
	if(T==NULL)   //����������Ϊ�����
	{
		T=new btNode;
		T->data=x;
		T->lChild=NULL;
		T->rChild=NULL;
		T->bf=0;
		return 1;
	}	
	
	Af=NULL;
	p=NULL;    //������ĸ����
	s=T;
	A=T;
	while(s)
	{
		if(s->data==x)  //�ؼ����Ѿ����ڣ�����ʧ�ܣ��˳�
			return 0;
		if(s->bf!=0)    //���������p
		{
			Af=p;
			A=s;
		}
		p=s;           //pΪ������ĸ����
		if(s->data>x)
			s=s->lChild;
		else
			s=s->rChild;	
	}

	s=new btNode;
	s->data=x;
	s->lChild=NULL;
	s->rChild=NULL;
	s->bf=0;

	if(p->data>x)
		p->lChild=s;   //�½�����Ϊp������
	else
		p->rChild=s;   //�½�����Ϊp���Һ���

	//�½���Ѿ����룬AΪ��Ͳ�ƽ�����������
	//dΪ��ǣ�d=1���½����뵽A����������d=-1���½����뵽A��������
	if(A->data>x)      //x���뵽A����������
	{
		B=A->lChild;   //BΪA������
		p=B;
		d=1;
	}
	else               //x���뵽A����������
	{
		B=A->rChild;   //BΪA���Һ���
		p=B;
		d=-1;
	}

	//�޸Ľ��B���²�����s·���ϸ�����bfֵ
	while(p!=s)
	{
		if(p->data>x)   //p������������
		{
			p->bf=1;
			p=p->lChild;		
		}
		else             //p������������
		{
			p->bf=-1;
			p=p->rChild;	
		}	
	}

	if(A->bf==0)   //Aԭ��bfΪ0������󲻻�ʧȥƽ��
	{
		A->bf=d;
		return 1;	
	}
	if(A->bf==-d)  //�½����ڽϵ������ϣ�A��ƽ�����ӱ�Ϊ0
	{
		A->bf=0;
		return 1;
	}

	//�½������ڽϸ������ϣ�ʧ�⣬��Ҫ����
	if(d==1)       //�½�������A����������
	{
		if(B->bf==1)
			B=LL(A,B);  //LL�͵���
		else
			B=LR(A,B);  //LR�͵���
	}
	else          //�½�������A����������
	{
		if(B->bf==-1)
			B=RR(A,B);  //RR�͵���
		else
			B=RL(A,B);  //RL�͵���	
	}

	if(Af==NULL)
		T=B;   //ԭ����AΪ����
	else
	{
		if(Af->lChild==A)
			Af->lChild=B;
		else
			Af->rChild=B;	
	}
}

//��������ƽ��������㷨��ʼ------------------------------------------------------------------
void CreateAVLTree(btNode *&T)
{
	elementType x;	
	T=NULL;      //��ʼ������������Ϊ����
	cout<<"�����������ݣ�������-9999�˳�����"<<endl;
	cout<<"x=";
	cin>>x;
	    //ѭ���������ݣ�������㣬���뵽ƽ��������У�-9999�˳�
	while(x!=-9999)
	{		
		InsertNode(T,x);   //ƽ�������������

		cout<<"x=";
		cin>>x;	
	}
}
//��������ƽ��������㷨����------------------------------------------------------------------


//�ݹ��������
void preTraverse(btNode *T)
{
	if(T)
	{
		cout<<T->data<<" ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		preTraverse(T->lChild);     //�������������
		preTraverse(T->rChild);     //�������������
	}
}
//�������--�ݹ�
void inTraverse(btNode *T)
{
	if(T)
	{		
		inTraverse(T->lChild);      //�������������
		cout<<T->data<<" ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
		inTraverse(T->rChild);      //�������������
	}
}
//�������--�ݹ�
void postTraverse(btNode *T)
{
	if(T)
	{		
		postTraverse(T->lChild);      //�������������		
		postTraverse(T->rChild);      //�������������
		cout<<T->data<<" ";         //���ʸ���㡣��ӡ��ǰ���Ԫ��ֵ�����visit(T)����
	}
}

//����������ɾ������㷨��ʼ----------------------------------------------------------------
int delNode(btNode *&T, elementType x)
{
	btNode *p,*s,*pf;   //pָɾ����㣬pfָp�ĸ����
	
	if(T==NULL)
		return 0;       //����ɾ��ʧ��
	  //������ɾ�����p�����丸���ָ��pf
	p=T;
	pf=T;
	while(p)
	{		
		if(p->data==x)   //�ҵ�Ŀ���㣬�˳�ѭ��
			break;
		else if(p->data>x)  //����������
		{
			pf=p;
			p=p->lChild;
		}
		else                //����������
		{
			pf=p;
			p=p->rChild;		
		}	
	}
	if(p==NULL)   //Ŀ���㲻���ڣ�ɾ��ʧ��
		return 0;
	    //���濪ʼɾ�����p���丸���Ϊpf
	if(p->lChild==NULL)   //pû������������Ҷ�ӽ�㣬���������ĸ�������p
	{
		if(pf==p)   //ɾ�����Ǹ����
			T=p->rChild;
		else
		{
			if(pf->lChild==p)
				pf->lChild=p->rChild;
			else
				pf->rChild=p->rChild;		
		}
		delete p;	
	}
	else if(p->rChild==NULL)  //pû��������
	{
		if(pf==p)   //ɾ�����Ǹ����
			T=p->lChild;
		else
		{
			if(pf->lChild==p)
				pf->lChild=p->lChild;
			else
				pf->rChild=p->lChild;		
		}
		delete p;		
	}
	else    
	{       //���淨1
		    //p�����������Բ��գ�p������ֱ��ǰ���������p���������ֵ������
		pf=p;		
		s=p->lChild;
		while(s->rChild)
		{
			pf=s;			
			s=s->rChild;
		}
		p->data=s->data;
		if(pf==p)  //sΪp��pf���������ĸ���㣬��û����������s��p��pf����ֱ��ǰ������s������������Ϊp����������
			pf->lChild=s->lChild;
		else
			pf->rChild=s->lChild;
		delete s;	
	}	
	return 1;
}

//����������ɾ������㷨��ʼ----------------------------------------------------------------

//���ٶ�����
void DestroyBt(btNode *&T)
{
	if(T)
	{
		DestroyBt(T->lChild);   //�ݹ�����������
		DestroyBt(T->rChild);   //�ݹ�����������
		delete T;               //�ͷŸ����
		T=NULL;
	}
}

//��������߶ȣ���ȣ�
int btHeight(btNode *T)
{
	int lh,rh;
	if(!T)
		return 0;
	else
	{
		lh=btHeight(T->lChild);   //���������߶�
		rh=btHeight(T->rChild);   //���������߶�
		//return (lh>rh?lh:rh)+1;  //����д��
		if(lh>rh)
			return lh+1;
		else
			return rh+1;
	}
}

//����ƽ������bf--����ɾ���㷨
void setBf(btNode *&T,elementType x)
{
	btNode *p;
	
	if(T==NULL)
		return;
	p=T;
	while(p)
	{
		p->bf=btHeight(p->lChild)-btHeight(p->rChild);
		if(p->data>x)
			p=p->lChild;
		else
			p=p->rChild;	
	}
}

//�������������ҽ���㷨��ʼ----------------------------------------------------------------
btNode* Search(btNode *&T, elementType x)
{
	btNode *p,*s,*pf;   //pָɾ����㣬pfָp�ĸ����
	
	if(T==NULL)
		return NULL;       //��������ʧ��
	  //������ɾ�����p�����丸���ָ��pf
	p=T;
	pf=T;
	while(p)
	{		
		if(p->data==x)   //�ҵ�Ŀ���㣬�˳�ѭ��
			break;
		else if(p->data>x)  //����������
		{
			pf=p;
			p=p->lChild;
		}
		else                //����������
		{
			pf=p;
			p=p->rChild;		
		}	
	}
	
	if(p==NULL)   //Ŀ���㲻���ڣ�����ʧ��
		return NULL;
			
	return p;
}
