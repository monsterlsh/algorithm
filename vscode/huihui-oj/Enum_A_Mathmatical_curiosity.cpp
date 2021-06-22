#include<iostream>
#include<cmath>
using namespace std;
int find_num(int n,int m);
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t,cases=0,n,m;
    scanf("%d",&t);
    while(t--){

        cases = 0;
        while(scanf("%d %d",&n,&m)&& (n||m)){
            cases++;
            int x = find_num(n,m);
            printf("Case %d: %d\n",cases,x);
        }
        if(t)cout<<endl;
    }
}
int find_num(int n,int m){
    if(n<=2)return 0;
    int b ,a,sum=0;

    /*for(;b<n;b++){
        for(a=1;a<b;a++)*/
    for(a=1;a<n;a++){
        for(b=a+1;b<n;b++){
            int x = (a*a+b*b+m)%(a*b);
            //cout<<"[n,m] = "<<n<<","<<m<<"  [a,b]="<<a<<","<<b<<"  x="<<x<<endl;
            //if(abs(round(x)-x)<0.000000000001)sum++;
            if(x==0)sum++;
        }
    }
    return sum;
}