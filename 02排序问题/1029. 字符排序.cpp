#include<iostream>
#include<cstring>
using namespace std;

void sort(char arr[],int len)
{   
    
    int *brr = new int[26];
    memset(brr,0,26 * 4);
    char *crr = new char[len];
    memset(crr,0,len);
    
    for(int i = 0; i < len; i++)
    {
        if(arr[i] >= 'A' && arr[i] <= 'Z')
            brr[arr[i] - 'A'] += 1;
            //���Ǵ�д��ĸ������ת��λbrr�У�������λ���ж��ٸ���
    }
    

    int a, b , c;
    a = b = c = 0;
    while(a < len)
    {
        if(arr[a] >= 'A' && arr[a] <= 'Z')
        {
            while(brr[b] == 0)//����if ��while
            {b++;}//Ҫ����ĸ��
            crr[c++] = b + 'A';
            brr[b]--;//��Ӧ����ĸ����һ��
            a++;
        }
        else
        {crr[c++] = arr[a++];}
    }
  
  
    for(int i = 0; i < len; i++)
    {
        cout << crr[i];
    }
    cout << endl;
    delete[] brr;
    delete[] crr;

}


int main()
{
    int total;
    cin >> total;
    getchar();

    for(int i = 0; i < total; i++)
    {
        char put[202] = {0};
        int len = 0;
        char c = getchar();
        while((c != '\n' && c != EOF))
        {
            put[len++] = c;
            c = getchar();
        }
        cout << "case #" << i << ":" << endl;
        sort(put,len);

    }
}