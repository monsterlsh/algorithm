#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
char s[10][10];//棋盘
int a[10];//标记每一列是否有棋子，有棋子为1，无棋子为0
int tot,cont;//总方案数，已放入棋盘棋子的个数

void dfs(int cur)
{
    if(cont == m)  //棋子个数达到要求，方案数+1，返回
    {
        tot++;
        return ;
    }
    if(cur >= n)//若搜出棋盘外，返回
        return ;
    for(int j = 0;j < n;j++)
     {
        if(!a[j] && s[cur][j] == '#')
        {
            a[j] = 1;//标记为1
            cont++;
            dfs(cur + 1);
            a[j] = 0;//清除标记
            cont--;
        }
     }
    dfs(cur + 1); //cur行不放棋子
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        if(n == -1 && m == -1)
            break;
        getchar();
        tot = 0;
        cont = 0;
        memset(a,0,sizeof(a));//将标记初始化为0
        for(int i = 0;i < n;i++)
        {
            gets(s[i]);
        }
        dfs(0);
        printf("%d\n",tot);
    }
    return 0;
}
