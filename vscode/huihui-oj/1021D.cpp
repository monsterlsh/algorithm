// http://39.98.39.23/problem.php?cid=1021&pid=3

#include <iostream>
#include <vector>
using namespace std;
void backtrace(vector<int> &res, vector<int> &ans, int i)
{

    if (ans.size() < 6)
    {
        ans.emplace_back(res[i]);
        if (ans.size() >= 6)
        {
            for (int j = 0; j < 6; j++)
                cout << ans[j] << (j == 5 ? "\n" : " ");
            ans.pop_back();
            return;
        }
        for (int j = i + 1; j < res.size(); j++)
        {
            backtrace(res, ans, j);
            if (ans.size() >= 6)
                break;
        }
        ans.pop_back();
    }
}
int main()
{
    int n;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (cin >> n && n)
    {
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            cin >> res[i];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            backtrace(res, ans, i);
        cout << endl;
    }
}