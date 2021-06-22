#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    long long int L;
    int n;
    while(scanf("%lld%d",&L,&n)!=EOF)
    {
        long long int len[610]={0},sum=0;
        for(int i=0; i<n; i++){
            scanf("%lld",&len[i]);
            sum+=len[i];
        }
        if(sum<L)
        {
            printf("impossible\n");
            break;
        }
        sort(len,len+n,cmp);
        int cnt=0,t;
        for(int i=0; i<=n; i++)
        {
            if(L>0)
            {
                L-=len[i];
                cnt++;
            }
            else
            {
                printf("%d\n",cnt);
                break;
            }
        }
    }
    return 0;
}