#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
class Solution{
    private: int dp[25];
    public: 
        void fn(){
            dp[0]=0;
            dp[1]=1;
            dp[2]=1;
            for(int i=3;i<=24;i++){
                dp[i] = dp[i-1]+dp[i-2];
            }
        }
        void print(int n){
            
            for(int i=1;i<=n;i++){
                string str(2*(n-i),' ');
                cout<<str;
                for(int j=0;j<2*i-1;j++){
                    printf("%d%s",dp[j],j==2*i-2?"\n":" ");
                }
            }
        }

};
int main(){
     freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    Solution a;
    a.fn();
    int n,k;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        a.print(k);
    }
}