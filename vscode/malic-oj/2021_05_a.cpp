#include <iostream>
#include <cctype>
#include <string>
#include<algorithm>
using namespace std;
class Solution
{
private:
    int m, k;
    string num;
    char nums[1001];

public:
    void init()
    {
        scanf("%d %d", &m, &k);
        scanf("%s", nums);
        num = nums;

        string numto10 = changeto10(m);
        pair<string,int>res ;
        string kres="";
        while(true){
             res = large_number_devision(numto10,k);
             numto10 = res.first;
             if(res.second<10)kres+=to_string(res.second);
             else kres += res.second-10+'A';
             if(numto10.empty())break;
        }
        printf("%s",kres.c_str());
        
    }
    pair<string,int> large_number_devision(string dividend, int divisor)
    {
        string result;
        int shang, remainder = 0;
        for (int i = 0; i < dividend.size(); i++)
        {
            shang = (remainder * 10 + (dividend[i] - '0')) / divisor;
            remainder = (remainder * 10 + dividend[i] - '0') % divisor;
            result.push_back(char(shang + '0'));
        }
        while (1)
        {
            if(result.size()==0)break;
            if (result[0] == '0')
                result.erase(result.begin(), result.begin() + 1);
            if (result[0] != '0')
                break;
        }
        return {result,remainder};
    }

    string changeto10(int mx)
    {
        string radix = to_string(mx);
        string res = "";
        int ch = 0;
        string a = "", b = "", sum = "", c;
        for (int i = num.length() - 1; i >= 0; i--)
        {
            int tmp = isdigit(num[i]) ? num[i] - '0' : num[i] - 'A' + 10;
            a = to_string(tmp);
            b = pow_quick(radix, ch++);
            c = BigMul(a, b);
            sum = BigAdd(sum, c);
        }
        return sum;
    }

    string pow_quick(string n, int ex)
    {
        //if(ex==0)return "0";
        string sum = "1";
        while (ex != 0)
        {
            if (ex & 1 != 0)
            {
                sum = BigMul(n, sum);
            }
            n = BigMul(n, n);
            ex >>= 1;
        }
        return sum;
    }
    string BigAdd(string s, string t)
    {
        int ch = 0;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int i = 0, j = 0;
        string str = "";
        while (i < s.length() && j < t.length())
        {
            int x = s[i] + s[j] - '0' - '0' + ch;
            ch = x / 10;
            int mol = x % 10;
            str += to_string(mol);
        }
        while (i < s.length())
        {
            int x = s[i] - '0' + ch;
            ch = x / 10;
            int mol = x % 10;
            str += to_string(mol);
        }
        i = j;
        while (i < s.length())
        {
            int x = s[i] - '0' + ch;
            ch = x / 10;
            int mol = x % 10;
            str += to_string(mol);
        }
        if (ch)
            str += to_string(ch);
        reverse(str.begin(), str.end());
        return str;
    }
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
};
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    Solution a;
    a.init();
}