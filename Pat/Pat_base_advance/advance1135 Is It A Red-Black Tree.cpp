#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool flag = true;
vector<int>tree;
int pre(vector<int>&res,int l,int r,int blc){
    if(l<=r && flag){
        int mid =l+1;
        int black=blc;
        if(res[l]<0){
            black++;
            if(l+1<res.size() && res[l+1]<0)flag=false;
        }
        while(mid<=r && abs(res[mid])<res[l]){
            mid++;
            //if(res[mid]<0)black++;
        }
        int lb = pre(res,l+1,mid-1,black);
        if(flag)tree.emplace_back(abs(res[l]));
        cout<<" "<<l<<":"<<res[l]<<"  ";
        if(l==r && res[l]<0){
            flag = false;
        }
        int rb = pre(res,mid,r,black);
        if(lb!=rb)flag = false;
        return lb;
    }
    else return blc;
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int k,n;
    
    cin>>k;
    while(k--){
        cin>>n;
       vector<int>res(n);
        for(int i=0;i<n;i++) cin>>res[i];
        if(res[0]<0)flag=false;
        
        if(flag){
            pre(res,0,n-1,0);
            for(int i=0;i<n-1 && flag;i++){
                if(tree[i]>tree[i+1]) flag= false;
            }
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
        flag = true;
    }
}