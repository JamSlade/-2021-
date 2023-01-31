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
        ll all = 0;

        
        sort(C,C+n,cmp);


        ll m_r_max = 0;//�ҳ���ǰm�������İ뾶����Ϊ�ײ�
        ll m_la_min = LONG_LONG_MAX;
        for(int i = 0; i < m; i++)
        {
            if(m_r_max < C[i].r)
            {
                m_r_max = C[i].r;
            }
            if(m_la_min > C[i].lateral)
            {
                m_la_min = C[i].lateral;
            }
            
        }


        ll temp = 0;
        for(int i = m; i < n; i++)
        {
            if(C[i].surface > (m_la_min + m_r_max * m_r_max) && C[i].r >= m_r_max && C[i].surface > temp)
            {
                //��������surfaceҪ����temp��������Ȼ���ܻ�ƫС����������
                temp = C[i].surface;
            }    
        }

        for(int i = 0; i < m; i++)
        {
            all += C[i].lateral;
        }

        if(temp)
        {
            all -= m_la_min ;
            all += temp;
        }
        else
        {
            all += (m_r_max * m_r_max);
        }
        cout << all << endl;

        return 0;
    }