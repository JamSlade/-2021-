#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int str_len;
    int line_len; //ÿ�г���
    char s[2001];
    scanf("%d\n",&line_len);
    gets(s);
    str_len=strlen(s); //�ַ�����
    /*
    ��ǰ����ɨ���ַ�����ͳ��ÿһ�п������
    �ĵ��ʸ�����������Ҫ���Ŀո�
    Ȼ���ٰ�Ҫ���Ű����ÿһ��

    �������±��� ��
    words_len: ÿһ��Ҫ����ĵ����ܳ���
    words_count��ÿһ��Ҫ����ĵ��ʸ���
    space�� ÿһ����Ҫ���Ŀո����   
    */
    int i;
    for(i=0;s[i]==' ';i++); //�������׿ո�
    while(i<str_len)
    {
        int start=i; //start��¼ÿһ��Ҫ����ĵ�һ�����ʵ���ʼλ��
        int words_len=0,words_count=0;
    // ͳ��ÿһ��Ҫ����ĵ����ܳ���words_len;
    // ͳ��ÿһ��Ҫ����ĵ��ʸ���words_count��
    // ����ÿһ��Ҫ���Ŀո����space;
    // �����Ű�Ҫ�����ÿһ�У�
        int l, p;
        for(;words_len+words_count<=line_len&&i<str_len;) 
        {
            for(l=0,p=i;s[p]!=' '&&p<str_len;p++,l++); //������һ�����ʼ��䳤��
            if(words_len+words_count+l<=line_len)
                { 
                words_len+=l;words_count++;
                for(i=p;s[i]==' ';i++); //�����ո�
                }
            else break;
        }
        int space=line_len-words_len; //����ÿ�������Ŀո����

        int j=start; words_count--;
        while(j<i) //�����Ű�Ҫ�����һ��
        {
            while(s[j]!=' '&&j<str_len) putchar(s[j++]); //���һ������
            while(s[j]==' '&&j<str_len) j++; //�����ո�
            if(i==str_len&&words_count) //���һ�У�����֮�����һ���ո�
            putchar(' '); 
            else //�����еĿո��ڵ���֮�価���ܾ��ȷֲ��������ܿ���
            {   

                for(p=0;words_count&&p<space/words_count;p++)
                putchar(' '); 
                space-= p;
            }
            words_count--;
        } putchar('\n');

    }
}

