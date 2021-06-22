#include<iostream>
using namespace std;
int n;
 int dp[21]={0};

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=20;i++){
        dp[i] = dp[i-2]+dp[i-1];
    }
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",dp[n]);
    }
}