#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
 
#pragma comment(linker, "/STACK:1024000000");
#define LL long long int
#define ULL unsigned long long int
#define _LL __int64
#define _INF 0x3f3f3f3f
#define INF 1000000
#define Mod 1000000009
 
using namespace std;
 
int dp[901][8101];
 
int a[10];
 
int num[910];
 
int Top;
 
void Output(int l,int r)
{
    if(l == 0 && r == 0)
        return ;
 
    for(int i = 1;i <= 9; ++i)
    {
        if(dp[l-i][r-a[i]] == dp[l][r]-1)
        {
            num[Top++] = i;
            Output(l-i,r-a[i]);
            return ;
        }
    }
}
 
int main()
{
    int l,r;
 
    int t,i,j,k;
 
    for(i = 1;i <= 9; ++i)
        a[i] = i*i;
 
    memset(dp,INF,sizeof(dp));
 
    dp[0][0] = 0;
 
 
    for(i = 1;i <= 9; ++i)
    {
        for(j = i;j <= 900; ++j)
        {
            for(k = a[i];k <= 8100; ++k)
            {
                dp[j][k] = min(dp[j][k],dp[j-i][k-a[i]]+1);
            }
        }
    }
 
    scanf("%d",&t);
 
    while(t--)
    {
        scanf("%d %d",&l,&r);
 
        if(l > r || l > 900 || r > 8100)
        {
            printf("No solution\n");
        }
        else
        {
            if(dp[l][r]  == -1 || dp[l][r] > 100)
            {
                printf("No solution\n");
            }
            else
            {
                Top = 0;
                Output(l,r);
 
                sort(num,num+Top);
 
                for(i = 0;i < Top; ++i)
                {
                    printf("%d",num[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}