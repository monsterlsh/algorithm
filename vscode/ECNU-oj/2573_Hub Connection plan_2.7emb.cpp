#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;
struct edge
{
   int v1,v2,len;
};
bool cmp(const edge & a,const edge & b){
   return a.len<b.len;
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t, v,v1,v2,sum=0;
    scanf("%d %d", &v, &t);
    vector<edge>maps(t);
    set<int>vs;
    while (t--)
    {
        scanf("%d %d %d",&maps[t].v1,&maps[t].v2,&maps[t].len);
    }
    sort(maps.begin(),maps.end(),cmp);
    for(int i=0;i<maps.size();i++){
        if(vs.find(maps[i].v1)==vs.end() || vs.find(maps[i].v2)==vs.end() ){
            sum += maps[i].len;
            vs.insert(maps[i].v1);
            vs.insert(maps[i].v2);
            if(vs.size()==v)break;
        }
    }
    cout<<sum<<endl;
    return 0;
}