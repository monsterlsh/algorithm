#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int hammingWeight(int n) {
        int sum = 0;
        while(n!=0){
            n/=10;
            sum++;
        }
        return sum;
    }
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t,a,b,sum=0;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d",&a,&b);
       sum=a+b;
       int res=0;
      // if(sum==0){cout<<0<<endl;continue;}
       
      /* while(sum){
           res++;
           sum &= (sum-1);
       }*/
        cout<<hammingWeight(sum)<<endl;
    }
    return 0;
}