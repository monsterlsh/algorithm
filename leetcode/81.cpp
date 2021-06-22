
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return false;
        int i = 0, j = nums.size() - 1;
        int mid = (i + j) / 2;
        while (i < j)
        {
            mid = (i + j) / 2;
            if (target == nums[mid])
                return true;
            if (nums[mid] < nums[j])
            {
                if (target > nums[mid])
                {
                    i = mid;
                    break;
                }
                else {
                    j=mid;
                }
            }else {
                
            }
        }
    }
};