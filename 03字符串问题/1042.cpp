#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>
using namespace std;

//����ʵ�����ǰ��ַ�������ȥ��֮��ȽϿ��Ƿ���ȣ�Ȼ�����ַ������������бȽ�
//ȡ����СֵӦ�������м䳤�ȵ��������ȴ�С
string duplicate(string a)
{
    int len = a.length();
    deque<char> b;
    b.push_back(a[0]);

    for(int i = 1; i < len; i++)
    {
        if(a[i] == b.back())
        {
            continue;
        }
        else
        {
           b.push_back(a[i]);
        }
    }

    string c;
    for(deque<char>::iterator it = b.begin(); it != b.end(); it++)
    {
        c += *it;
    }
    return c;
}

//�ó������¼��������
//�������Ѹ�������ת����strȻ��ȥ��
bool cmp(int a, int b)
{
    return (a < b);
}

int change_min(int *arrl,int t)
{
    int mid = t / 2;
    int mid1 = mid;
    if(!(t % 2))
    {
        mid1--;
    }

    long long times = 0;
    for(int i = 0; i < mid; i++)
    {
        times += arrl[mid] - arrl[i];
    }
    for(int i = mid + 1; i < t; i++)
    {
        times += arrl[i] - arrl[mid];
    }

    long long times1 = 0;
    for(int i = 0; i < mid1; i++)
    {
        times1 += arrl[mid1] - arrl[i];
    }
    for(int i = mid1 + 1; i < t; i++)
    {
        times1 += arrl[i] - arrl[mid1];
    }
    return (times > times1) ? times : times1;
}


int main()
{
    int t;
    cin >> t;
    string *str = new string[t];
    string *str1 = new string[t];

    for(int i = 0; i < t; i++)
    {
        cin >> str[i];
        str1[i] = duplicate(str[i]);
    }

    for(int i = 0; i < t - 1; i++)
    {
        if (str1[i] != str1[i + 1])
        {
            cout << "-1" << endl;
            return 0;
        }
    }


    
    int len = str1[0].length();
    int * arrl = new int[t];
    int * location = new int[t];//��¼λ��

    memset(arrl, 0 ,4 * t);
    memset(location, 0 ,4 * t);
    long long T = 0;


    for(int i = 0; i < len; i++)//���������ݿ�ʼ�ָ�
    {
        for(int j = 0; j < t; j++)//ÿ������������ַ�����Ҫͳ��
        {
            int len = str[j].length();
            for(;location[j] < len; location[j]++)//ÿ���ַ�����ÿ������
            {
                if(str[j][location[j]] == str1[0][i])
                {arrl[j]++;}
                else
                {break;}//
            }
        }

        //ͳ�ƺõ����ַ��ڸ����ַ������������󣬿�ʼ����λ��������
        sort(arrl , arrl + t, cmp);


        T += change_min(arrl,t);
        
        
        //���³�ʼ������һ��ѭ��
        memset(arrl, 0 ,4 * t);
    }
    

    cout << T << endl;


    return 0;
}