#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "string.h"
#include "time.h"
//=========�Զ���ͷ�ļ�=================
#include "seqQueue.h"
#include "SeqStack.h"
#include "grpAdjMatrix.h"
#include "createGrpAdjMatrix.h"
#include "DijkstraAdjMatrix.h"
#include "Floyd.h"
#include "KruskalAdjMatrix.h"
#include "PrimAdjMatrix.h"
#include "TopoSortAdjMatrix.h"

using namespace std;

int main(int argc, char* argv[])
{
	Graph G;
	G.VerNum=-1;    //���ͼͼ��δ����
	int vID;        //����ı�ţ���1��ʼ�� 
	elementType x;  //ѡ���������ʼ����

	int i;
	int topoList[MaxVerNum+1];  //�����������е�����


	//�������˵�
    int nChoice=-1;
	do
	{
		//��ʾ���˵�
		cout<<"---ͼ���ڽӾ����ʾ���Գ���---"<<endl;
		cout<<"* 0-�˳�                     *"<<endl;
		cout<<"* 1-�����ļ�����ͼ           *"<<endl;
		cout<<"* 2-��ӡͼ                   *"<<endl;
		cout<<"* 3-��ͨͼDFS                *"<<endl;
		cout<<"* 4-����ͼDFS                *"<<endl;
		cout<<"* 5-��ͨͼBFS                *"<<endl;
		cout<<"* 6-����ͼBFS                *"<<endl;
		cout<<"* 7-Prim�㷨                 *"<<endl;
		cout<<"* 8-Kruskal�㷨              *"<<endl;
		cout<<"* 9-Dijkstra�㷨             *"<<endl;
		cout<<"* 10-Floyd�㷨               *"<<endl;
		cout<<"* 11-��������                *"<<endl;
		cout<<"* 12-�ؼ�·��                *"<<endl;
		cout<<"------------------------------"<<endl;
		cout<<"����������ѡ�������0-12����";
		cin>>nChoice;

		if(cin.fail())
		{
			
			cin.clear();
			cin.ignore();
			cin.sync();
			
			system("cls");  //�����Ļ
			cout<<"�������ݶ������ʹ���"<<endl;
			nChoice=-1;
			continue;
		}

		switch(nChoice)
		{
		case 0:        //0-�˳�
			cout<<endl;
			cout<<"<--  �����˳�  -->"<<endl<<endl;
			break;

		case 1:   //1-�����ļ�����ͼ
            system("cls");  //�����Ļ

			char strFileName[100];
			cout<<"������ͼ�����ļ���(i.e. Graph.grp)��";
			cin>>strFileName;  //����̨���������ļ���			

			if(CreateGrpFromFile(strFileName,G))  //���ļ���������Ԫ�أ�����ͼ			    
				printGraph(G);			
			break;

		case 2:  //2-��ӡͼ�������Ϣ
			system("cls");  //�����Ļ
			if(G.VerNum==-1)
			{
				cout<<endl<<"���� ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}
			printGraph(G);  //��ӡͼ
			cout<<endl;
			break;

		case 3:  //3-��ͨͼ��������DFS
			system("cls");  //�����Ļ
			if(G.VerNum==-1)
			{
				cout<<endl<<"���� ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}

			for(vID=1;vID<=MaxVerNum;vID++)  //���ʱ�������ʼ��
				visited[vID]=false;
			
			cout<<"������DFS����ʼ���㣺";
			cin>>x;

			vID=LocateVertex(G,x);
			if(vID==-1)
			{
				cout<<endl<<"����ѡ���������ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
				break;
			}
			cout<<endl<<"������ȱ����������У�"<<endl;
			DFS(G,vID);  //�ݹ����������ȱ����㷨��������ͨͼ��������һ����ͨ����

			cout<<endl<<endl;
			break;

		case 4:     //4-����ͼ�ģ�ͨ�ã�������ȱ���
			system("cls");  //�����Ļ
			if(G.VerNum==-1)
			{
				cout<<endl<<"���� ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}
			cout<<"������DFS����ʼ���㣺";
			cin>>x;
			vID=LocateVertex(G,x);
			if(vID==-1)
			{
				cout<<endl<<"����ѡ���������ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
				break;
			}
			cout<<endl<<"������ȱ����������У�"<<endl;
			DFSTraverse(G,vID);  //������ȱ���ͼ�ĸ�����ͨ����
			cout<<endl<<endl;
			break;

		case 5:  //5-������ȱ�����ͨͼ����һ����ͨ����
			system("cls");  //�����Ļ
			if(G.VerNum==-1)
			{
				cout<<endl<<"���� ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}			
			for(vID=1;vID<=MaxVerNum;vID++)  //���ʱ�������ʼ��
				visited[vID]=false;
			
			cout<<"������BFS����ʼ���㣺";
			cin>>x;

			vID=LocateVertex(G,x);
			if(vID==-1)
			{
				cout<<endl<<"����ѡ���������ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
				break;
			}
			cout<<endl<<"������ȱ����������У�"<<endl;
			BFS(G,vID);  //������ȱ�����ͨͼ����һ����ͨ����
			cout<<endl<<endl;
			break;

		case 6:  //6-������ȱ�������ͼ--��ͨ�����ͨ
			system("cls");  //�����Ļ
			if(G.VerNum==-1)
			{
				cout<<endl<<"���� ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}
			cout<<"������BFS����ʼ���㣺";
			cin>>x;
			vID=LocateVertex(G,x);
			if(vID==-1)
			{
				cout<<endl<<"����ѡ���������ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
				break;
			}
			cout<<endl<<"������ȱ����������У�"<<endl;
			BFSTraverse(G,vID);  //������ȱ���ͼ�ĸ�����ͨ����
			cout<<endl<<endl;

			break;

		case 7:  //7-Prim�㷨
			system("cls");
			if(G.VerNum==-1)
			{
				cout<<endl<<"����ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}

			cout<<"������Prim�㷨����ʼ���㣺";
			cin>>x;

			vID=LocateVertex(G, x);
			if(vID==-1)
			{
				cout<<endl<<"����ѡ���������ʼ���㲻��ͼ�ϣ��㷨ʧ�ܡ�"<<endl<<endl;
				break;
			}

			//��ʼ���Ѿ�ѡ����������
			for(i=1;i<=G.VerNum;i++)
				inTree[i]=0;  //��ʾȫ��û��ѡ��
			
			Prim(G,vID); //ִ��Prim�㷨������minEdges[]����

			//PrimPrint(G, minEdges, vID);  //��ӡ���

			break;

		case 8:  //8-Kruskal�㷨
			system("cls");
			if(G.VerNum==-1)
			{
				cout<<endl<<"����ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}
			Kruskal(G);
			disjointKruskal(G);   //ʹ�ò��鼯�����Kruskal�㷨
			break;

		case 9:  //9-Dijkstra�㷨
			system("cls");  //�����Ļ
			if(G.VerNum==-1)
			{
				cout<<endl<<"���� ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}
			cout<<"������ Dijkstra �㷨����ʼ���㣺";
			cin>>x;
			vID=LocateVertex(G,x);
			if(vID==-1)
			{
				cout<<endl<<"����ѡ�����ʼ���㲻��ͼ�ϣ�����ʧ�ܡ�"<<endl<<endl;
				break;
			}

			int path[MaxVerNum];
			int dist[MaxVerNum];
			Dijkstra(G, path, dist, vID);
			PrintDijkstra(G, path, dist, vID);  //��ӡ���·��
			break;

		case 10:  //10-Floyd�㷨
			system("cls");  //�����Ļ
			if(G.VerNum==-1)
			{
				cout<<endl<<"���� ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}
			
			cellType dist1[MaxVerNum][MaxVerNum];  //��ά�������
			int path1[MaxVerNum][MaxVerNum];       //��ά·������  

			Floyd(G, dist1, path1);  //ִ��Floyd�㷨
			PrintFloyd(G, dist1, path1);
			break;

		case 11:  //11-��������
			system("cls");  //�����Ļ
			if(G.VerNum==-1)
			{
				cout<<endl<<"���� ͼ��δ���������ȴ���ͼ����ִ�д˲�����"<<endl<<endl;
				break;
			}

			//if(TopologicalSortS(G, topoList)) //�������������㷨--ʹ��ջ
			//if(TopologicalSortQ(G, topoList)) //�������������㷨--ʹ�ö���
			if(TopologicalSort(G, topoList)) //�������������㷨--��ʹ��ջ�����У�����һ��solved[]����
			{
				cout<<endl;
				cout<<"��ͼ��������ɹ����������У�"<<endl;
				for(i=1;i<=G.VerNum;i++)  //�Զ����������������
					cout<<topoList[i]<<"\t";
				cout<<endl<<"��"<<endl;
				for(i=1;i<=G.VerNum;i++)  //�Զ���Ԫ�������������
					cout<<G.Data[topoList[i]]<<"\t";
				cout<<endl<<endl;
			}
			else
			{
				cout<<endl<<"��ͼ���л�·����������ʧ�ܡ�"<<endl<<endl;
			}			  

			break;	

		default:
			cout<<"���󣺲���ѡ�����������ѡ��"<<endl;;
			break;
		}

	}while(nChoice!=0);

	return 0;
}
