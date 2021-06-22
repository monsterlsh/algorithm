#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
ll n;
vector<vector<ll>>res;
void printf_format(vector<vector<ll>>&res,ll n){
    printf("{");
    for(int i=0;i<res[n].size();i++){
        printf("%lld%s",res[n][i],i!=res[n].size()-1?",":"");
    }
    printf("}\n");
}
void dfs(vector<vector<ll>>&res,ll lastnum,int n,ll  nextnum){
    /*if(res.back().size()>=lastnum+1){
        nextnum *=3;
        dfs(res,lastnum+1,n,nextnum);
        return;
    }*/
    vector<ll>tmp;
    int x=res.size();
    for(int i=0;i<x;i++){
        
        tmp.assign(res[i].begin(),res[i].end());
        tmp.emplace_back(nextnum);
        res.emplace_back(tmp);
        vector<ll>().swap(tmp);
        /*cout<<"["<<lastnum<<": ]";
        printf_format(res,res.size()-1);*/
    }
    if(res.size()<n){
        nextnum *=3;
        dfs(res,lastnum+1,n,nextnum);
    }
}
void dfs2(vector<vector<ll>>&res,int n,ll nextnum){
    vector<ll>tmp;
    int x=res.size();
    for(int i=0;i<x;i++){
        tmp.assign(res[i].begin(),res[i].end());
        tmp.emplace_back(nextnum);
        res.emplace_back(tmp);
        vector<ll>().swap(tmp);
        /*cout<<"["<<lastnum<<": ]";
        printf_format(res,res.size()-1);*/
    }
    if(res.size()<n){
        nextnum *=3;
        dfs2(res,n,nextnum);
    }
}

int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    vector<ll>tmp;
    ll maxs = 0;
    res.emplace_back(tmp);
    tmp.emplace_back(1);
    res.emplace_back(tmp);
    //printf_format(res,0);
    tmp.pop_back();
    while( scanf("%lld",&n) && n){
        tmp.emplace_back(n);
        if(maxs < n)maxs = n;
        /*if(n<=res.size()) printf_format(res,n-1);
        else {
            ll lastnum = res.back().size();
            ll nextnum = pow(3,lastnum);
            dfs(res,lastnum,n,nextnum);
            printf_format(res,n-1);
        }*/
        
    }
    dfs2(res,maxs,3);
    for(int i=0;i<tmp.size();i++){
        printf_format(res,tmp[i]-1);
    }
   /* n=1125900981634049;
    dfs(res,1,n,3);
    printf_format(res,n-1);*/
   
}
