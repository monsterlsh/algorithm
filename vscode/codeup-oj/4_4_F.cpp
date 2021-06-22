#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS


int main()
{
#ifdef _DEBUG
    //freopen("data.txt", "r+", stdin);
    fstream cin("data.txt");
#endif // _DEBUG

    const int MaxN = 110;
    int N, P[MaxN], n, V, W,allP,index;
    while (cin >> N)
    {
        while (N--)
        {
            cin >> n >> V >> W;
            for (int i = 0; i < n; ++i)
                cin >> P[i];

            sort(P, P + n);

            for (index = 0,allP = 0; index < n; ++index)
            {
                if ((double)(allP + P[index]) / ((index + 1) * 100) >((double)W / 100))
                {
                    break;
                }
                allP += P[index];
            }

            printf("%d %.2f\n", index * V , index ? ((double)allP / (index * 100)) : 0.0);
        }
    }


#ifdef _DEBUG
    cin.close();
#ifndef _CODEBLOCKS
    system("pause");
#endif // !_CODEBLOCKS
#endif // _DEBUG

    return 0;
}

/**************************************************************
    Problem: 2143
    User: Sharwen
    Language: C++
    Result: 升仙
    Time:0 ms
    Memory:1708 kb
****************************************************************/