#include<iostream>
#include<string.h>
using namespace  std;


// void trans(int q)
// {

//     string Octal;
//     char decimal[1000];
//     /*
//     ��   �˽���ת��ʮ����ʱ
//         �Ӻ���ǰ��ÿ��ȡ��ÿһλ������8��
//         ��������һ�γ�������õ��������
//         �ٳ���8
//     */
//     cin >> Octal;
//     int num;//��¼ʮλ��
//     int len = Octal.length() - 1;
//     int Dlen = 0;//��¼ʮ��������λ��

//     for(; len != 1; len--)
//     {
//         num = Octal[len] - '0';
//         int digit = 0;//��¼mod֮�����
//         int j = 0;//��ǰ����
//         do
//         {
//             int temp;
//             if(j < Dlen)
//             {
//                 temp = num * 10 + decimal[j] - '0';
//             }
//             else
//             {
//                 temp = num * 10;
//                 //����û�д�ŵ������ˣ�ֻ�ܼ��������0
//             }
//             digit = temp % 8;
//             decimal[j++] = temp / 8 +'0';//������j��Ҫ����һλ�ģ�Ȼ�������ַ������Ǽ�0
//             num = digit;
//         }
//         while(digit || j < Dlen);
//         Dlen = j;//����ʮ���Ƶ�λ��
//     }
    
//     cout << "case #" << q << ":" << endl <<"0.";
//     for(int i = 0; i < Dlen; i++)
//     {
//         cout << decimal[i];
//     }
//     cout << endl;
// }
void add(char *a, char *b)
{
    int alen = strlen(a);
    int blen = strlen(b);
    char * OP = a;//a+b�Ĵ�С��ֵ��a��OP��

    int len = (alen > blen) ? alen : blen;
    OP[len] = '\0';
    int ten_dig = 0;
    int c = 0;
    for(int i = len - 1; i > 1; i--)
    {
        //ע�����a bС����������һ��������Ҫ��0
        int da = (i < alen) ? a[i] - '0' : 0;
        int db = (i < blen) ? b[i] - '0' : 0;
        
        int sum = da + db + c;
        c = sum / 10;
        OP[i] = sum % 10 + '0';//������char��

    }
    OP[1] = '.';
    OP[0] =  a[0] + b[0] - '0' + c;
    
}


void trans01(int a)
{
    char oct[1000];
    scanf("%s",oct);
    cout << "case #" << a << ":"<<endl;
    char c[1000] = {'0'};
    c[1] = '.';
    
    int len = strlen(oct);
    for(int i = 2; i < len; i++)
    {
        char b[1000] = {'0'};
        b[1] = '.';
        for(int j = 2; j <= i; j++)
        {
            
        }
    }
}



int main()
{
    int total;
    cin >> total;
    for(int i = 0; i < total; i++)
    {
        //trans(i);
        trans01(i);
    }
}