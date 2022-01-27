//����ͷ�ļ�
#include<iostream>
#include<string.h> 
#include<string>
#include<map>
#include<list>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
#include <fstream>

//ʹ�������ռ�std
using namespace std;

//�궨��
#define Feature 100                         //��������feature��+1������ 
#define Sample  7000                        //���������� ���� 
#define FeatureChoice 50                    //���� ȡֵ���� ������ 

//�ṹ�嶨��
struct Node                 //�������ڵ� 
{
    string attribute;       //������
    string val;             //����ֵ
    bool isLeaf;            //�Ƿ�ΪҶ�ӽڵ㣨Ҷ�ӽڵ��ж���ֹ��
    vector<Node*> childs;   //���ӽڵ�
    //���캯�����趨��ʼֵ
	Node()
	{
		val = "";           //��ʼ����ֵ
		attribute = "";     //��ʼ������
		isLeaf = false;     //Ĭ�ϲ���Ҷ�ӽڵ�
	}
};

//ȫ�ֱ��� 
vector< vector<string> > trainData;         //����ѵ�����ݼ�
vector< vector<string> > testData;          //����ʵ�����ݼ�
vector< vector<string> > update;            //��������������ݼ�--���ڴ���������
vector<string> attributes;                  //��������
Node *root = NULL;                          //�����������ĸ��ڵ�

//ȫ�ֺ���
void DTA_createTrainDataset();                                                                      //���ı��ļ�"train.data"��ȡ�ı���Ϣ��Ȼ�󴴽�ѵ�������ݼ�
void DTA_createTestDataset();                                                                       //���ı��ļ�"test.data"��ȡ�ı���Ϣ��Ȼ�󴴽�ѵ�������ݼ�
double DTA_calcEntropy(vector< vector<string> > &data);                                             //����������ݼ�����Ϣ��
vector< vector<string> > DTA_splitDataSet(vector< vector<string> > data, int axis, string value);   //���ո��������������ݼ����µ����ݼ���ά������һ��/axis �������±�/value������ֵ
vector<string> DTA_createFeatureList(vector< vector<string> > &data, int axis);                     //���������б�
int DTA_chooseBestFeatureToSplit(vector< vector<string> > &data);                                   //ѡ����õ����ݼ����ַ�ʽ
string DTA_majorityCnt(vector<string> &classList);                                                  //���س��ִ������ķ�������/������ǩ����Ψһ�����ö�������ķ�������Ҷ�ӽڵ�ķ���
Node* DTA_createTree(Node *root, vector< vector<string> > &data, vector<string> &attribute);        //�ݹ鹹��������
void DTA_printTree(Node *root, int depth);                                                          //��ӡ����������Tree.txt���� 
void DTA_freeNode(Node *root);                                                                      //�ͷŽڵ�
string DTA_classify(Node *root, vector<string> &attribute, vector<string> &test);                   //Ԥ��һ�����ݵĽ�� 
void DTA_printResult(vector< vector<string> > &data,Node* root);									//��ӡ�������result.txt"��												//�������ӡ����result.txt���� 
//����ʵ��

//���ı��ļ�"train.data"��ȡ�ı���Ϣ��Ȼ�󴴽�ѵ�������ݼ�
void DTA_createTrainDataset()
{
    int i,j;           //����ѭ������
	int num;
    char p,*p2;
    string line;
    string word;
	vector<string> temp_line;
    ifstream fin("train.data");
    
    //���Ȼ�ȡ��һ����Ϊ����
    getline(fin,line);
    //�ָ�ɵ���
    for (string::size_type i = 0;i < line.size(); i++)
    {
        if(line[i]=='\t')
		{
			if(!word.empty())
			{
				temp_line.push_back(word);
				word = "";
			}
		}
		else
			word += line[i];
    }
	temp_line.push_back(word);
    word = "";
	for(i = 0; i <temp_line.size(); ++i)
	{
		attributes.push_back(temp_line[i]);
	} 
	temp_line.clear();

	while (fin.get(p))
	{
        getline(fin,line);
//        string::size_type 
        for (i = 0;i < line.size(); i++)
        {
            if(line[i]=='\t')
			{
				if(!word.empty())
				{
					temp_line.push_back(word);
					word = "";
				}
			}
			else
				word += line[i];
        }

        temp_line.push_back(word);
        word = "";
        trainData.push_back(temp_line); 
		temp_line.clear();
    }
	fin.close();               //������Ҫ�����һ�е����������뵽��ά��̬������

    for(i = 0; i <attributes.size(); ++i)
	{
		cout << attributes[i] << "\t";
	}
    cout << endl;

    for (i = 0;i < trainData.size(); ++i)
    {
        for (j = 0;j < trainData[0].size(); ++j)
        {
            cout << trainData[i][j] << "\t";
        }
        cout << endl;
    }
}

//���ı��ļ�"test.data"��ȡ�ı���Ϣ��Ȼ�󴴽�ѵ�������ݼ�
void DTA_createTestDataset()
{
    int i,j;           //����ѭ������
	int num;
    char p;
    string line;
    string word;
	vector<string> temp_line;
    ifstream fin("test.data");
	
	getline(fin,line); 
    while (fin.get(p))
	{
        getline(fin,line);
        for (string::size_type i = 0;i < line.size(); ++i)
        {
            if(line[i]==' ' || line[i]=='\t')
			{
				if(!word.empty())
				{
					temp_line.push_back(word);
					word = "";
				}
			}
			else
				word += line[i];
        }
        temp_line.push_back(word);
        word = "";
        testData.push_back(temp_line); 
		temp_line.clear();
    }
	fin.close();               //������Ҫ�����һ�е����������뵽��ά��̬������
	
    for (i = 0;i < testData.size(); ++i)
    {
        for (j = 0;j < testData[0].size(); ++j)
        {
            cout << testData[i][j] << "\t";
        }
        cout << endl;
    }
}

//����������ݼ�����Ϣ��
double DTA_calcEntropy (vector< vector<string> > &data)
{
	 int n = data.size();                   //����ѭ����Χ
	 int i;									//ѭ������ 
	 map<string, int> classCounts;          //���ü�ֵ�� key -- value ʹ��map
	 int label = data[0].size() - 1;        //ȥ��ÿһ�����һ��������
	 for(i = 0; i < n; i++)             //��ʼΪ0
	 {
		classCounts[ data[i][label] ] = 0;
	 }
	 for(i = 0; i < data.size(); i++)  //ÿ������һ�Σ�+1
	 {
		classCounts[ data[i][label] ] += 1;
	 }

     /*������Ϣ��
    ��Ϣ�ؼ��㷽���� Entropy(D) = -sum( p_i * log_2(p_i) )   
                    DΪ��������
                    1<= i <= ����D���������������
                    p_i Ϊ��i�������D����ռ�ı���
     */
	 double entropy = 0;                     //��Ϣ��
	 map<string, int>::iterator it;         //����������map
	 for(it = classCounts.begin(); it != classCounts.end(); it++)
	 {
		 double prob = (double)(it->second) / (double)n;
		 entropy -= prob * ( log(prob) / log(2) );
	 }
	//	cout << "shanno is " << entropy << endl;
	//  cout << "TA_calcEntropyt is completed" << endl;
	 return entropy;
}

//���ո��������������ݼ����µ����ݼ���ά������һ�� /axis �������±� /value������ֵ
vector< vector<string> > DTA_splitDataSet(vector< vector<string> > data, int axis, string value)
{
	vector< vector<string> > result;        //�½�vector����result
	for(int i = 0; i < data.size(); i++)
	{
		if(data[i][axis] == value)
		{
			//������ǰ���������ά��ȥ��
			vector<string> removed(data[i].begin(), data[i].begin()+axis);
			//�÷�����ָ��λ��itǰ�����롱����[start, end)������Ԫ��.
            removed.insert(removed.end(), data[i].begin()+axis+1, data[i].end());
			result.push_back(removed);
		}
	}
	// cout << "DTA_splitDataSet is completed" << endl; 
	return result;
}
//���������б�
vector<string> DTA_createFeatureList(vector< vector<string> > &data, int axis)
{
	int n = data.size();
	vector<string> featureList;     //����������ȡֵ
	set<string> s;                  //ͨ��set����ȥ�ز���
	for(int j = 0; j < n; j++)      //Ѱ�Ҹ����������п���ȡֵ
		s.insert(data[j][axis]);
	set<string>::iterator it;       //֮��������set����ѹ��featureList
	for(it = s.begin(); it != s.end(); it++)
	{
		featureList.push_back(*it);
	}
	// cout << "DTA_createFeatureList is completed" << endl;
	return featureList;
}

//ѡ����õ����ݼ����ַ�ʽ
int DTA_chooseBestFeatureToSplit(vector< vector<string> > &data)
{
	int n = data[0].size() - 1;                  //����ѭ������
	double bestEntropy = DTA_calcEntropy(data);      //��ʼ��Ϣ��
	double bestInfoGain = 0;                     //������Ϣ����
	int bestFeature = 0;                         //��õ�����
	for(int i = 0; i < n; i++)                   //��������
	{
		double newEntropy = 0;                   //�µ�������Ϣ��
		vector<string> featureList = DTA_createFeatureList(data, i);  //�����������п���ȡֵ
		for(int j = 0; j < featureList.size(); j++)
		{
            //ȥ��������
			vector< vector<string> > subData = DTA_splitDataSet(data, i, featureList[j]);
			double prob = (double)subData.size() / (double)data.size();
			newEntropy += prob * DTA_calcEntropy(subData);   
		}
		double infoGain = bestEntropy - newEntropy;  //��Ϣ���棬���صļ��٣�����������ȵļ���
        //ѡ�����ŵ���Ϣ����
		if(infoGain > bestInfoGain)
		{
			bestInfoGain = infoGain;
			bestFeature = i;
		}
	}
	// cout << "DTA_chooseBestFeatureToSplit is completed" << endl;
	// cout << "the bestFeature is " << bestFeature << endl;
	return bestFeature;

}

//���س��ִ������ķ�������
//������ǩ��Ȼ����Ψһ�ģ����ö�������ķ�������Ҷ�ӽڵ�ķ���
string DTA_majorityCnt(vector<string> &classList)
{
	int n = classList.size();       //����ѭ����Χ
	map<string, int> classCount;    //����classCount��key -- value��ֵ�ԣ�����ͶƱ����
	int i;                          //ѭ������i

    //��ʼ��
	for(i = 0; i < n; i++)
	{
		classCount[classList[i]] = 0;
	}
    //ͶƱ����
	for(i = 0; i < n; i++)
	{
		classCount[classList[i]] += 1;
	}

    //����ͶƱ�㷨��Majority Vote Algorithm��
    int DTA_majorityCnt = 0;            //���Ʊ��������
    map<string, int>::iterator it;  //���õ�����
    string result = "";             //��ʼ��result

    for(it = classCount.begin(); it != classCount.end(); it++)
    {
        if(it->second > DTA_majorityCnt)
        {
            //it->firstΪ��ֵ��
            //it->secondΪ��ֵ��
            DTA_majorityCnt = it->second;
            result = it->first;
        }
    }
	// cout << "DTA_majorityCnt is complete" << endl;
	// cout << "result is " << result << endl;
    return result;
}

//�ݹ鹹���������������㷨��
Node* DTA_createTree(Node *root, vector< vector<string> > &data, vector<string> &attribute)
{
	if(root == NULL)                    //�½��������root
		root = new Node();
	vector<string> classList;           //�����б�
	set<string> classList_removal;      //ȥ�������б�
	int i, j;                           //ѭ������
	int label = data[0].size() - 1;     //����ѭ����Χ
	int n = data.size();                //���ݼ��Ĵ�С
    //TODO: move the n to the beginning as a global value(is ok)
	for(i = 0; i < n; i++)
	{
		classList.push_back(data[i][label]);
		classList_removal.insert(data[i][label]);
	}
	if(classList_removal.size() == 1)   //�������ʵ��������ͬһ�ֹ࣬ͣ����
	{
		if(classList[0] == "yes")
			root->attribute = "yes";
		else
			root->attribute = "no";
		root->isLeaf = true;
		return root;
	}
	if(data[0].size() == 1)             //�������������������ö���������س��ִ����������
	{
		root->attribute = DTA_majorityCnt(classList);
		return root;
	}

	int bestFeatureIndex = DTA_chooseBestFeatureToSplit(data);                   //ѡ����õķ�ʽ���л���
	vector<string> featureList = DTA_createFeatureList(data, bestFeatureIndex);  //�õ������Ե����п���ֵ
	string bestFeature = attribute[bestFeatureIndex];                            //��¼��õ�����
 
	root->attribute = bestFeature;          //��¼Ҫ���ֵ�����
 
	for(i=0; i<featureList.size(); i++)     //���ڵ�ǰ���Ե�ÿ������ֵ�������µķ�֧
	{
		vector<string> subAttribute;        //�µ������б���������ǰҪ���ֵ����ԣ���������һ��
		for(j=0; j<attribute.size(); j++)
		{
			if(bestFeature != attribute[j])
				subAttribute.push_back(attribute[j]);
		}
		Node *newNode = new Node();         //�½��ڵ�
		newNode->val = featureList[i];      //��¼���Ե�ȡֵ

        //�ݹ鴴��������
        update = DTA_splitDataSet(data, bestFeatureIndex, featureList[i]);
		DTA_createTree(newNode, update, subAttribute);
		root->childs.push_back(newNode);    //Ϊ���ڵ����child
	}
	return root;
}

//��ӡ������ 
void DTA_printTree(Node *root, int depth)
{
    ofstream fout("DecisionTree.txt",ios::app);		//ʹ��׷�ӵķ�ʽ���ļ� 
	int i;              //ѭ������i
	//����㷨 
	for(i = 0; i < depth; i++)
		fout << "\t";
	
	if(root->val != "")
	{
		fout << root->val << endl;
		for(i = 0; i < depth+1; i++)
			fout << "\t";
	}
	fout << root->attribute << endl;
	fout.close();
	//��ջ���������ֹδ¼�� 
	//����������� 
	vector<Node*>::iterator it;
	for(it = root->childs.begin(); it != root->childs.end(); it++)
	{
		DTA_printTree(*it, depth+1);
	}
	// cout << "DTA_printTree is completed" << endl;
}
string DTA_classify(Node *root, vector<string> &attribute, vector<string> &test)
{
	string firstFeature = root->attribute;
	int firstFeatureIndex;
	int i;
	for(i=0; i<attributes.size(); i++)  //�ҵ����ڵ��ǵڼ�������
	{
		if(firstFeature == attribute[i])
		{
			firstFeatureIndex = i;
			break;
		}
	}
	if(root->isLeaf)  //�����Ҷ�ӽڵ㣬ֱ��������
		return root->attribute;
	for(i=0; i<root->childs.size(); i++)
	{
		if(test[firstFeatureIndex] == root->childs[i]->val)
		{
			return DTA_classify(root->childs[i], attribute, test);
		}
	}
}

//�������ӡ����result.txt���� 
void DTA_printResult(vector< vector<string> > &data,Node* root)
{
	vector<string> temp;
	string result;
	int i = 1;
	try{
		vector<vector<string> > ::iterator iter;
		for(iter = data.begin(); iter != data.end(); ++iter)
		{
			ofstream fout("result.txt",ios::app);
			temp = *iter;
			result = DTA_classify(root,attributes,temp);
			if(result != "no")
				result = "yes"; 
	 		fout << "��" << i << "�����ԵĽ��Ϊ��" << result << endl;		
	 		i++;
	 		fout.close();
		}				
	} catch(std::bad_alloc)
	{
		cout << "bad_alloc happened" << endl;
	} 
}
//�ͷŽڵ�

void DTA_freeNode(Node *root)
{
	if(root == NULL)
		return;
	vector<Node*>::iterator it;
	for(it=root->childs.begin(); it != root->childs.end(); it++)
		DTA_freeNode(*it);
	delete root;
}

//main����
int main(void)
{
//	����printResult�Ĵ���
//	int i;				//ѭ�� 
//	string result;		
//	vector <string> test;
//		test.push_back("��");
//		test.push_back("��");
//		test.push_back("����");
//		test.push_back("��");
    DTA_createTrainDataset();
	cout << "DTA_createTrainDataset is completed" << endl;
    DTA_createTestDataset();
	cout << "DTA_createTestDataset is completed" << endl;
	//��ȡroot 
	root = DTA_createTree(root, trainData, attributes);
	cout << "DTA_createTree is completed" << endl;
	DTA_printTree(root, 0);
	cout << "DTA_printTree is completed" << endl;
//	result = DTA_classify(root, attributes, test);
//	cout << "���ԵĽ��Ϊ��" << result << endl;
	DTA_printResult(testData,root);
	cout << "DTA_printResult is completed" << endl;
	DTA_freeNode(root);
	cout << "DTA_freeNode is completed" << endl;

    return 0;
}
