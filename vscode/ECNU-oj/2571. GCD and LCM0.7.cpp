#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int lcm(int a,int b){
    if(a==b)return a;
    if(a>b)swap(a,b);
    int ai=a,bi=b;
    while(b !=a){
       
        if(b>a)a += ai;
        if(a>b)b +=bi;
    }
    return a;
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t,a,b;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d",&a,&b);
       cout<<gcd(a,b)<<" "<<lcm(a,b)<<endl;
    }
    return 0;
}