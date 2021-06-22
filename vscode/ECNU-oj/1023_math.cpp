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
vector<ll> res;
vector<string> ans;
void dp2(ll n, string &str);
void dp(ll n);
void dp3(ll n);
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
        double x = log(n) / log(2);
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
            //dp3(n);
        }
    }
}

//dp2超时 或许不该用insert
void dp2(ll n, string &str)
{
    while (n > 0)
    {
        if (n == 1)
            break;
        ll x = 1;
        //ll nx = pow_quick(2, x);
        ll nx = 2;
        if (nx == n)
        {
            //tmp = to_string(pow_quick(3, x - 1))+",";
            //str.insert(0,to_string(pow_quick(3, x - 1))+",");
            str += to_string(pow_quick(3, x - 1)) + ",";
            break;
        }
        while (nx < n)
        {
            x++;
            //if(!flag)
            //nx = pow_quick(2, x);
            nx *= 2;
            //else x = pow(2,index)-2;
        }
        x--;
        ll pow3ex = pow_quick(3, x);
        if (nx == n)
        {
            //bug
            while (x > 0){
        
                str += to_string(pow3ex) + ",";
                pow3ex /= 3;
                x--;
            }
            str +="1,";
            //str.insert(0,to_string(pow_quick(3, x ))+","); 
            //cout << "index:" << x << " " << res.back() << " x:" << nx << " n:" << n << endl;
            break;
        }

        //str.insert(0,to_string(pow_quick(3, x))+",");
        str += to_string(pow3ex) + ",";
        //cout << "index:" << x << " " << res.back() << " x:" << nx << " n:" << n << endl;
        n -= nx>>1;
    }
    str = str.substr(0, str.length() - 1);
    //printf("[%s]: ", str.c_str());
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
//dp 和 dp3 内存288.04 要求是256
void dp(ll n)
{
    vector<ll>().swap(res);
    while (n > 0)
    {
        if (n == 1)
            break;
        ll x = 1;
        ll nx = pow_quick(2, x);
        if (nx == n)
        {
            res.emplace_back(pow_quick(3, x - 1));
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

            while (x >= 0)
                res.emplace_back(pow_quick(3, x));
            //cout << "index:" << x << " " << res.back() << " x:" << nx << " n:" << n << endl;
            break;
        }

        res.emplace_back(pow_quick(3, x));
        //cout << "index:" << x << " " << res.back() << " x:" << nx << " n:" << n << endl;
        n -= powl(2, x);
    }
    printf("%s", "{");
    for (int i = res.size() - 1; i >= 0; i--)
    {
        printf("%lld%s", res[i], i == 0 ? "" : ",");
    }
    printf("%s", "}\n");
}
void dp3(ll n)
{
    vector<string>().swap(ans);
    while (n > 0)
    {
        if (n == 1)
            break;
        ll x = 1;
        ll nx = pow_quick(2, x);
        if (nx == n)
        {

            ans.emplace_back(to_string(pow_quick(3, x - 1)));
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

            while (x >= 0)
                ans.emplace_back(to_string(pow_quick(3, x)));
            //cout << "index:" << x << " " << res.back() << " x:" << nx << " n:" << n << endl;
            break;
        }

        ans.emplace_back(to_string(pow_quick(3, x)));
        //cout << "index:" << x << " " << res.back() << " x:" << nx << " n:" << n << endl;
        n -= powl(2, x);
    }
    printf("%s", "{");
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        printf("%s%s", ans[i].c_str(), i == 0 ? "" : ",");
    }
    printf("%s", "}\n");
}