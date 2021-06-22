#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution{
    public:
        void movearray(vector<int>&arr,int k){
        if(arr.size()==0 || arr.size()==1|| k%arr.size()==0)return;
        int n = arr.size();
        k = k%n;
        reverse(arr,0,n-1);
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);

    }
        void reverse(vector<int>&arr,int i,int j){
            int len =0;
            for(int k =i;k<=(j+i)/2;k++,len++){
                int tmp = arr[k];
                arr[k] = arr[j-len];
                arr[j-len]=tmp;
            }
        }
};
int main(){
     freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    Solution s;
    int n;
    while(scanf("%d",&n)!=EOF){
       vector<int>arr(n);
       for(int i=0;i<n;i++){
           scanf("%d",&arr[i]);
       }
       int k;
       scanf("%d",&k);
       s.movearray(arr,k);
       for(int i=0;i<n;i++){
           if(i!=n-1)
           printf("%d ",arr[i]);
           else printf("%d\n",arr[i]);
       }

    }
}