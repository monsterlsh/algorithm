#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
//typedef unsigned long long ll;
string BigMul(string s, string t)
{
    int sum[10005] = {0}, a[10005], b[10005], tmp, extra, i, j, start, length1, length2;
    char goal[10005];
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    length1 = s.length();
    length2 = t.length();
    for (i = 0; i < length1; i++)
    {
        a[i] = (int)(s[i] - '0');
    }
    for (i = 0; i < length2; i++)
    {
        b[i] = (int)(t[i] - '0');
    }
    for (i = 0; i < length1; i++)
    {
        start = i;
        for (j = 0; j < length2; j++)
        {
            sum[start] += a[i] * b[j];
            start++;
        }
    }
    for (i = 0; i < start; i++)
    {
        sum[i + 1] += sum[i] / 10;
        sum[i] = sum[i] % 10;
    }
    while (sum[i] == 0)
    {
        i--;
    }
    start = 0;
    for (j = i; j >= 0; j--)
    {
        goal[start] = (char)(sum[j] + '0');
        start++;
    }
    goal[start] = '\0';
    return (string)goal;
}
string add(string a, string b)
{
    string ans;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int ch = 0;
    while (i >= 0 && j >= 0) 
    {
        int x = a[i--] + b[j--] + ch - '0' - '0';
        ans += x % 10 + '0';
        ch = x / 10;
    }
    while (i >= 0)
    {
        int x = a[i] + ch - '0';
        ans += x % 10 + '0';
        ch = x / 10;
    }
    i = j;
    while (i >= 0)
    {
        int x = a[i] + ch - '0';
        ans += x % 10 + '0';
        ch = x / 10;
    }
    if (ch)
        ans += ch + '0';
    return ans;
}
string out(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    int weishu = 1;
    while (weishu * 9 < n)
        weishu++;
    weishu--;
    string str(weishu, '9');
    if (weishu * 9 != n)
        str += n - weishu * 9 + '0';
    vector<string> res;
    res.emplace_back(str);
    int x = 1, i = 0, ixx = 0,tianjia=9;
    while (res.size() < n)
    {
        while (i <= ixx)
        {
            while (x <= str.length() - 1 && res.size() < n)
            {
                string tmp = str;

                while (tmp[i] < '9' && tmp[i + x] >= '1' && i +x < n  && res.size() < n)
                {
                    tmp[i]++;
                    tmp[i + x]--;
                    res.emplace_back(tmp);
                    cout<<tmp;
                }
                x++;
            }
            i++;
        }

        x = 1;
        if(tianjia==9)
            {str += "1";ixx++; str[1]--;tianjia =1;}
        else{
            str[0]++;
            tianjia++;
        }
       
        if (res.size() < n)
            res.emplace_back(str);
        i = 0;
    }
    string ans = res[0];
    for(int i=1;i<res.size();i++){
        ans = add(ans,res[1]);
    }
    return ans;
}
int main()
{
    cin >> n;
    cout<<out(n)<<endl;
}