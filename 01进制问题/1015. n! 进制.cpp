#include<iostream>
#include<stack>
using namespace std;

void trans(long long a)
{
    long nbase[10];
    long base = 1;
    for(int i = 1; i <= 9; i++)
    {
        base *= i;
        nbase[i] = base;  
    }

    int flag = 0;
    for(int i = 9; i > 0; i--)
    {
        int temp = a / nbase[i];//��Ӧ�ļ��������¿��Գ������ּ�
        if(temp != 0)//ע�⵽ǰ�������0
        {
            cout << temp;
            flag = 1;//��֤�����0�������
            a = a - temp * nbase[i];//ע��n������Ҫ��μ��� 
        }                           //��ǰ����ֱ�ӳ��������٣����������n!����ÿ�γ�����ͬ��������㻹��ֱ�Ӽ�
        else
        {
            if(flag)
            {
                cout << temp;
            }
        }
        

    }
    cout << endl;
}

int main()
{
    int total;
    cin >> total;

    for(int i = 0 ; i < total; i++)
    {
        long long a;
        cin >> a;
        cout << "case #" << i<<":"<<endl;
        trans(a);
    }
    
}