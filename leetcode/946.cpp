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
                    //break;
                }
            }
            if(i==pushed.size()&&!s.empty())return false;

        } while (j < popped.size());

        return true;
    }
};