
//Kruskal�㷨--�����ڽӾ���
//��������0��Ԫδ�ã�ʹ������������С����ͬ





//����ߵĽṹ����
typedef struct edgeType
{
	int vBegin;  //�ߵ���ʼ�����ţ���1��ʼ
	int vEnd;    //�ߵ���ֹ�����ţ���1��ʼ
	cellType eWeight;  //�ߵ�Ȩֵ
}EdgeType;

//��ͼ���ڽӾ����ȡ���бߵ���Ϣ���洢��һ��������
void GetEdges(Graph &G, EdgeType edges[])
{
	int i,j;
	int k=0;  //��Ϊ�ߵı��
	for(i=1;i<=G.VerNum;i++)  //��ѭ��
	{
		for(j=1;j<=G.VerNum;j++)  //��ѭ��
		{
			if((G.AdjMatrix[i][j]>=1) &&   //�����±��붥������ͬ
		       (G.AdjMatrix[i][j]<INF)) 
			{
				edges[k].vBegin=i;  //�ߵĵ�һ����
				edges[k].vEnd=j;    //�ߵĵڶ����� 
				edges[k].eWeight=G.AdjMatrix[i][j];  //�ߵ�Ȩֵ
				k++;
			}		   
		}
	}
}

//��ȡ��ǰ������С��
EdgeType GetMinEdge(Graph &G, EdgeType edges[], int edgeUsed[], int &n)  //nΪ���ص���С����edges[]�����е��±�
{
	EdgeType minEdge;
	cellType wMin=INF;  //������СȨֵ
	int i;
	int M;  //����ѭ������
	if(G.gKind==UDG || G.gKind==UDN)
		M=G.ArcNum*2;  //������������ͼ��ӦΪ�Գ��ԣ��ڽӾ�����Ч�����Ǳ�����2��
	else
		M=G.ArcNum;    //����ͼ���������У�M��Ϊͼ�ı���

	for(i=0; i<M ;i++) //��Ϊ����ͼ�ڽӾ���Գ��У���Ч�����Ǳ�����2�������Գ�2
	{
		if(edgeUsed[i]==0 && edges[i].eWeight<wMin)
		{
			wMin=edges[i].eWeight;
			minEdge.eWeight=edges[i].eWeight;;
			minEdge.vBegin=edges[i].vBegin;
			minEdge.vEnd=edges[i].vEnd;
			n=i;
		}
	}

	return minEdge;  //����ȡ�õ���С��
}

//Kruskal�㷨
void Kruskal(Graph &G)
{
	int conVerID[MaxVerNum];  //�������ͨ�����������
	EdgeType edges[MaxVerNum*MaxVerNum];  //���ͼ�����б���Ϣ
	EdgeType treeEdges[MaxVerNum];        //����������еı���Ϣ��n-1��

	int edgeUsed[MaxVerNum*MaxVerNum];  //�������飬���ͼ�еı��Ƿ��Ѿ����Թ���1--���ù���0--δ�ù�
	                                    //Ҳ�����������㷨�ȶ�ͼ�����б߽�������������������

	EdgeType minEdge;  //������С��
	int i,j;
	int k=0;
	int conID;  //�ߵ���ֹ�������ͨ�����ı��
    
	int n;  //���ص���С�ߵ����

	//��ȡͼ���бߵ���Ϣ����������edges[]
	GetEdges( G, edges );

	//��ʼ�����ñ�����--���������㷨ȡ��
	int M;  //ѭ������
	if(G.gKind==UDG ||G.gKind==UDN)
		M=G.ArcNum*2; //��Ϊ����ͼ���������ڽӾ���Գƣ���Ч�����Ǳ�����2�������Գ�2
	else
		M=G.ArcNum;

	for(i=0; i<M; i++)  
		edgeUsed[i]=0;

	//��ʼ����ͨ������š���ʼÿ��������Ϊһ����ͨ������ÿ��һ����ţ���1��ʼ���붥������ͬ
	for(i=1;i<=G.VerNum;i++)
	{
		conVerID[i]=i;  //�������������±��1
	}

	for(i=1; i<G.VerNum; i++)  //ȡ��n-1���ߣ�����������
	{
		minEdge=GetMinEdge(G, edges, edgeUsed, n );
		while(conVerID[minEdge.vBegin]==conVerID[minEdge.vEnd])
		{
			edgeUsed[n]=1;  //2����������ͬһ����ͨ�������ع��ɻ�·������С�߲�����
			minEdge=GetMinEdge( G, edges, edgeUsed, n ); //����ȡ��һ����С�ߣ�ֱ��ȡ�ÿ��ñ�Ϊֹ
		}
		    //����ȡ����1��������С�ߣ�������������
		treeEdges[i]=minEdge;
		conID=conVerID[minEdge.vEnd]; //ȡ����С�ߵ��յ���
		//conID=conVerID[minEdge.vBegin]; //ȡ����С�ߵ������

		for(j=1;j<=G.VerNum;j++)  //�ϲ���ͨ��ŵ���С���
		{
			if(conVerID[j]==conID)  //������ͨ�������ΪconID�Ķ��㣬��ͨ������Ŷ���Ϊ��С����ʼ�������ͨ��
			{
				conVerID[j]=conVerID[minEdge.vBegin];
			}
		}


		edgeUsed[n]=1; 

	}

	//������	
	cellType wAll=0;  //��Ȩֵ
	cout<<endl;  //������
	cout<<"Kruskal��С������-->>"<<endl;
	cout<<"ѡ��ıߺ�Ȩֵ��"<<endl;
	for(i=1;i<G.VerNum;i++)  //n-1����
	{	
		cout<<"("<<G.Data[treeEdges[i].vBegin]<<","<<G.Data[treeEdges[i].vEnd]<<")";
		cout<<" �� ("<<treeEdges[i].vBegin<<","<<treeEdges[i].vEnd<<")��Ȩֵ��"<<treeEdges[i].eWeight<<endl;
		wAll+=treeEdges[i].eWeight;
	}
	cout<<"��������Ȩֵ��"<<wAll<<endl;
	cout<<endl;
	
}

//----���鼯������--------------------------------------

//1.��ʼ�����鼯
//--int anc[]�洢ÿ�����ϵĴ���ֵ���˴�anc[0]��Ԫδ�ã�nΪԪ�ظ���
//--anc[]����Ϊȫ�����飬�ڵݹ��и���Լ�ռ�
void unionIni(int anc[], int n)
{
	for(int i=1;i<=n; i++)
		anc[i]=i;
}

//2.���Һ���
int find(int anc[], int x) 
{
	if(x!=anc[x])
		anc[x]=find(anc,anc[x]);
	return anc[x];
}

//3.�ϲ�����
void unionSet(int anc[], int x, int y)
{
	int fx,fy;
	fx=find(anc,x);
	fy=find(anc,y);
	if(fx!=fy)
		anc[x]=fy;
}

//----���鼯�������---------------------------------------

//--ʹ�ò��鼯��Kruskal�㷨
void disjointKruskal(Graph &G)
{
	
	EdgeType edges[MaxVerNum*MaxVerNum];  //���ͼ�����б���Ϣ
	EdgeType treeEdges[MaxVerNum];        //����������еı���Ϣ��n-1��

	int edgeUsed[MaxVerNum*MaxVerNum];  //�������飬���ͼ�еı��Ƿ��Ѿ����Թ���1--���ù���0--δ�ù�
	                                    //Ҳ�����������㷨�ȶ�ͼ�����б߽�������������������

	int anc[MaxVerNum];  //---ֻ�ڲ��鼯����ʱʹ��
	unionIni(anc,MaxVerNum);

	EdgeType minEdge;  //������С��
	int i,j;
	
    
	int n;  //���ص���С�ߵ����

	//��ȡͼ���бߵ���Ϣ����������edges[]
	GetEdges( G, edges );

	//��ʼ�����ñ�����--���������㷨ȡ��
	int M;  //ѭ������
	if(G.gKind==UDG ||G.gKind==UDN)
		M=G.ArcNum*2; //��Ϊ����ͼ���������ڽӾ���Գƣ���Ч�����Ǳ�����2�������Գ�2
	else
		M=G.ArcNum;

	for(i=0; i<M; i++)  
		edgeUsed[i]=0;


	for(i=1; i<G.VerNum; i++)  //ȡ��n-1���ߣ�����������
	{
		minEdge=GetMinEdge(G, edges, edgeUsed, n );
		if(find(anc,minEdge.vBegin)==find(anc,minEdge.vEnd))  //���鼯��ѯ��ǰ�ߵ�2�������Ƿ���ͬһ����ͨ������
		{
			edgeUsed[n]=1;  //2����������ͬһ����ͨ�������ع��ɻ�·������С�߲�����
			minEdge=GetMinEdge( G, edges, edgeUsed, n ); //����ȡ��һ����С�ߣ�ֱ��ȡ�ÿ��ñ�Ϊֹ
		}
		    //����ȡ����1��������С�ߣ�������������
		treeEdges[i]=minEdge;

		//���鼯�ĺϲ������ߵ�2������ϲ���һ�����ϣ�ͬһ����ͨ������
		unionSet(anc,minEdge.vBegin,minEdge.vEnd);

		edgeUsed[n]=1; 

	}

	//������	
	cellType wAll=0;  //��Ȩֵ
	cout<<endl;  //������
	cout<<"Kruskal�����鼯����С������-->>"<<endl;
	cout<<"ѡ��ıߺ�Ȩֵ��"<<endl;
	for(i=1;i<G.VerNum;i++)  //n-1����
	{	
		cout<<"("<<G.Data[treeEdges[i].vBegin]<<","<<G.Data[treeEdges[i].vEnd]<<")";
		cout<<" �� ("<<treeEdges[i].vBegin<<","<<treeEdges[i].vEnd<<")��Ȩֵ��"<<treeEdges[i].eWeight<<endl;
		wAll+=treeEdges[i].eWeight;
	}
	cout<<"��������Ȩֵ��"<<wAll<<endl;

	cout<<endl;	
}