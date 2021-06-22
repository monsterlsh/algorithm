#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <cstring>
#include<cmath>
using namespace std;
 typedef unsigned long long ll;
string BigMul(string s,string t){
   int sum[10005] = {0},a[10005],b[10005],tmp,extra,i,j,start,length1,length2;
   char goal[10005];
   reverse(s.begin(),s.end());
   reverse(t.begin(),t.end());
   length1 = s.length();
   length2 = t.length();
   for(i = 0;i < length1;i++){
        a[i] = (int)(s[i] - '0');
   }
   for(i = 0;i < length2;i++){
        b[i] = (int)(t[i] - '0');
   }
   for(i = 0;i < length1;i++){
        start = i;
        for(j = 0;j < length2;j++){
            sum[start] += a[i]*b[j];
            start ++;
        }
   }
   for(i = 0;i < start;i++){
        sum[i + 1] += sum[i] / 10;
        sum[i] = sum[i] % 10;
   }
    while(sum[i] == 0){
        i --;
    }
    start = 0;
   for(j = i ;j >= 0;j--){
        goal[start] = (char)(sum[j] + '0');
        start ++;
   }
   goal[start] = '\0';
   return (string)goal;
}
 string pow_quick(string n, ll ex)
{
    string sum = "1";
    while (ex != 0)
    {
        if (ex & 1 != 0)
        {
            sum = BigMul(n,sum);
        }
        n = BigMul(n,n);
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
            str += pow_quick("3", x - 1) + ",";
            break;
        }
        while (nx < n)
        {
            x++;
            nx *= 2;
        }
        x--;
        string pow3ex = pow_quick("3", x);
        if (nx == n)
        {
            while (x > 0){
        
                str += pow3ex + ",";
                x--;
                pow3ex =pow_quick("3",x);

            }
            str +="1,";
            break;
        }
        str += pow3ex + ",";
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
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    ll n;
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
                cout << pow_quick("3", i) << (i != ex - 1 ? "," : "");
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