#include<stdio.h>
#include<string.h>
int ans[101][101];//存储当前位置能得到的最优解
int map[101][101];//存储当前位置的元素值
int dir[4][2]={1,0,0,1,-1,0,0,-1};//四个方向，右，上，左，下
int N,M;
int max(int a,int b)
{
	return a>b?a:b;
}
int dp(int i,int j)//得到[i,j]位置的最优解
{
	if(ans[i][j]>0) return ans[i][j];
	//寻找四个方向的局部满足要求的最优解
	int t,tempi,tempj;
	int maxn=0;
	for(t=0;t<4;t++)
	{
		tempi=i+dir[t][0];
		tempj=j+dir[t][1];
		if(tempi>0&&tempi<=N&&tempj>0&&tempj<=M) //不可越界
		{
			if(map[tempi][tempj]<map[i][j])//低于[i,j]
				maxn=max(maxn,dp(tempi,tempj));
		}
	}
	return ans[i][j]=maxn+1;
}
int main()
{
	while(~scanf("%d%d",&N,&M))
	{
		int answer=0;
		int i,j;
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		memset(ans,0,sizeof(ans));
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=M;j++)
			{
				ans[i][j]=dp(i,j);//得到[i,j]位置的最优解
				answer=max(answer,ans[i][j]);//更新整体最优解
			}
		}
		printf("%d\n",answer);
	}
	return 0;
}
