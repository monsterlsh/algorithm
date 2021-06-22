#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int i = 0, j = 0;
        do
        {
            while (i < pushed.size())
            {
                s.push(pushed[i++]);
                while (!s.empty() && s.top() == popped[j])
                {
                    j++;
                    s.pop();
                }
            }
            if (i == pushed.size() && !s.empty())
                return false;
        } while (j < popped.size());

        return true;
    }
};
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    Solution s ;
    while (scanf("%d", &n) && n)
    {
        vector<int> in(n);
        for (int i = 1; i <=n; i++)
        {
            in[i-1]=i;
        }
        vector<int>out(n);
        for (int i = 0; i <n; i++)
        {
            scanf("%d",&out[i]);
        }
        bool flag = s.validateStackSequences(in,out);
        if(!flag){printf("No\n");}
        else if(flag) printf("Yes\n");
    }
}