#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
#include<climits>
using namespace std;

long long mins=LONG_MAX;
int ns;
void bfs( vector<vector<int>>&res,int c,long long sum,vector<bool>&vs,int idx){
    
    if(idx == ns){
        if(sum < mins) mins =sum;
        return;
    }
    
        for(int i=c+1;i<=ns;i++){
            if(!vs[i] && res[c][i]>0){
                vs[i]=1;
                bfs(res,i,sum+res[c][i],vs,idx+1);
                vs[i]=0;
            }
        }
    
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t, v,v1,v2,len;
    long long sum=0;
    scanf("%d %d", &v, &t);
    vector<vector<int>>maps(t+1,vector<int>(t+1,0));
    vector<bool>vs(t+1,0);
    ns = v;
    while (t--)
    {
        scanf("%d %d %d",&v1,&v2,&len);
        maps[v1][v2]=maps[v2][v1]=len;
    }
    for(int i=1;i<=v;i++){
        if(!vs[i]){
            vs[i]=1;
        bfs(maps,i,sum,vs,1);
        vs[i]=0;
        }
    }
    
    cout<<mins<<endl;
    return 0;
}