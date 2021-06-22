#include<stdio.h>
int main()
{
    freopen("ac.in", "r", stdin);
    freopen("ac.out", "w", stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,d=1;
		while(scanf("%d%d",&n,&m),n||m)
		{
		    int cnt=0;
			int a,b;
			printf("Case %d: ",d++);//改到崩溃了才发现，冒号与结果之间有空格，真是跪了。 
			for(a=1;a<n;a++)
			{
				for(b=a+1;b<n;b++)
				{
					if((a*a+b*b+m)%(a*b)==0)//整除的判断，取余为0； 
					  cnt++;
				}
			}
			printf("%d\n",cnt);
		}
	     if(t)
		  printf("\n");
	}
	return 0;
}