
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t,k,th;
    scanf("%d",&t);
    vector<int>res(t+1);
    for(int i=1;i<=t;i++) scanf("%d",&res[i]);
    int casenum = 0;
    sort(res.begin(),res.end());
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&th);
        cout<<res[th]<<endl;
    }
    return 0;
}