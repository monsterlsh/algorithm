#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000+5;

int n,m;
int dp[maxn][maxn];
char s1[maxn],s2[maxn];

int main()
{
    while(scanf("%s%s",s1,s2)==2)
    {
        n=strlen(s1);//s1串长度
        m=strlen(s2);//s2串长度
        memset(dp,0,sizeof(dp));

        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max( dp[i-1][j] , dp[i][j-1] );
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
