#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int>arr(n);
        map<int,map<int,int>> nums;
        map<int,int> res;
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            res[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            int tmp;
            scanf("%d",&tmp);
            nums[tmp][arr[i]]++;

        }
        
      
         auto it = nums.begin();
        
         while(it!=nums.end()){
             printf("%d={",it->first);
             map<int,int>aa = it->second;
             auto x = res.begin();
             while(x!=res.end()){
                 auto i=x;
                printf("%d=%d%s", x->first,aa[x->first],(++i==res.end()?"":","));
                x++;
               
             }
             printf("}\n");
             it++;
         }

    }
}