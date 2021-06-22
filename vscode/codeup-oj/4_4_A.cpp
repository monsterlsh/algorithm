#include <iostream>
#include <algorithm>
using namespace std;
struct tv
{
    int begin, end;
} lists[100];
bool cmp(const tv &a, const tv &b)
{
    if (a.begin == b.begin)
        return a.end < b.end;
    return a.begin > b.begin;
}
int n;
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    while (scanf("%d", &n) && n)
    {
        tv node = {0, 0};
        fill(lists, lists + n, node);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &lists[i].begin, &lists[i].end);
        }
        sort(lists, lists + n, cmp);
        int cn = 1;
        int next = 1, thiss = 0;
        while (next<n)
        {
            if (lists[next].end <= lists[thiss].begin)
            {
                cn++;
                thiss = next;
                next++;
            }
            else
                next++;
        }
        printf("%d\n", cn);
    }
}