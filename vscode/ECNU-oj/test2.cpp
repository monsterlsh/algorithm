#include<iostream>
#include<cmath>
#include<string>
using namespace std;
typedef unsigned long long ll;
ll  pow_quick(ll n,ll ex){
    ll sum=1;
    while(ex!=0){
        if(ex&1!=0){
            sum *= n;
        }
        n *=n;
        ex >>=1;
    }
    return sum;
}
void dp2(ll n,string &res){
    
    while (n > 0)
    {
        if (n == 1)
            break;
        ll x = 1;
        ll nx = pow_quick(2, x);
        if (nx == n)
        {
            res+=(pow_quick(3, x - 1));
            break;
        }
        while (nx < n)
        {
            x++;
            //if(!flag)
            nx = pow_quick(2, x);
            //else x = pow(2,index)-2;
        }
        x--;
        if (nx == n)
        {
             
             while(x>=0)
            res+=(pow_quick(3, x));
            //cout << "index:" << x << " " << res.back() << " x:" << nx << " n:" << n << endl;
            break;
        }

        res+=(pow_quick(3, x));
        //cout << "index:" << x << " " << res.back() << " x:" << nx << " n:" << n << endl;
        n -= powl(2, x);
    }
     printf("%s","{");
    for(int i =res.size()-1;i>=0;i--){
            printf("%lld%s",res[i],i==0?"":",");
        }
      printf("%s","}\n");
    
}
int main(){
     freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    ll a = 1.2676506002282294e+30;
    string res="ss";
     res.insert(0,to_string(pow_quick(3, 11 - 1)));
   // res.insert(0,"ss");
    cout<<res<<endl;
    printf("ss");
}