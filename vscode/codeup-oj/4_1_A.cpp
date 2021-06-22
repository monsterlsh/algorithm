#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &res[i]);
        }
        sort(res.begin(), res.end());
        printf("%d\n",res[--n]);
        for (int i = 0; i < n; i++)
        {
            printf("%d%s", res[i], i == n - 1 ? "\n" : " ");
        }
        if(n==0) printf("-1\n");
    }
}