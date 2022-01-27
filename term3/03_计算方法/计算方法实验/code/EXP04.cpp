/**
 * @author: Li Haporan 
 * @date: 2020.10.20
 * @details: ʵ����,�����Է����������
 */

#include <iostream>
#include <math.h>

using namespace std;

//Ĭ�Ϻ�������ֵ����6
double f(double x)
{
    return (x * x * x) - x - 1;
}

//Ĭ�Ϻ�����һ�ε�������
double df(double x) 
{
    return 3 * (x * x) - 1;
}

//ţ����ɽ��
void NewtonDownhill(double x0, double e, int N, int M)
{
    //�������
    int k = 0;
    double x1;
    double lamda = 1.0;
    bool flag = false;

// ѭ����ʼţ����ɽ��
    while ( true )
    {
        // �����ɽ����
        if(lamda != 1)
        {
            cout << "��" << k << "����ɽ���ӣ�" << lamda << endl;
        }
        // ��ɽ���ӳ�ʼ��Ϊ1.0
        lamda = 1.0;

        // ��Ϊ����ֵΪ0����Ϊ�����־
        if ( df(x0) == 0 )
        {   
            cout << "�����־" << endl;
        }
        // ���������ɽ����
        else
        {
            while ( true )
            {
                if(flag == true)
                {
                    flag = false;
                    break;
                }
                x1 = x0 - lamda * (f(x0) / df(x0));

                // ������������,˵����ɽδ����
                if ( fabs( f(x1) ) > fabs( f(x0) ) )
                {
                    cout << "��" << k << "����ɽ����Ϊ��" << lamda << endl;

                    k ++;
                    lamda = lamda * 0.5;
                    // ��ɽ������������
                    if ( k >= M)
                    {
                        cout << "��ɽ�������࣬����������x0" << endl;
                        exit(0);
                    }
                    else continue;
                 
                }
                // ��ɽ������,�������
                else
                {
                    if (fabs(x1 -x0) < e)
                    {
                        cout << "���Ƹ�Ϊ��" << x1 << endl;
                        exit(0);
                    }
                    else
                    {
                        k = k + 1;
                        x0 = x1;
                        if (k >= N)
                        {
                            cout<<"����ʧ�ܣ�"<<endl;
                            exit(0);
                        }
                        else
                        {
                            flag = true;
                            continue;
                        }    
                    }
                }           
            }
        }
    }
}

int main (void) 
{
    /**
     * @param x0 ��ֵ
     * @param e �����
     * @param N ����������
     * @param M ��ɽ������
     */
    double x0;
    double e;
    int N;
    int M;

    //�����������
    cout << "�������ֵ:" << endl;
    cin >> x0;
    cout<<"�����������:"<<endl;
    cin >> e;
    cout << "��������ɽ������:" << endl;
    cin >> M;
    cout << "���������������:" << endl;
    cin >> N;

    //����ţ����ɽ��
    NewtonDownhill(x0, e, N, M);
    
    return 0;
}
