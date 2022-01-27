
//���������㷨--�����ڽӾ���

//��ʼ����ȡÿ���������ȣ������������inds[]��
void GetInDegrees(Graph &G, int inds[])
{
	int i,j;
	for(j=1;j<=G.VerNum;j++)  //�ڽӾ�����ѭ��
	{
		for(i=1;i<=G.VerNum;i++)  //�ڽӾ�����ѭ��
		{
			if(G.AdjMatrix[i][j]>=1 && G.AdjMatrix[i][j]<INF)
				inds[j]++;  //���j����ȼ�1.
		}
	}

	//for(i=1;i<=G.VerNum;i++)  //���ÿ������ĳ�ʼ���
	//{
	//	cout<<i<<"--"<<inds[i]<<endl;
	//}
}
//���������㷨--ʹ��ջ
int TopologicalSortS(Graph &G, int topoList[])
{
	int inds[MaxVerNum];  //���嶥���������
	seqStack S;  //����һ��˳��ջ���������Ϊ0�Ķ���
	int i;
	int v;  //������
	int vCount=0; //��¼�������Ϊ0�Ķ�����
	
	initialStack(S);  //��ʼ��ջ

	for(i=1;i<=G.VerNum;i++)
		inds[i]=0;  //��������ʼ��

	//�������������ʼ��
	for(i=1;i<G.VerNum;i++)		
		topoList[i]=-1;  //��ʼ��������Ϊ-1

	//���ڽӾ����ȡͼ�и�������ĳ�ʼ���
	GetInDegrees(G, inds);

	//���Ϊ0�Ķ�����ջ
	for(i=1;i<=G.VerNum;i++)
	{
		if(inds[i]==0)
			push(S,i);
	}

	while(!stackEmpty(S))
	{
		pop(S,v);  //��ջ������һ�����Ϊ0�Ķ����ŵ�v
		topoList[vCount+1]=v;  //��ǰ���Ϊ0����v��������������
		vCount++;  //�Ѵ����㣨���Ϊ0������1		

		//��v�ڽӵĶ������ȼ�1
		for(i=1;i<=G.VerNum;i++)
		{			
			if(G.AdjMatrix[v][i]>=1 && G.AdjMatrix[v][i]<INF && inds[i]>0)
			{
				inds[i]--;  //��v�ڽӵĶ���i����ȼ�1
				if(inds[i]==0) //����i������Ѿ�Ϊ0����ջ
					push(S,i);
			}
		}
	}

	if(vCount==G.VerNum)
		return 1;  //�����޻�·���
	else	
		return 0;  //�л�·�����ܲ�����������
}

//���������㷨--ʹ�ö���
int TopologicalSortQ(Graph &G, int topoList[])
{
	int inds[MaxVerNum];  //������������
	seqQueue Q;  //�������Ϊ0����Ķ���
	int i;
	int v;  //���浱ǰ����Ķ�����
	int vCount=0;  //�������Ϊ0�Ķ�����

	initialQueue(&Q);

	for(i=1;i<=G.VerNum;i++)
	{
		inds[i]=0;  //inds[]����Ԫ�س�ʼ��Ϊ0
		topoList[i]=-1;  //�������������ʼ��Ϊ-1
	}
	GetInDegrees(G,inds); //��ͼ���ڽӾ����ȡͼ�и�����ĳ�ʼ���

	for(i=1;i<=G.VerNum;i++)
	{
		if(inds[i]==0)  //���Ϊ0�Ķ�����i���
			enQueue(&Q,i);
	}

	while(!queueEmpty(Q))
	{
		getFront(Q,v);  //ȡ��ͷԪ�ص�v
		outQueue(&Q,v);  //��ͷԪ��v����
		topoList[vCount+1]=v;  //��ͷԪ�ؽ�����������
		vCount++;  //���Ϊ0��������1

		for(i=1;i<=G.VerNum;i++)  //v���ڽӶ�����ȼ�1
		{
			if(G.AdjMatrix[v][i]>=1 && G.AdjMatrix[v][i]<INF && inds[i]>0)
			{
				inds[i]--;  //v���ڽӶ���i����ȼ�1
				if(inds[i]==0)  //����i������Ѿ�Ϊ0�����
					enQueue(&Q,i);
			}
		}
	}

	if(vCount==G.VerNum)
		return 1;  //�޻�·����������ɹ�
	else
		return 0;  //�л�·����������ʧ��
}

//���������㷨--��ʹ��ջ�Ͷ��У�ʹ��һ���������solved[]
int TopologicalSort(Graph &G, int topoList[])
{
	int inds[MaxVerNum];  //����ͼ�и���������
	int solved[MaxVerNum];  //���ͼ�����Ϊ0�Ķ����Ƿ��Ѿ��������0--δ����1--�Ѵ���
	int i;
	int v=-1;  //��ǰ��������Ϊ0�Ķ�����
	int vCount=0;  //��¼���Ϊ0�Ķ��������

	//��ʼ��
	for(i=1;i<=G.VerNum;i++)
	{
		inds[i]=0;       //���ж��������Ϊ0
		solved[i]=0;     //���ж�����Ϊδ����
		topoList[i]=-1;  //��������Ԫ��ȫ����ʼ��Ϊ-1
	}

	//���ڽӾ����ȡͼ�и�������ĳ�ʼ��ȣ���inds[]���鷵��
	GetInDegrees(G,inds);
    
	//ȡ�õ�һ�����Ϊ0�Ķ����ţ�������ڣ������浽v
	for(i=1;i<=G.VerNum;i++)
	{
		if(inds[i]==0 && !solved[i])
		{
			v=i;
			break;
		}
	}

	while(v!=-1)
	{
		topoList[vCount+1]=v;  //����v������������
		vCount++;  //���Ϊ0��������1
		solved[v]=1;  //��Ƕ���v�Ѿ�����

		//�붥��v���ڵĶ�����ȼ�1
		for(i=1;i<=G.VerNum;i++)
		{
			if(G.AdjMatrix[v][i]>=1 && G.AdjMatrix[v][i]<INF && inds[i]>0)
				inds[i]--;  //����i��ȼ�1
		}

		//��ȡ��һ�����Ϊ0������δ����Ķ���
		v=-1;
		for(i=1;i<=G.VerNum;i++)
		{
			if(inds[i]==0 && !solved[i])
			{
				v=i;
				break;  //�ҵ����������Ķ��㣬�˳�ѭ��--���Ϊ0����δ����
			}
		}
	}

	if(vCount==G.VerNum)
		return 1;  //�޻�·����������ɹ�
	else
		return 0;  //�л�·����������ʧ��
}
