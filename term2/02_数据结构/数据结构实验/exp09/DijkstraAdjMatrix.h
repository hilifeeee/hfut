

//Dijkstra�㷨--�����ڽӾ���
//**************  Dijkstra�㷨--�����ڽӾ��� ****************//
//* �������ܣ��������㣬���˵�������������������·��    *//
//* ��ڲ�����Graph G�������ʵ�����ͼ��                     *//
//*           int vID��ָ������ı��                       *//
//* ���ڲ�����int path[]���������·����Ϣ                  *//
//*           int dist[]��������̾���ֵ                    *//
//* �� �� ֵ����                                            *//
//***********************************************************//
void Dijkstra(Graph &G, int path[], int dist[], int vID)
{
	int solved[MaxVerNum];  //��Ƕ����Ƿ��Ѿ�������·����1--����⣬0--δ���
	int i,j;
	int v;
	cellType minDist;  //��̾��룬cellTypeΪ�Զ�����ڽӾ�����Ԫ�ص���������
	//��ʼ������S�;�������
	for(i=1;i<=G.VerNum;i++)
	{
		solved[i]=0;  //���ж��������
		dist[i]=G.AdjMatrix[vID][i];
		if(dist[i]!=INF)
			path[i]=vID;  //��i�����ǰ��ΪvID
		else
			path[i]=-1;   //��ǰ����i��ǰ��
	}
	solved[vID]=1; //��Ƕ���vID�����
	dist[vID]=0;   //vID������ľ���Ϊ0
	path[vID]=-1;  //vIDΪ��ʼ���㣬��ǰ��

	//�����ҳ�����n-1�������������⼯��S
	for(i=1; i<G.VerNum; i++)
	{
		minDist=INF;
		for(j=1;j<=G.VerNum;j++)  //��δ�ⶥ����Ѱ�Ҿ�vID��������Ķ��㣬��ű��浽v��
		{
			if(solved[j]==0 && dist[j]<minDist)  //jĿǰ����V-S�У�Ϊδ�ⶥ��
			{
				v=j;
				minDist=dist[j];
			}
		}
		
		if(minDist==INF)
			return;
		cout<<"ѡ�񶥵㣺"<<G.Data[v]<<"--���룺"<<minDist<<endl;   //�������ѡ��Ķ������

		solved[v]=1;  //����v���ҵ���̾��룬�����ѽ⼯��S��

		//��ѡ�еĶ���v���޸�δ�ⶥ�㼯V-S�У�v���ڽӶ��㣨ֱ�Ӻ�̣�������vID�ľ���
		for(j=1; j<=G.VerNum; j++)
		{
			if(solved[j]==0 && (minDist+G.AdjMatrix[v][j])<dist[j])
			{
				dist[j]=minDist+G.AdjMatrix[v][j];   //���¶���j������vID����̾��롣
				path[j]=v;   //���¶���j��ֱ��ǰ��Ϊ����v
			}		
		}
	}

/*	cout<<"*******************"<<endl;
	for(i=1; i<=G.VerNum;i++)
	{
		cout<<i<<"--"<<path[i]<<endl;
	}

	cout<<"*******************"<<endl;
*/
}

void PrintDijkstra(Graph &G, int path[], int dist[], int vID )
{
	int sPath[MaxVerNum];  //����һ������ջ����������
	int vPre;  //ǰ�������
	int top=-1;  //ջ��
	int i;

	int j;

	for(i=1; i<=G.VerNum; i++)
	{
		cout<<G.Data[vID]<<" to "<<G.Data[i];
		if(dist[i]==INF)
			cout<<" �޿ɴ�·����"<<endl;
		else
		{
			cout<<" ��̾��룺"<<dist[i]<<endl;
			cout<<"           ·����";
		}
		//printf("\nDistanced: %7d, path:", dist[i]);
		
		top++;
		sPath[top]=i;   //sPath[0]Ϊ��ǰ����i
		vPre=path[i];  //i�����ǰ������
		while(vPre!=-1)  //�ӵ�i�����㣬ͨ��ǰ��������ǰ����������㣬�������·��
		{
			top++;
			sPath[top]=vPre;
			vPre=path[vPre];
		}

/*		while(top>0)
		{
			top--;
			cout<<G.Data[sPath[top]]<<"  ";
			//printf("%2d", sPath[top]);			
		}
*/
		
		if(dist[i]!=INF)
		{
			for(j=top;j>=0;j--)  //sPath[top]Ϊָ������ʼ����
			{
				cout<<G.Data[sPath[j]]<<"  ";
			}
		}

		top=-1;
		cout<<endl;
	}
}