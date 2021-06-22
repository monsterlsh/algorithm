#include <stdio.h>
int main()
{
    long long ans[1000001]={0};
    int i, j, n;
    ans[0]=1;
    ans[1]=1;
    for(i=2; i<1000001; i++)
    {
        if(i%2) ans[i]=ans[i-1];
        else ans[i]=(ans[i-1]+ans[i/2])%1000000000;
    }
    scanf("%d",&n);
    for(i=0; i<n; i++) 
    {
        scanf("%d",&j);
        printf("case #%d:\n%lld\n",i,ans[j]);
    }
    return 0;
}
