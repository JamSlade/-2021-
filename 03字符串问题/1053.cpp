#include<iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int z = 0; z < t; z++)
    {
        int line_len;
        cin >> line_len;
        getchar();//�л��з�����getlineҪ�ǵ�getchar
        string all;
        getline(cin,all);
        int all_len = all.length();

        cout << "case #" << z << ":"<<endl;

        
        int i = 0;//����all�ı���

        while(i < all_len)
        {
            
            for(; all[i] == ' '; i++);//����ͷ�Ŀո�
            int line_loc = i;//ÿһ�еĿ�ͷ
            int word_alen = 0;//��¼һ�еĵ�����ĸ��
            int word_anum = 0;//��¼������,��Ӧ��Ҳ���� �ٿո���+1
            
            for(; word_alen + word_anum <= line_len && i < all_len ;) /*iԽ�����⡣����*/
            {
                int j = 0, k = i;
                while(all[k] != ' ' && k < all_len) /*lԽ�����⡣����*/
                {
                    j++;k++;//j��¼��һ�����ʳ���
                }
                if(j + word_alen + word_anum <= line_len)
                {
                    word_alen += j;
                    word_anum++;
                    //����ͷŽ�ȥ��һ��
                    for(i = k; all[i] == ' '; i++);//������һ������
                }
                else
                    break;
            }
            int empty = line_len - word_alen;//�ո�����
            word_anum--;




            while(line_loc < i)
            {
                while(all[line_loc] != ' ' && line_loc < i)
                    cout << all[line_loc++];
                while(all[line_loc] ==' '&& line_loc < i)/*Խ�����⡣����*/
                    line_loc++;

                if(i == all_len && word_anum)
                    cout << ' ' ;//���һ����������ո�
                else
                {
                    int j = 0;//������һ�еĿո񾡿��ܾ������ұ�
                    for(;word_anum && j < empty / word_anum; j++)
                    {
                        //������������Ȼ��������ұ���empty/word����������
                        cout << " " ;
                    }
                    empty -= j;//��ӦҲҪ����
                }
                word_anum--;
            }
            cout << endl;


        }
        
    }

    return 0;
}

