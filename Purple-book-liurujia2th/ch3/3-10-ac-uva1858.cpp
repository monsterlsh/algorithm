#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
pair<int, int> p[6];
int i;
int main()
{
    while (1)
    {
        for (int i = 0; i < 6; i++)
        {
            if (!(cin >> p[i].first >> p[i].second))
                return 0;
            if (p[i].first > p[i].second)
                swap(p[i].first, p[i].second);
        }
        sort(p, p + 6); //按照首先first递增，其次second递增排序
        puts(p[0].first == p[1].first && p[0].first == p[2].first && p[0].first == p[3].first &&
                     p[2].second == p[3].second && p[2].second == p[4].second && p[2].second == p[5].second &&
                     p[0].second == p[1].second && p[0].second == p[4].first && p[0].second == p[5].first
                 ? "POSSIBLE"
                 : "IMPOSSIBLE");
    }
    return 0;
}
