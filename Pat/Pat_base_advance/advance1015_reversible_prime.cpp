#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n<2)return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
int exchange(int x,int radix){
    string res="";
    int i=0,n=0;
    while(x){
        res+=x%radix+'0';
        x/=radix;
    }
    while(i<res.length()){
        n*=radix;
        n += res[i++]-'0';
    }
    return n;
}
int main(){
    int n,ex,radix;
    bool flg1,flg2;
    while(cin>>n && n>0){
        flg1=isPrime(n);
        cin>>radix;
        ex=exchange(n,radix);
        flg2=isPrime(ex);
        if(flg1&&flg2) cout<<"Yes\n";
        else cout<<"No\n";
    }
}