#include<iostream>

using namespace std;

void compress(unsigned long long a)
{   
    int binb[64] = {0};
    int flag = 0;
    int before = 0;
    
    
    
    //ת������������
    for(int i = 0; i < 64; i++)
    {
        if( a & (1LL << 63) )
        {
            flag = 1;
            binb[i] = 1;
        }

        a <<= 1;

        if(flag)
            before++;
    }
    

    flag = 0;//��ʼ�����ڶ���
    int count = 0;
    int bina[64] = {0};
    int after = 0;
    int place = 63;
    //�Ӻ���ǰ

    for(int i = 0; i < before; )
    {   
        count = 0;//��ע��һ��������while(count--)  ����-1�ġ�
        if(binb[63 - i] == 0)
        {
            bina[place--] = 0;
            i++;
            after++;
            continue;
        }//0�����
        else
        {
            while(binb[63 - i])
            {
                count++;
                i++;
            }
            
            // cout << " cout "<<count << endl;
            if(count <= 2)//1�������������
            {
                while(count)
                {
                    bina[place--] = 1;
                    after++;
                    count--;
                }
                
            }
            else
            {
                //count��10���Ʊ��2����
                while(count)
                {
                    bina[place--] = (count % 2) ? 1 : 0;
                    count >>= 1;
                    after++;
                }
            }
            //cout << " cout "<<count << " i "<<i<<endl;
            // for(int i = 0; i < 64; i++)
            // {
            //     cout << bina[i];
            // }
            // cout<<endl;
        }
        
        
    }
    //��countͬ��
    unsigned long long num = 0;//����ҲҪULL�������ˡ�����
    for(int i = 0;i < 64; i++)
    {
        num *= 2;
        num += bina[i];
    }

    
    cout << num <<","<<before<<","<<after;

}

int main()
{
    unsigned long long a;
    cin >> a;
    compress(a);
}

