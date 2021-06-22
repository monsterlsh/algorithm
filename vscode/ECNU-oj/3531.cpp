#include<iostream>
#include<vector>
using namespace std;

int steps( int n,const int broken[]){
    if(n==0)return 0;
    vector<int>dp(n+1,0);
    if(!broken[1])dp[1]=1;
    if(!broken[1]&&!broken[2])dp[2]=2;
    else if(!broken[2])dp[2]=1;

    if(!broken[1]&&!broken[2]&&!broken[3])dp[3]=4;
    else if(( (broken[1]&&!broken[2] ) || (!broken[1]&&broken[2]) )&&!broken[3])dp[3]=2;
    else if(!broken[3])dp[3]=1;

    for(int i=4;i<=n;i++){
        if(!broken[i])
        for(int j =1;j<=3;j++)
        dp[i] += !broken[i-j]?dp[i-j]:0;
    }
    return dp[n];
}
int main(){
    int n,m,tmp;
    scanf("%d %d",&n,&m);
    int broken[101] ={0};
    for(int i=0;i<m;i++){
        scanf("%d",&tmp);
        broken[tmp]=1;
    }
   // printf("%d\n",n);
    printf("%d",steps(n,broken));
}