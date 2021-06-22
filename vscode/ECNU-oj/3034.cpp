/**
 * https://acm.ecnu.edu.cn/problem/3034/
 * 单点时限: 2.0 sec

内存限制: 256 MB

将一个正整数拆分为成  的幂的和，例如：


总共有六种不同的拆分方案。

再比如： 可以拆分成：，，，。

函数  表示  的不同拆分的方案数，例如 。

请编写程序，读入一个正整数  ()，输出 。

输入格式
第  行：一个整数  () 为问题数。

接下来  行，每行输入一个正整数 。

输出格式
对于每个问题，输出一行问题的编号（ 开始编号，格式：case #0: 等）。

然后对应每个问题在一行中输出 。
 * 
 */
//2021年3月6日13:54:54
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int f(int n);
string add(string a, string b);

int f(int n)
{
    return 0;
}
string add(string a, string b)
{
    int i = a.length() - 1;
    int j = b.length() - 1;
    int ch = 0, shang = 0;
    //int n = max(i, j);
    string res = "";
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] - '0'-'0' + ch;
        ch = sum / 10;
        shang = sum % 10;
        res += shang + '0';
        i--;
        j--;
    }

    while (i >= 0 && ch != 0)
    {
        int sum= (a[i] + ch - '0') ;
        ch = sum / 10;
        res += sum % 10 + '0';
        i--;
    }
    while (i >= 0) 
        res += a[i--];
    i = j;
    while (i >= 0 && ch != 0)
    {
        int sum= (b[i] + ch - '0') ;
        ch = sum / 10;
        res += sum % 10 + '0';
        i--;
    }
    while (i >= 0)
        res += b[i--];
    if(ch)res+=ch+'0';
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    scanf("%d", &t);
    int casenum = 0;
    vector<string> ans(1000001,"0");
    int i = 2;
    ans[0] = "1";
    ans[1] = "1";
    for (; i < 1000001; i++)
    {
        if (i % 2)
            ans[i] = ans[i - 1];
        else
            ans[i] = add(ans[i - 1] , ans[i / 2]);
    }
    while (t--)
    {
        int n;
        scanf("%d", &n);
        const char *ch = ans[n].c_str();
        printf("case #%d:\n%s\n", casenum++, ch);
    }
    return 0;
}