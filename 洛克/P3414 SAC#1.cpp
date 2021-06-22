#include<iostream>
#include<cstring>
#define ull unsigned long long
#define RE
using namespace std;
const ull MOD = 6662333;
ull quick_power(ull a,ull b){
    ull sum=1;
    while(b){
        if(b&1) sum = (sum*a)%MOD;
        b>>=1;
        a = (a*a)%MOD;
    }
    return sum;
}
int main()
{
#ifdef RE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    ull n;
    scanf("%llu",&n);
    cout<<quick_power(2,n-1);
}
