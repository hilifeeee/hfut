//************************************************************//
//*    ͼ���ڽӾ���洢��ͷ�ļ����ļ�����grpAdjMatrix.h      *//
//*                                                          *//
//************************************************************//

//#include "stdio.h"
//#include "stdlib.h"
//#include "iostream.h"
//#include "string.h"

#define INF 65535          //���������
#define MaxVerNum  100     //������󶥵����
//typedef int elementType;  //����ͼ�ж������������
typedef char elementType;  //����ͼ�ж������������
typedef int cellType;      //�����ڽӾ�����Ԫ�ص���������
                           //����Ȩͼ��1-���ڣ��бߣ���0-�����ڣ��ޱߣ�
                           //����Ȩͼ��Ϊ�ߵ�Ȩֵ���ر��������
                           //ö��ͼ������--����ͼ(UDG)��������(UDN)������ͼ(DG)��������(DN)
typedef enum{UDG, UDN, DG, DN} GraphKind;  

bool visited[MaxVerNum+1];  //ȫ�����飬��Ƕ����Ƿ��Ѿ����ʣ�visited[0]��Ԫ����

//****************************************************//
//*  �����ڽӾ����ʾ��ͼ�ṹ��5��������ɣ�         *//
//*      data[]���鱣��ͼ�ж�������Ԫ��              *//
//*      AdjMatrix[][]�ڽӾ���                       *//
//*      VerNum�������                              *//
//*      ArcNum�ߣ���������                          *//
//*      gKindö��ͼ������                           *//
//*  ���ǵ����Ƶ�ͳһ�ԣ�ͼ�������ƶ���ΪGraph       *//
//****************************************************//
typedef struct GraphAdjMatrix
{
	elementType Data[MaxVerNum+1];                 //�������飬��Ŷ���Ԫ�ص�ֵ��Data[0]��Ԫ����
	cellType AdjMatrix[MaxVerNum+1][MaxVerNum+1];  //�ڽӾ��������±�Ϊ0��Ԫ���ã���AdjMatrix[1][1]��Ԫ��ʼ
	int VerNum;       //������
	int ArcNum;       //�����ߣ���
	GraphKind gKind;  //ͼ������:0-����ͼ��1-��������2-����ͼ��3-������
} Graph;  //ͼ��������

//******************* ����ͼ�ж���ĺ���*********************//
//* �������ܣ���ӡͼ�ж���Ԫ�أ������Ϊ�Ѿ�����            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID Ŀ�궥����   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����visit(Graph &G, int verID)                    *//
//***********************************************************//
void visit(Graph &G, int verID)
{        //�����Ŵ�1��ʼ������0��Ԫ����
	cout<<G.Data[verID]<<"\t";
	visited[verID]=true;
}

//*******************  ͼ�в���Ŀ�궥�� *********************//
//* �������ܣ���������Ԫ�أ���ͼ�в��Ҵ˶���Ԫ��            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��elementType v Ŀ�궥��   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ��int�����Ŀ�궥����ڣ����ض����ţ�         *//
//*                �����Ŵ�1��ʼ�����򷵻�-1              *//
//* �� �� ����visit(Graph &G, int verID)                    *//
//***********************************************************//
int LocateVertex(Graph &G, elementType v)
{
	for(int i=1;i<=G.VerNum;i++)
	{
		if( G.Data[i]==v )
			return i;
	}
	return -1;
}
//�󶥵�v�ĵ�һ���ڽӵ�
int firstAdj(Graph &G,int v)
{
	int w;
	for(w=1;w<=G.VerNum;w++)
	{
		if((G.AdjMatrix[v][w]>=1)   &&
		   (G.AdjMatrix[v][w])<INF)
		   return w;    //���ص�һ���ڽӵ���
	}
	 return 0;          //δ�ҵ��ڽӵ㣬����0
}
//�󶥵�v��λ���ڽӵ�w�����һ���ڽӵ�
int nextAdj(Graph &G,int v,int w)
{
	int k;
	for(k=w+1;k<=G.VerNum;k++)
	{
		if((G.AdjMatrix[v][k]>=1)   &&
		   (G.AdjMatrix[v][k])<INF)
		   return k;    //����v��λ��w֮�����һ���ڽӵ�k
	}
	return 0;           //��������һ���ڽӵ㣬����0
}

//*************** ��ͨͼ��һ����ͨ������DFS *****************//
//* �������ܣ�������ȱ�����ͨͼ����һ����ͨ����            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID ��ʼ������   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����DFS(Graph &G, int verID)                      *//
//***********************************************************//
void DFS(Graph &G, int verID)
{
	int w;
	visit(G, verID);
	w=firstAdj(G,verID);
	while(w!=0)
	{
		if(!visited[w])        //w��δ����
			DFS(G,w);          //�ݹ���ȱ���
		w=nextAdj(G,verID,w);    //�ݹ鷵�غ�����verID��λ��w�����һ���ڽӵ�	
	}

/*	
//���´������ʵ�ֱ���DFS
	for(int w=1;w<=G.VerNum;w++)
	{
		if((G.AdjMatrix[verID][w]>=1) && 
		   (G.AdjMatrix[verID][w]<INF) &&
		   (!visited[w]))
		{
			DFS(G,w);
		}
	}
*/
}

//*******************    ����ͼ��DFS    *********************//
//* �������ܣ���ͨ�����ͨ��DFS����                         *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID ��ʼ������   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����DFSTraverse(Graph &G, int verID)              *//
//***********************************************************//
void DFSTraverse(Graph &G, int verID)
{
	int vID;
	for(vID=1;vID<=G.VerNum;vID++)  //���ʱ�������ʼ��
		visited[vID]=false;
	
	DFS(G,verID);  //��ָ���Ķ��㣬����ָ���ĵ�һ����ͨ����
	for(vID=1;vID<=G.VerNum;vID++)  //�����α���ͼ����������ͨ����
	{
		if(!visited[vID])
			DFS(G,vID);
	}
}

//*************** ��ͨͼ��һ����ͨ������BFS *****************//
//* �������ܣ�������ȱ�����ͨͼ����һ����ͨ����            *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID ��ʼ������   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����BFS(Graph &G, int verID)                      *//
//***********************************************************//
void BFS(Graph &G, int verID)
{
	visit(G, verID);
	seqQueue Q;
	initialQueue(&Q);             //��ʼ��ѭ��˳�����
	enQueue(&Q, verID);           //���ΪverID�Ķ������
	int v,w,x;
	while(!queueEmpty(Q))         //���в���ѭ��������
	{
		getFront(Q, v);           //ȡ��ͷԪ�ص�v����������Ϊv��
		outQueue(&Q,x);           //v����		
		w=firstAdj(G,v);          //����v�ĵ�һ���ڽӵ�
		while(w!=0)
		{
			if(!visited[w])       //w��δ���ʣ�����w��������ѷ���
			{
				visit(G,w);         
				enQueue(&Q,w);    //����w���
			}
			w=nextAdj(G,v,w);     //��������vλ��w�����һ���ڽӵ�
		}
	}


/*
//���´������ʵ��BFS	
	while(!queueEmpty(Q))  //���в���ѭ��������
	{
		getFront(Q, u);  //ȡ��ͷԪ�ص�u����������Ϊu��
		outQueue(&Q,x);      //u����		
		for(int w=1;w<=G.VerNum;w++)
		{
			if((G.AdjMatrix[u][w]>=1) && 
			   (G.AdjMatrix[u][w]<INF) &&
			   (!visited[w]))
			{
				visit(G,w);     //���ʱ��w���ڽӵ�
				enQueue(&Q,w);  //���w���ڽӵ����
			}
		}
	}
*/
}
//*******************    ����ͼ��BFS    *********************//
//* �������ܣ���ͨ�����ͨ��BFS����                         *//
//* ��ڲ���  Graph G�������ʵ�ͼ��int verID ��ʼ������   *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����BFSTraverse(Graph &G, int verID)              *//
//***********************************************************//
void BFSTraverse(Graph &G, int verID)
{
	int vID;
	for(vID=1;vID<=G.VerNum;vID++)  //���ʱ�������ʼ��
		visited[vID]=false;
	
	BFS(G,verID);  //��ָ���Ķ��㣬����ָ���ĵ�һ����ͨ����
	for(vID=1;vID<=G.VerNum;vID++)  //�����α���ͼ����������ͨ����
	{
		if(!visited[vID])
			BFS(G,vID);  
	}

}

//******************** ��ӡͼ�������Ϣ *********************//
//* �������ܣ���ӡͼ�������Ϣ                              *//
//* ��ڲ�����Graph G������ӡ��ͼ                           *//
//* ���ڲ�������                                            *//
//* �� �� ֵ����                                            *//
//* �� �� ����GraphPrint(Graph &G)                          *//
//***********************************************************//
void printGraph(Graph &G)
{
	int i=0,j=0;
	//��ӡͼ������
	switch(G.gKind)
	{
	case UDG:
		cout<<"ͼ���ͣ�����ͼ"<<endl;
		break;
	case UDN:
		cout<<"ͼ���ͣ�������"<<endl;
		break;
	case DG:
  	    cout<<"ͼ���ͣ�����ͼ"<<endl;
		break;
	case DN:
		cout<<"ͼ���ͣ�������"<<endl;
		break;
	default:
		cout<<"ͼ���ʹ���"<<endl;
		break;
	}
	//��ӡͼ�Ķ�����
	cout<<"��������"<<G.VerNum<<endl;
	//��ӡͼ�ı���
	cout<<"��  ����"<<G.ArcNum<<endl;
	//��ӡ���㼰����
	cout<<"��  �ţ�";
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	cout<<"��  �㣺";
	for(i=1;i<=G.VerNum;i++)
	{
		cout<<G.Data[i]<<"\t";
	}
	cout<<endl;

	//��ӡ�ڽӾ���
	cout<<"ͼ���ڽӾ���"<<endl;
	for(i=1;i<=G.VerNum;i++)
	{   
		cout<<"\t";
		for(j=1;j<=G.VerNum;j++)
		{
			if((G.gKind==UDN || G.gKind==DN) && G.AdjMatrix[i][j]==INF)
				cout<<"INF"<<"\t";  //���������ʱ����ӡ��INF����ʾ
			else
				cout<<G.AdjMatrix[i][j]<<"\t";
		}
		cout<<endl;
	}

}
