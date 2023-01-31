#include<iostream>
#include<stack>
using namespace std;

string alpha = "0123456789ABCDEF";

void transI(stack<int>&bin)
{
    long long i = 0;
    long long r = 0;
    

    int first = bin.top();
    bin.pop();
    
    int len = bin.size();
    for(int j = 0; j < len; j++)
    {
        //��ʱ�����stackȡ�����������λ
        //����˵������111����λ����ôֻ��Ҫ����ǰ��λ
        //����ڶ���1��ʱ��ֻ��Ҫ������һ��
        
        int temp = bin.top();
        
        if(temp == 0)
        {
            bin.pop();
            continue;
        }

        if( j != 0 )
        {
            long long a = -1;
            long long b = 1;
            int c = -1;
            int d = 1;
            
            for(int k = 0; k < j; k++)//����-1+i��˱�����������ˣ����Զ�Ӧ��jҪ��-1����kҪ>0
            {
                long long ta = a;
                long long tb = b;
                a = (ta * c - tb *d);
                b = (tb * c + ta *d);
            }
            //cout << "a "<<a<<" b "<<b<<endl;
            
            
            bin.pop();
            i += b;
            r += a;
            
        }
        
        
    }
    
    r += first;
    
    int puti = 0;
    int putr = 0;
    int positive = 0;
    int one = 0;
    if(i)
    {
        puti = 1;
        if(i == 1 || i == -1){one = 1;}
        if(i > 0){positive = 1;}
    }
    if(r){putr = 1;}
    

    if(putr)
    {cout << r;}
    if(positive && putr)
    {cout << '+';}
    
    if(puti && !one)
    {cout<< i << "i" ;}
    else if(puti && one)
    {
        cout << ((i > 0)?"i":"-i");
        
    }
}

int main()
{
    string hexadecimal;
    cin >> hexadecimal;

    if(hexadecimal == "0x0")
    {
        cout << "0";
        return 0;
    }
    int len = hexadecimal.length();
    // long long decimal = 0;
    // for(int i = 2; i < len; i++)
    // {
    //     decimal *= 16;
    //     decimal += alpha.find(hexadecimal[i]);
    //     cout << decimal << endl;
        
    // }
    //����̫���ף�������long long ֱ��ת��
    
    stack<int>bin;
    for(int j = 2; j < len; j++)
    {
        
        int temp = alpha.find(hexadecimal[j]);
        cout <<"temp" << temp;
        for(int i = 0; i < 4; i++)
        {
            int mod = temp % 2;
            bin.push(mod);
            temp >>= 1;
            cout << mod ;
        }
        
    }
    
    cout << endl<<bin.size()<<endl;
    transI(bin);

    return 0;
}