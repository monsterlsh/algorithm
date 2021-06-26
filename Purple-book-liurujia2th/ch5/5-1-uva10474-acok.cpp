#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
#define RE

size_t n,q,num,i;
void solve(){
    size_t nn=n;
    vector<size_t>all;
    while(nn--){
        scanf("%zd",&num);
        all.emplace_back(num);
    }
    sort(all.begin(),all.end());
    
    while(q--){
        i=0;
        scanf("%zd",&num);
        printf("%zd ",num);
        for(;i<all.size()&&all[i]!=num;i++);
        if(i==all.size()) printf("not found\n");
        else printf("found at %zd\n",i+1);
    }
    //all.clear();
}
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    size_t kase=0;
    while(scanf("%zd %zd",&n,&q)==2 && n && q){
        printf("CASE# %zd:\n",++kase);
        solve();
    }

}
