#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char st[15][15];
int visit[15];
int n, k;
int sum;
void dfs(int start, int num)
{
    for(int i=1; i<=n; i++)//这里考虑列，把所以列全都遍历一遍。
    {
        if(visit[i]==0 && st[start][i]=='#')
        {
            if(num==1)
                {sum++;}
            else
            {
                visit[i] = 1;//因为行是递增放的，所以无需考虑在同一行的情况，
                              //只需考虑是否在同一列即可。
                for(int j=start+1; j<=n-num+2; j++)//接着可以放的行的地方，应该是从
                                                   //start+1，到n-num+2；
                {
                    dfs(j, num-1);
                }
                visit[i] = 0;//还要注意修改标记后递归回来要及时复原
            }
        }
    }
}
 
int main()
{
 
    while(~scanf("%d%d", &n, &k)&&(n!=-1)&&k!=-1)
    {
        memset(st, 0, sizeof(st));
 
        for(int i=1; i<=n; i++)
        {
            scanf("%s", st[i]+1);//这样就能使其从零开始。
        }
        sum = 0;
        memset(visit, 0, sizeof(visit));
        for(int i=1; i<=n-k+1; i++) //这里我们考虑行，现考虑第一个可以放在第几行
        {
            dfs(i, k);
        }
        printf("%d\n", sum);
    }
    return 0;
}