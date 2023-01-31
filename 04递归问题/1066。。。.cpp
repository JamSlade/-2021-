#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a,b;

ll mpow(ll a,ll b)
{
    ll ret = 1;
    while(b--)
    {
        ret *= a;
    }
    return ret;
}

ll mix(string s)
{
    ll temp = 0;
    for(int i = s.length() - 2;i >= 0;--i){
        temp += s[i] - '0';
    }
    ll ret = temp % 9;//�ж��Ƿ���9�ı�����
    return ret ? 9 - ret : 0;//���ظ�������һ��9�ı������������
}

ll cal(string s)
{
    ll len = s.length();
    ll ret = 0;
    for(ll i = 0;i < len - 1;++i)
     {
        if(s[i] == '9')
        {
            for(ll j = i;j < len;++j){
                s[j] = '8';
            }
        }
        ret += (s[i] - '0') * mpow(9LL,len - i - 2) * 8LL;
    }

    ll left = min(s[len - 1],'8') - '0';//�����һλ�������⴦��
    ret += left + 1;
    if(mix(s) <= left)--ret;
    return ret;
}

int main()
{
    while(cin>>a>>b){
        cout<<cal(b) - cal(a) + 1<<endl;
    }
    return 0;
}