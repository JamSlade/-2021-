#include<iostream>
#include<stack>

using namespace std;

int main()
{
    string str;
    char c;
    while((c = getchar()) != EOF)
    {
        str += c;
    }

    int len = str.length();
    string erase;
    int commentOne = 0;
    int commentMuch = 0;
    int CHAR = 0;
    int STR = 0;
    for(int i = 0; i < len;i++)
    {
        FLAG:
        if(str[i] == '/' && str[i + 1] == '/')//����ע�ͼ������з��Ͳ���
        {
            while(str[i] != '\n')
                i++;
            //cout << "1" << endl;
        }

        if(str[i] == '/' && str[i+1] =='*')//����ע�ͽ���֮��Ҫע������Ƿ�����ǵ���ע��
        {
            i+=2;
            while (!(str[i] == '*' && str[i + 1] == '/'))
            {
                i++;
            }
            i += 2;
            goto FLAG;
        }

        if(str[i] =='\'')//�������п��ܻ����˫����
        {
            for(int j = 0; j <= 3; j++)
            {
                erase += str[i + j];
            }
            i += 4;
            goto FLAG;
        }

        if(str[i] == '"')//˫����Ҫ������һ�е����һ��˫���ţ�Ȼ����м��������ݶ�������
        {
            int j = i;
            int k = i;
            while(str[i] != '\n')
            {
                if(str[i] == '"')
                    k = i;
                i++;
            }
            k++;
            for(int q = j; q < k; q++)
            {
                erase += str[q];
            }
            i = k;
            //cout << "3" << endl;
            goto FLAG;
        }



        erase += str[i];

//
    }

    //cout << str << endl;
    cout << erase << endl;


    return 0;
}
//����//֮���������к�����������
//����/*֮������*/������//