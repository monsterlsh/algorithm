#include<stdio.h>
#include<string.h>
int ans[101][101];//�洢��ǰλ���ܵõ������Ž�
int map[101][101];//�洢��ǰλ�õ�Ԫ��ֵ
int dir[4][2]={1,0,0,1,-1,0,0,-1};//�ĸ������ң��ϣ�����
int N,M;
int max(int a,int b)
{
	return a>b?a:b;
}
int dp(int i,int j)//�õ�[i,j]λ�õ����Ž�
{
	if(ans[i][j]>0) return ans[i][j];
	//Ѱ���ĸ�����ľֲ�����Ҫ������Ž�
	int t,tempi,tempj;
	int maxn=0;
	for(t=0;t<4;t++)
	{
		tempi=i+dir[t][0];
		tempj=j+dir[t][1];
		if(tempi>0&&tempi<=N&&tempj>0&&tempj<=M) //����Խ��
		{
			if(map[tempi][tempj]<map[i][j])//����[i,j]
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
				ans[i][j]=dp(i,j);//�õ�[i,j]λ�õ����Ž�
				answer=max(answer,ans[i][j]);//�����������Ž�
			}
		}
		printf("%d\n",answer);
	}
	return 0;
}
