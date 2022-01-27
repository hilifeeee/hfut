
//Prim�㷨�����ڽӾ����ʵ��




int inTree[MaxVerNum+1]={0}; //��Ƕ����Ѿ���Prim�������У����Ѿ����ʹ���1��true--�ѷ��ʣ�0��false--δ����
                             //inTree[0]��Ԫδ��
                             //����Ϊ����Ѿ��ڼ���U�еĶ���
//�����ѡ�ߵ���Ϣ
typedef struct minEdgeType
{
	int v;              //V-U�е�ǰѡ�еĶ����ţ���1��ʼ�����մ�V-U��ѡ���ŵ�U�еĶ���
	cellType eWeight;  //U��ĳ�����㵽V-U�е�ǰ����v����С����
} MinEdgeType;

//�����Ѿ�ѡ��ıߵ���Ϣ
typedef struct selectedEdge
{
	int vBegin;  //ѡ�бߵ���ʼ�����ţ���1��ʼ
	int vEnd;    //ѡ�бߵĽ��������ţ���1��ʼ
	cellType eWeight;
} SelectedEdgeType;

//���ͼG�б��ΪvBegin��vEnd֮���Ƿ��б�
int HasEdge(Graph &G, int vBegin, int vEnd)
{
	if(G.gKind==UDN || G.gKind==DN)  //�����
	{
		if(G.AdjMatrix[vBegin][vEnd]!=INF)  //Ȩֵ��������б�
			return 1;  //�бߣ�����1
		else
			return 0;  //�ޱߣ�����0
	}
	else  //ͼ���
	{
		if(G.AdjMatrix[vBegin][vEnd]==1)  //�������������±��1
			return 1;  //�бߣ�����1
		else
			return 0;  //�ޱߣ�����0
	}
}


//��ʼ����ѡ�����飬���Ѿ�ѡ�������
void InitMinEdges(Graph &G, MinEdgeType minEdges[],int vID)
{
	int i;
	for(i=1;i<=G.VerNum;i++)
	{
		//��ʼ����ѡ������
		if(HasEdge(G, vID, i))
		{
			minEdges[i].v=vID;
			minEdges[i].eWeight=G.AdjMatrix[vID][i];  //Ȩֵ��ʼ��Ϊ�����
		}
		else
			minEdges[i].eWeight=INF;
	}
}

//�Ӻ�ѡ�߼�����ѡ����С�ߣ�������V-U�еĹ���������
int GetMinEdge(Graph &G, MinEdgeType minEdges[])
{
	cellType eMin=INF;  //������С��Ȩֵ
	int i,j;
	for(i=1;i<=G.VerNum;i++)
	{
		if(inTree[i]==0 && minEdges[i].eWeight<eMin)
		{
			j=i;  //�����ǰ���Ϊi�Ķ����ڼ���V-U�У���Ȩֵ��eMinС����ѡΪ��С��
			eMin=minEdges[i].eWeight;
		}
	}
	return j;  //j��ΪV-U�У���С�߹�������ı��
}


void ChangeMinEdgesWeight(Graph &G, MinEdgeType minEdges[], int vID)
{
	//����ѡ���ı��ΪvID�Ķ��㣨�¼��뼯��U�У���������ѡ�߼���
	int i,j; 
	for(i=1;i<=G.VerNum;i++)
	{
		if(inTree[i]==0)  //���i������V-U�У�����U��
		{
			//���vID��i֮���Ƿ����ڣ��бߣ�
			//���U�ж���vID��i֮��ı�Ȩֵ�Ƿ��С������С�����(vID,i)Ȩֵ
			if(HasEdge(G,vID,i) && G.AdjMatrix[vID][i]<minEdges[i].eWeight)
			{
				minEdges[i].v=vID;
				minEdges[i].eWeight=G.AdjMatrix[vID][i];
			}
		}
	}
}

void Prim(Graph &G, int vID)
{
	
	MinEdgeType minEdges[MaxVerNum];  //minEdges[i]���±��1����i+1Ϊѡ���ߵ���ʼ��
	                                  //minEdges[i].vΪѡ���ߵ��յ�  

	int i;
	int	curID;  //��ǰѡ�񶥵���
	cellType wAll=0;  //Ȩֵ�ܺ�

	InitMinEdges(G, minEdges, vID);  //��ʼ����ѡ������

	inTree[vID]=true;  //���vID�����������ϣ�������U��

	for(i=1;i<G.VerNum;i++)  //ѡ��n-1���ߣ��γ�������
	{
		curID=GetMinEdge(G, minEdges);  //ѡ��V-U����С�߹����Ķ���		
		inTree[curID]=true;  //���curID��ѡ��U��
		ChangeMinEdgesWeight(G, minEdges, curID);  //�޸�Ȩֵ

		
	}
	
	cout<<endl;  //������
	cout<<"Prim��������ʼ���㣺"<<G.Data[vID]<<"����ţ�"<<vID<<endl;
	cout<<"ѡ��ıߺ�Ȩֵ��"<<endl;
	for(i=1;i<=G.VerNum;i++)
	{
		//cout<<i<<"--"<<minEdges[i].v<<",  "<<minEdges[i].eWeight<<endl;
		if(i!=vID)
		{
			cout<<"("<<G.Data[minEdges[i].v]<<","<<G.Data[i]<<")";
			cout<<" �� ("<<minEdges[i].v<<","<<i<<")��Ȩֵ��"<<minEdges[i].eWeight<<endl;
			//cout<<i<<"--"<<minEdges[i].v<<",  "<<minEdges[i].eWeight<<endl;
			//cout<<minEdges[i].eWeight<<"\t";
			wAll+=minEdges[i].eWeight;
		}
	}
	cout<<"��������Ȩֵ��"<<wAll<<endl;
	cout<<endl;

}

void PrimPrint(Graph &G, MinEdgeType minEdges[], int vID)
{
	int i;
	cellType wAll=0;
	cout<<"Prim��������ʼ���㣺"<<vID<<endl;
	cout<<"ѡ��ıߺ�Ȩֵ��"<<endl;
	for(i=1;i<=G.VerNum;i++)
	{
		if(i!=vID)
		{
			cout<<i<<"--"<<minEdges[i].v<<",  "<<minEdges[i].eWeight<<endl;
			wAll+=minEdges[i].eWeight;
		}
	}
	cout<<"��������Ȩֵ��"<<wAll<<endl;
	cout<<endl;

}