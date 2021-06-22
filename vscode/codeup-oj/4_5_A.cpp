#include <iostream>

#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

int main()
{

    freopen("in.in", "r", stdin);
    freopen("out.out","w",stdout);
    int n, x;
    while (scanf("%d",&n)!=EOF && n)
    {
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            scanf("%d",&ans[i]);

       scanf("%d",&x);
        int l = 0, r = n - 1;
        int mid = -1;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (ans[mid] == x)
                break;
            if (ans[mid] > x)
                r = mid-1;
            else
                l = mid + 1;
        }
           cout << (l<=r?mid:-1) << endl;
    }
}