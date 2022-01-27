
//Floyd�㷨

//typedef cellType dist[MaxVerNum][MaxVerNum];
//typedef int path[MaxVerNum][MaxVerNum];

void Floyd(Graph &G, cellType dist[MaxVerNum][MaxVerNum], int path[MaxVerNum][MaxVerNum])
{
	int i,j,k;
	//��ʼ����������·������
	for(i=1;i<=G.VerNum;i++)
	{
		for(j=1;j<=G.VerNum;j++)
		{
			dist[i][j]=G.AdjMatrix[i][j];   //��������ʼ��Ϊ�ڽӾ���
			                                        //��ʼ��·������·������Ԫ��path[i][j]�б�����j�����ǰ���Ķ�����
            if( i!=j && G.AdjMatrix[i][j]<INF)  //���i,j֮����ڱߣ���j��ǰ��Ϊi������ǰ����Ϊ-1
				path[i][j]=i;
			else
				path[i][j]=-1;													
		}
	}

	//��k=1��ʼ��������k=G.verNum������ѡ��һ������k����Ϊ����i��j֮�����ת���㣬�Ż�����i��j֮��ľ���
	//������Floyd�㷨�ĺ���--����forѭ��
	for(k=1; k<=G.VerNum; k++)
	{
		for(i=1; i<=G.VerNum; i++)
		{
			for(j=1; j<=G.VerNum;j++)
			{
				if(i!=j && dist[i][k]+dist[k][j]<dist[i][j])  //k��Ϊ��ת���㣬i��j֮������С������k��Ϊ��ת�㣬����i��j֮��ľ���
				{
					dist[i][j]=dist[i][k]+dist[k][j];  //���¾���
					path[i][j]=path[k][j];  //�޸�ǰ������					
				}
			}	
		}

		    //��ӡk������Ϊ��ת������Ż��ľ������
		cout<<"��"<<k<<"���Ż���ľ������"<<endl;
		for(i=1;i<=G.VerNum;i++)
		{   
			cout<<"\t";
			for(j=1;j<=G.VerNum;j++)
			{
				if((G.gKind==UDN || G.gKind==DN) && dist[i][j]==INF)
					cout<<"INF"<<"\t";  //���������ʱ����ӡ��INF����ʾ
				else
					cout<<dist[i][j]<<"\t";
			}
			cout<<endl;
		}
		    //��ӡk������Ϊ��ת������Ż���·������
		cout<<"��"<<k<<"���Ż����·������"<<endl;
		for(i=1;i<=G.VerNum;i++)
		{   
			cout<<"\t";
			for(j=1;j<=G.VerNum;j++)
			{
				cout<<path[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
}

//��ӡFloyd�㷨���������·��
void PrintFloyd(Graph &G, cellType dist[MaxVerNum][MaxVerNum], int path[MaxVerNum][MaxVerNum])
{
	int sPath[MaxVerNum];  //����һ������ջ����������
	int pra;  //ǰ�������
	int top=-1;  //ջ��
	int i;

	int j;
	int m;

	for(i=1; i<=G.VerNum; i++)
	{		
		for(j=1; j<=G.VerNum; j++)
		{
			cout<<G.Data[i]<<" to "<<G.Data[j];
			if(dist[i][j]==INF)
				cout<<" �޿ɴ�·����"<<endl;
			else
			{
				cout<<" ��̾��룺"<<dist[i][j]<<endl;
				cout<<"           ·����";

				top++;
				sPath[top]=j;   //sPath[0]Ϊ��ǰ����i
				pra=path[i][j];  //i�����ǰ������
				while(pra!=i)
				{
					top++;
					sPath[top]=pra;
					pra=path[i][pra];
				}
				top++;
				sPath[top]=i;  //�ӽ���ʼ����i
				
				if(dist[i][j]!=INF)
				{
					for(m=top;m>=0;m--)  //sPath[top]Ϊָ������ʼ����
					{
						cout<<G.Data[sPath[m]]<<"  ";
					}
				}
				
				top=-1;
				cout<<endl;				
			}	
		}
	}
}