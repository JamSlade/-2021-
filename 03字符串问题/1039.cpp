#include<iostream>

using namespace std;
char com[100];

void print(string & b, int len , int l ,int r)
{
    if(l == r)//�����������ˣ�˵�������ַ�����'\0'��
        return;
    for(;l != r; l++)
    {
        com[len] = b[l];//�Ȱ�һ�����ַŽ�ȥ
        com[len + 1] = 0;//��һ���Ÿ�0
        cout << com << endl;//���
        print(b,len + 1, l + 1, r);//�ⲿ����a������һ���֡�b�������
    }  
}

int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        string a;
        cin >> a;
        int alpha[130] = {0};
        string b;
        for(int i = 0; i < a.length(); i++)
        {
            alpha[a[i]]++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(alpha['A' + i]){b += 'A' + i;}
        }
        for(int i = 0; i < 26; i++)
        {
            if(alpha['a' + i]){b += 'a' + i;}
        }

        cout << "case #" <<i << ":" <<endl;
        int len = b.length();
        print(b,0,0,len);
    }

    return 0;
}