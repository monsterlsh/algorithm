#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0||prices.size()==1)return 0;
        int maxs,mins,i=0,sum=0;
        while(i<prices.size()-1){
            if(prices[i+1]<=prices[i]){i++; if(i==prices.size()-1)return sum; }
            else break;
           
        }
        mins = prices[i];maxs=mins;
        while(++i<prices.size()){
            //cout<<prices[i]<<endl;
            if(prices[i]>maxs){maxs=prices[i];sum += i==prices.size()-1?maxs-mins:0;}
            else {
                sum+=maxs-mins;
                while(i<prices.size()-1){
                    if(prices[i+1]<=prices[i]){i++; if(i==prices.size()-1)return sum; }
                    else break;
                }
                mins=prices[i];maxs=mins;
            }
        }
        return sum;
    }
};

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);

    vector<int>ans{7,1,5,3,6,4};
    Solution a;
    cout<<a.maxProfit(ans);
}