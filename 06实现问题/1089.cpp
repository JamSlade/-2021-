#include <stdio.h>
#include <string.h>
const int N = 111;
int dx[N] = {0},dy[N] = {0};
char order[N];
//***********************************************
int walk(int ab,int dxy,int dis_xy)//����һ��ѭ�����ÿһ��״̬������ab�ܷ񵽴���һ״̬���ڼ���ѭ������
{
    if(dis_xy > 0 && ab >= dxy && (ab - dxy) % dis_xy == 0)
        return (ab - dxy) / dis_xy;//����0�����һ��ѭ���͵���
    else if(dis_xy < 0 && ab <= dxy && (ab - dxy) % dis_xy == 0)
        return (ab - dxy) / dis_xy;//����0�����һ��ѭ���͵���
    else if(dis_xy == 0 && ab == dxy)
        return -2;//-2��ʾÿ�ζ��ɵ���
    else
        return -1;//-1��ʾ�޷�����
}

/**********************************************/
int main(void)
{
    scanf("%s",order);
    int len=strlen(order);
    dx[0] = 0;
    dy[0] = 0;
    for(int i = 1; i <= len; i++)   //dx��dy��������order����1
    {                               //����һ��ѭ�����ܵ����״̬
        dx[i] = dx[i-1];
        dy[i] = dy[i-1];
        switch(order[i-1])
        {
        case 'U':
            dy[i]++;
            break;
        case 'D':
            dy[i]--;
            break;
        case 'L':
            dx[i]--;
            break;
        case 'R':
            dx[i]++;
            break;
        }
    }
    int dis_x = dx[len];
    int dis_y = dy[len];
    //��ʼ�����


    int __;
    scanf("%d",&__);
    for(int _ = 0,a,b; _<__; _++) //OJ�ﵥ�������������������������»���
    {                             //��˾�ﲻ�У���Ȼ�ᱻ�� :)
        scanf("%d %d",&a,&b);
        //��������

        int ans = 0;
        for(int i = 0;i <= len; i++)
        {
            ans = 0;
            int can_reach_a = walk(a,dx[i],dis_x);
            int can_reach_b = walk(b,dy[i],dis_y);
            if(can_reach_a == -1 || can_reach_b == -1)//-1��ʾ�޷�����
                ans = 0;
            else if(can_reach_a == -2 || can_reach_b == -2)//-2��ʾÿ�ζ��ɵ���
                ans = 1;
            else if(can_reach_a == can_reach_b)//��ʾ����ͬ��ѭ������
                ans = 1;
            else
                ans = 0;//��ʾ�ڲ�ͬ��ѭ������
            if(ans)
                break;
        }
        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}