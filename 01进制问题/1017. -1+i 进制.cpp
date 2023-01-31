#include<iostream>
#include<stack>
using namespace std;

class com
{
public:
    long long i;
    long long r;
    int rema;

    com(long long i, long long r,int remain)
    {
        this->i = i;
        this->r = r;
        this->rema = remain;
    }
    com operator^(const com &c)const
    {
        int has_mod = 0;
        long long real = r;
        long long imag = i;
        int remain;
        if((real + imag) % 2 != 0)
            {remain = 1;
            real--;
            //cout <<"???"<<r << i<<remain<<endl;
            }
        else
            {remain = 0;
            //cout <<"!!!"<<r << i<<remain << endl;
            }
        //��������ֻ����-1+i,���ԾͲ���������������
        long long r1 = (imag - real) / 2 ;
        long long i1 = (-imag - real) / 2;

        

        return com(i1,r1,remain);//
    }

};

void trans(long long r, long long i)
{
    stack<int>bin;
    com translate(i,r,0);
    com base(1,-1,0);

    while(translate.i || translate.r)
    {
        translate = translate ^ base;
        //cout << "i "<<translate .i <<" r "<<translate.r << " remain "<<translate.rema << endl;
        bin.push(translate.rema);
    }
    while(!bin.empty())
    {
        cout << bin.top();
        bin.pop();
    }

}

int main()
{
    //�����ַ���ת��Ϊ����
    string a;
    cin >> a;
    if(a == "0")
    {cout << 0;
    return 0;}
    
    
    char c;
    long long i = 0;
    long long r = 0;

    int pos_r = 0;
    int pos_i = 0;
    int is_r = 0;
    int is_i = 0;
    int neg_r = 0;
    int neg_i = 0;

    int len = a.length();
    int j = len - 1;

    if(a[j] == 'i')
    {
        is_i = 1;
        j--;    
    }
    if(is_i)
    {   
        stack<int> bin;
        if(a[j] == '-' || a[j] == '+' || j == -1)
            i = 1;

        for(; a[j] != '+' && a[j] != '-' && j != -1 ; j--)
        //Ҫ���� 1 �������� 2 ����ǰ�Ƿ���ʵ�� 
        {
            bin.push(a[j] - '0');
        }
        while(!bin.empty())
        {   
            int temp = bin.top();
            i *= 10;
            i += temp;
            bin.pop();
        }

        (j == -1 || a[j] == '+')? pos_i : neg_i = 1;
        if(a[j] == '-')
        {
            neg_i = 1;
        }

        if(neg_i)
        {
            i = -i;
            if(j == 0)
            {trans(r,i);return 0;}//ûʵ����
        }

        if(j == -1)//ûʵ����
        {trans(r,i);return 0;}

        j--;//��ʵ�����Ǿ���λ��ǰһ�㣬����ָ����+����-
    }

    //�������ִ�����������˵������ʵ����
    stack<int>qqq;
    for(; j > 0; j--)
    {
        qqq.push(a[j] - '0');
        
    }
    if(a[0] == '-')
    {
        neg_r = 1;
    }
    else
    {
        qqq.push(a[0] - '0');
    }
    while(!qqq.empty())
    {
        int temp =qqq.top();
        r *= 10;
        r += temp;
        qqq.pop();
    }
    if(neg_r)
    {r = -r;}
    

    
    FLAG:
    //cout << "i " << i <<" r "<<r<<endl;
    trans(r,i);
}