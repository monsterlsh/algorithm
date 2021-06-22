#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,m;
    
    while(scanf("%d %d",&n,&m)!=EOF){
        unordered_map<int,int>ans;
        vector<int>res(n+1);
        for(int i=1;i<=n;i++){
            int tmp;
            scanf("%d",&tmp);
            ans[tmp]++;
            res[i]=tmp;
        }
         for(int i=1;i<=n;i++){
             if(ans[res[i]]>1)printf("%d\n",ans[res[i]]-1);
             else printf("BeiJu\n");
         }
       
    }
}