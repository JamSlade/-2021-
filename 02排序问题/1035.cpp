    #include<iostream>
    #include<algorithm>
    #include<climits>
    #define ll long long
    using namespace std;

    struct cylinder
    {
        ll h;
        ll r;
        ll surface;
        ll floor;
        ll lateral;

        void init()
        {
            floor = r * r;
            lateral = 2 * r * h;
            surface = floor + lateral;//���ӻ�Ӧ��ֻ��һ������Ͳ���
        }

    };

    //  ����ֻ��Ҫǰm�����ݣ���� m-n �����ݲ����н���
    //  ����ֱ���ҳ���ǰm�����������İ뾶��Բ������Ϊ���漴��

    //  �����������Ҫ�� m-n ����֮���������滻����ʲô�����أ�
    //  �� m-n����֮��������ֻ�ܷŵײ�ɣ��������ط��ᵼ�²������С
    //  ���Է� m-n ���ײ� �����������ʲô�仯��
    //  ������ײ�ĵ�������ˣ���Σ���С�Ĳ����������;

    bool cmp(cylinder a, cylinder b)
    {
        return(a.lateral > b.lateral);
    }

    int main()
    {
        int n,m;
        cin >> n >> m;
        cylinder * C = new cylinder[n];
        for(int i = 0; i < n ;i++)
        {
            cin >> C[i].r >> C[i].h;
            C[i].init();
            
        }

        
        sort(C,C+n,cmp);

        ll all = 0;
        for(int i = 0; i < n; i++)
        {
            ll each_max = 0;
            int qual = 0;

            each_max += C[i].surface;
            for(int j = 0; j < n; j++)
            {
                if(j == i)
                {
                    continue;//
                }
                
                
                if(qual == m - 1)
                {
                    break;
                }//���if����һ��if��Ҫ��������ϸ����Ϊɶ
                if(C[i].r >= C[j].r)
                {
                    qual ++;
                    each_max += C[j].lateral;
                }
            }

            if(qual == m - 1 && each_max > all)
            {
                all = each_max;
            }
        }

        cout << all;

        return 0;
    }