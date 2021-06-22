#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin>>n;
    vector<int>pre(n);
    vector<int>in(n);
    for(int i=0;i<n;i++)cin>>pre[i];
    for(int i=0;i<n;i++)cin>>in[i];
    int inroot = 0,inend=n-1,preroot=0,preend=n-1;
    while (true)
    {
        int i=inroot,first=inroot;bool flag=true;
       for(;i<=inend;i++){
            if(pre[preroot]==in[i]){
                if(i==inroot){inroot=i+1;flag=false;}
                else inroot=i;
                 break;
            }
        }
        if(inroot==inend+1){
            cout<<in[inend];
            break;
        }
        preend = preroot+inroot-first;
        if(flag){
            inend = inroot-1;
            }
        
        preroot++;
       // inend = inroot-1;

    }
    
    
}