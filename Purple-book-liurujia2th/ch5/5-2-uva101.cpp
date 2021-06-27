#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define RE
size_t n;
vector<vector<size_t>>blocks;
 map<size_t,pair<size_t,size_t>> index;
 size_t a, b;
 void returning(){
     
 }
void moves(size_t ins){
    size_t ax,ay,bx,by;
    ax = index[a].first,ay=index[a].second;
    bx = index[b].first,by=index[b].second;
    switch (ins)
    {
        //move a onto b
        //将a和b所在上方的方块先归位，再将a移到b所在柱子
    case 1:

        blocks[bx].insert(blocks[bx].begin()+by,blocks[ax][ay]);
        blocks[ax].erase(blocks[ax].begin()+ay);
        break;
        //move a over b 仅将a所在上方的方块先归位，再将a移到b所在柱子
    case 2:
        blocks[bx].insert(blocks[bx].begin()+by,blocks[ax].begin()+ay,blocks[ax].end());
        blocks[ax].erase(blocks[ax].begin()+ay,blocks[ax].end());
        break;
//将b所在上方的方块先归位，再将a及其上方的所有方块移到b所在柱子
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    default:
        break;
    }
}
void slove(){
    blocks.clear();
    index.clear();
    string ir;
    size_t ins=0;
    a=0;
    while(a<n){
        blocks.emplace_back(vector<size_t>(0));
        blocks[a].emplace_back(a);
        index[a]={a,a};
        a++;
    }
    while(cin>>ir && ir!="quit"){
        ins = ir=="move"?0:1;
        cin>>ir; a = atoll(ir.c_str());
        cin>>ir; ins += ir=="onto"?1:2;
        cin>>ir; b = atoll(ir.c_str());
        moves(ins);
    }
}
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    while(scanf("%zd",&n)!=EOF){

    }
}
