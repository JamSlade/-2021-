#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

ll a[20];
ll dp[20][20];

int dfs(int location, bool Fdigit, bool upper)
{
    if(location == -1)
        return 1;
    //�����������е���λ֮��location�ᵽ-1λ
    //��Ӧ�ľ��ǵ�һλ��ǰһλ���������ˣ�
    //��ʾö�����

    if(!Fdigit && !upper && dp[location] != -1)
        return dp[location][state];
    /*
    Fdigit������λ�����Ƿ���0
    upper������������Ƿ��������λ���Ͻ�

    ����˵234
    ���԰�Fdigit�ֳ�3�����ۣ�2��1��0��
    ����100~199�� 001~099 �� 200~234�ⲿ��

    ����Ȼ�����λ��1������100~199���Ĳ���  Ҳ����˵����λ����0��
    �ڲ��Ҳ�������λ     ������λ��2������ÿ�����һλ�ǲ���3
    �۲���ǰ��ĵݹ��Ѿ���¼��000~099�ⲿ�ֵ����ݣ�
    
    �ǾͿ���ֱ�ӷ���100��199�ⲿ����


    */

    int up = upper ? a[location] : 9;
    ll count = 0;
    for(int i = 0; i < up; i++)
    {
        if(i == 9)//����9ֱ������
            continue;
        count += dfs(location - 1,Fdigit && i == 0, upper && i == a[location]);
    }

    if(!Fdigit && !upper)
        dp[location] = count;
    
    return count;
}

int main()
{
    ll count = 0;
    ll a,b;
    cin >> a >> b;

    for(ll i = a; i <= b; i++)
    {
        if(i % 9 == 0)
        {continue;}
        ll temp = i;
        while(temp)
        {
            ll t = temp % 10;
            if(t == 9)
            {goto FLAG;}
            temp /= 10;
        }

        count++;
        FLAG:;
    }
    cout << count << endl;
    return 0;
}