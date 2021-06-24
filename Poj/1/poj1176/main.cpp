#include <iostream>
#include<string.h>
using namespace std;

int n,c;
int on[3]= {0};
int off[3]= {0};
bool lamps[101];
int button[4]= {0};
bool check(int i){
    bool s = lamps[i];
    if(button[0]==1)
        {
             s = !s;
            if(i%2==0 )
            {
                if(button[1]==1)
                 {
                     s = !s;
                    //if(i%3==1 && button[3]==1)  s = !s;
                 }
                 if(i%3==1 && button[3]==1)  s = !s;

            }
            else
            {
                if(button[2]==1)
                {
                     s = !s;
                    //if(i%3==1 && button[3]==1)  s = !s;
                 }
                 if(i%3==1 && button[3]==1)  s = !s;
            }
        }
        else
        {
            if(i%2==0 )
            {
                if(button[1]==1)
                 {
                     s = !s;
                    //if(i%3==1 && button[3]==1)  s = !s;
                 }
                  if(i%3==1 && button[3]==1)  s = !s;

            }
            else
            {
                if(button[2]==1)
                {
                     s = !s;
                    //if(i%3==1 && button[3]==1)  s = !s;
                 }
                  if(i%3==1 && button[3]==1)  s = !s;
            }
        }
        return s;
}
void printlamps()
{
    int i;
    for(i=0; i<4; i++)
    {
        if(button[i]%2==1)
            button[i]=1;
        else
            button[i]=0;
    }
    for(i=0;i<3;i++){
        if(!on[i]) break ;
        else if(!check(on[i])) return;
    }
     for(i=0;i<3;i++){
        if(!off[i]) break ;
        else if(check(off[i])) return;
    }

    for(i=1; i<=n; i++)
    {
        cout<<check(i);
    }
    cout<<endl;

}
void dfs(int m,int b)
{
    if(m>=c)
    {
        printlamps();
        //cout<<b<<" is  "<<button[b]<<endl;
        return;
    }
    else
    {
        for(int i=0; i<4; i++)
        {
            m++;b= (b+i)%4;
             button[b]++;
            dfs(m,b);
            m--;
            button[b]--;
        }
    }
}
int main()
{
    cin>>n>>c;
    int temp,i=0;
    cin>>temp;
    while(temp!=-1)
    {
        on[i]=temp;
        cin>>temp;
    }
    cin>>temp;
    while(temp!=-1)
    {
        off[i]=temp;
        cin>>temp;
    }
    memset(lamps,1,sizeof(lamps));
    dfs(0,0);
    return 0;
}
/*
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 0x3f3f3f3f
const int maxn=5010;
using namespace std;
string ans[9];
int a[110];
int state[9][7]=
{
    0,0,0,0,0,0,0,//�±�ӡ�1,1����ʼ
    0,0,0,0,0,0,0,//��1
    0,0,0,1,1,1,0,//��3��4
    0,0,1,0,1,0,1,//��2
    0,0,1,1,0,1,1,//��4
    0,1,0,0,1,0,0,//��1��4
    0,1,0,1,0,1,0,//��3
    0,1,1,0,0,0,1,//��2��4
    0,1,1,1,1,1,1,//����
};
//int state[9][101]=
//{
//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//{0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1},
//{0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
//{0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0},
//{0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1},
//{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//{0,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0},
//{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};

int minn[9]={0,1,2,1,3,2,1,2,2};//8��״̬�ֱ����ٵĴ���


int main()
{
    int n,c;
    int num=0;
    scanf("%d%d",&n,&c);
    memset(a,-1,sizeof(a));
    int x;
    while(scanf("%d",&x) && x!=-1)
        a[x]=1;
    while(scanf("%d",&x) && x!=-1)
        a[x]=0;

    for(int i=1;i<9;++i)//ö�ٷ���
    {
        int f=1;
        for(int j=1;j<=n;++j)
        {
            if(a[j]==-1) continue; //û�涨�������ǰ�
            int temp = j%6;
            if(temp==0) temp=6;
            if(a[j]!=state[i][temp])
         //   if(a[j]!=state[i][j])
            {
                f=0;break;
            }
        }
        if(f && (c >= minn[i] || (c==1 && i==4)) )//���ַ�������
        {
            char now[110];
            num++;

            for(int j=1;j<=n;++j)
            {
              int temp = j%6;
              if(temp==0) temp=6;
              now[j-1]=state[i][temp]+'0';
            //now[j-1]=state[i][j]+'0';
            }
            now[n]='\0';
            ans[num]=now;
        }
    }
    sort(ans,ans+num);
    for(int i=1;i<=num;++i)
        puts(ans[i].c_str());
    return 0;
}

*/