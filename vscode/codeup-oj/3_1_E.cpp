//http://codeup.hustoj.com/problem.php?cid=100000575&pid=4
#include <cstdio>
int main()
{
	int circle[100000],distance[100000];
	distance[1]=0;
	int n,m,sum=0;
	scanf("%d",&n);	
	int b,e,low,high,dis1,dis2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&circle[i]);
		sum+=circle[i];
		distance[i+1]=distance[i]+circle[i];
	}
	scanf("%d",&m);
	for(int j=0;j<m;j++)
	{
		scanf("%d%d",&b,&e);
		low=(b<e?b:e);
		high=(b>e?b:e);
		dis1=distance[high]-distance[low];
		dis2=sum-dis1;
		if(dis1<dis2)
			printf("%d\n",dis1);
		else
			printf("%d\n",dis2);
	}
	return 0;
}