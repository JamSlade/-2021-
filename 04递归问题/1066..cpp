#include<iostream>
#define ll long long
using namespace std;

ll POW(ll base, ll power)
{
    ll temp = 1;
    while(power--)
    {
        temp *= base;
    }
    return temp;
}

ll distan(string s)
{
    int len = s.length();
    int times = 0;
    for(int i = 0; i < len - 1; i++)
    {
        times += s[i] -'0';
    }
    return (times % 9) ? (9 - times % 9) : 0;
    //�ж��������Ĩȥ��λ��������һ��9�ı������ж��ٸ���

}

ll solve(string s)
{
    int len  = s.length();
    ll num = 0;
    for(int i = 0; i < len - 1; i++)
    {
        if(s[i] == '9')
        {
            for(int j = i; j < len; j++)
                s[j] = '8';
        }
        num += (s[i] - '0') * POW(9LL, len - i - 2) * 8LL;
        //���� 1023��ÿ����ǧ�ͻ���0~8 �Ÿ���������Ҫ�����ۼ�
        //ÿ�������ֿ��Է�0~8�Ÿ���10������ÿ����ʮ����8��������������
    }

    ll remain = min(s[len - 1], '8') - '0';
    num += remain;//��λ����������
    num ++;//������0

    if(distan(s) <= remain)
        num--;

    return num;

    
}

int main()
{
    string a,b;
    cin >> a >> b;
    ll way = solve(b) - solve(a);
    cout << ++way << endl;
    //������a�Ǳ�����
    return 0;
}