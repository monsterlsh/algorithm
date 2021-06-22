#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef unsigned long long ll;
ll n;

ll pow_quick(ll n, ll ex)
{
    ll sum = 1;
    while (ex != 0)
    {
        if (ex & 1 != 0)
        {
            sum *= n;
        }
        n *= n;
        ex >>= 1;
    }
    return sum;
}
void dp2(ll n, string &str)
{
    while (n > 0)
    {
        if (n == 1)
            break;
        ll x = 1;
        //ll nx = pow_quick(2, x); x是指数 nx=2^x
        ll nx = 2;
        if (nx == n)
        {
            str += to_string(pow_quick(3, x - 1)) + ",";
            break;
        }
        while (nx < n)
        {
            x++;
            nx *= 2;
        }
        x--;
        ll pow3ex = pow_quick(3, x);
        if (nx == n)
        {
            while (x > 0){
        
                str += to_string(pow3ex) + ",";
                pow3ex /= 3;
                x--;
            }
            str +="1,";
            break;
        }
        str += to_string(pow3ex) + ",";
        n -= nx>>1;
    }
    //结果输出：
    str = str.substr(0, str.length() - 1);
    printf("%s", "{");
    string tmp = "";
    int r = str.length() - 1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == ',')
        {
            tmp = str.substr(i+1, r - i) + ",";
            printf("%s", tmp.c_str());
            r = i - 1;
        }
    }
        tmp = str.substr(0, r+1);
        printf("%s", tmp.c_str());
        printf("%s", "}\n");
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    
    while (scanf("%lld", &n) && n)
    {
        if (n == 1)
        {
            printf("%s", "{}\n");
            continue;
        }
        //当n为2的ex次方时得单独处理
         long double x = log(n) / log(2);
        if (abs(round(x) - x) < 0.000000000000001)
        {
            ll ex = x;
            ll i = 0;
            printf("%s", "{");
            while (i < ex)
            {
                cout << pow_quick(3, i) << (i != ex - 1 ? "," : "");
                i++;
            }
            printf("%s", "}\n");
        }
        else
        {
            string str = "";
            dp2(n, str);
        }
    }
}