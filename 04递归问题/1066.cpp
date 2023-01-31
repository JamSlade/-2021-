#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

ll dp[20][10];
int dig[20];

ll dfs(int loc, int num, bool lim, int sum)
{
    if(loc == -1 && sum % 9)
        return 1;
    else if(loc == -1)
        return 0;
    
    if(!lim && dp[loc][num] != -1)
        return dp[loc][num];
    //����Ҫ�ж��Ƿ������޵����
    //�ٶ���15������֣���������ж����޵Ļ�������ֱ�ӵ�������19��Ҳ���Ǻ��Ե�������5������������8�����ۼ�
    
    int a = lim ? dig[loc] : 9;
    ll way = 0;
    for(int i = 0; i <= a; i++)
    {
        if(i == 9)
            continue;
        way += dfs(loc - 1, i, lim && dig[loc] == i, sum + i);
    }
    if(!lim)
    dp[loc][num] = way;
    return way;
}

ll solve(ll a)
{
    memset(dp,-1,sizeof(dp));
    memset(dig,0,sizeof(dig));

    
    for(int i  = 0; i < 20; i++)
    {
        dig[i] = a % 10;
        a /= 10;
    }
    //����while ���ܻ�Խ��
    //֮ǰ��while�ͻᵼ��һЩ��Ե���ݵĴ���Ĳ���ȷ
    return dfs(19, dig[19], 1, dig[19]);
}

int main()
{
    ll a,b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1);
    return 0;

}