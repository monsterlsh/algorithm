#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k%n==0)return ;
        k = k%n;
        int i=0,idx=i;
      
            int tmp=nums[i],tmpx;
            int x=0;
            while( x++<=0 ||i!=idx){  
                tmpx=nums[(i+k)%n];
                nums[(i+k)%n]=tmp;
                tmp = tmpx;
                i = (i+k)%n;
            }
        
    }
};
int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                   // cout<<dp[i]<<" then is ..";
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                  //  cout<<"[i,j] "<<i<<","<<j<<" = "<<dp[i]<<endl;
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    vector<int >res={2,5,6,7,8};
    int n=11;
    coinChange(res,n);
}