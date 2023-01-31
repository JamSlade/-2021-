#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

int A[32],B[32],K[32];
ll dp[32][2][2][2];

ll dfs(int loc, int aup, int bup , int kup)
{
    if(loc == -1)
        return !(aup || bup || kup);
        //������һ����1��˵����һ����ȡ��������
    if(dp[loc][aup][bup][kup] != -1)
        return dp[loc][aup][bup][kup];
        //��ʼ�����˾�ֱ�ӷ��أ���Ȼ�ͻ��ظ������ӵݹ�
    
    int amax = aup ? A[loc] : 1;
    int bmax = bup ? B[loc] : 1;
    //�������޵Ļ���ȡ���ֵ,��������ֵ��1

    ll way = 0;

    for(int i = 0; i <= amax; i++)
    {
        for(int j = 0; j <= bmax; j++)
        {
            if(kup && (i & j) > K[loc])
                continue;//����kλҲ������
            bool taup = ((aup && i) == amax);
            bool tbup = ((bup && j) == bmax);
            //�жϽ������ĵݹ��Ƿ����ϼ�������
            bool tkup = (kup && (i & j) == K[loc]);
            //�ж��Ƿ��K��Ӧ��λ���

            way += dfs(loc - 1, taup, tbup, tkup);
        }
    }
    dp[loc][aup][bup][kup] = way;
    return way;
}

void solve()//��ʼ��
{
    int a,b,k;
    cin >> a >> b >> k;
    for(int i = 0; i < 32; i++)
    {
        A[i] = a & 1; a >>= 1;
        B[i] = b & 1; b >>= 1;
        K[i] = k & 1; k >>= 1;
    }
    memset(dp,-1,sizeof(dp));
    cout << (ll)dfs(31,1,1,1) << endl;
    //Ĭ�Ͽ�ʼ��ʱ����1���ж��Ƿ�������
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}