
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
string a[2000];
int i,t=1;
double f1(double a,char b,double c)//���㺯��
{
    switch(b)
    {
        
        case'+':return a+c;
        
        case'-':return c-a;//���������ͳ���ǰ��������λ��
        case'*':return a*c;
        case'/':return c/a;
    }
}

double f2()
{
    int i=t;//t�൱��һ��ָ��
    if(a[i][0]>='0'&&a[i][0]<='9')//���i��λ����һ����ֵ
    {
        t++;//ָ��ָ����һλ
        return atof(a[i].c_str());//ת���ɸ�����
    }
    t++;//������������ָ��ָ����һλ
    return f1(f2(),a[i][0],f2());//�����Ĳ����Ǵ������󴫵ݵ�
}

int main()
{
    string b;
    while(cin>>b)
        a[++i]=b;
    printf("%lf",f2());
    return 0;
}