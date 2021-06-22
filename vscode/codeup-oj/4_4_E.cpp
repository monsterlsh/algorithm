
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct
{
    int J;
    int F;
    double rate;
}CatJ;

bool cmp(CatJ a, CatJ b)
{
    return a.rate > b.rate;
}

int main()
{
#ifdef _DEBUG
    //freopen("data.txt", "r+", stdin);
    fstream cin("in.in");
#endif // _DEBUG
    const int MaxN = 1010;
    int M, N;
    CatJ catj[MaxN];
    double remain;
    while (cin >> M >> N, !(M == -1 && M == -1))
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> catj[i].J >> catj[i].F;
            catj[i].rate = (double)catj[i].J / catj[i].F;
        }

        sort(catj, catj + N, cmp);

        remain = 0;
        for (int i = 0; M > 0 && i < N; ++i)
        {
            if (catj[i].F <= M)
            {
                M -= catj[i].F;
                remain += catj[i].J;
            }
            else
            {
                remain += (double)M/catj[i].F * catj[i].J;
                M = 0;
            }
        }

        printf("%.3f\n", remain);
    }

#ifdef _DEBUG
    cin.close();
#ifndef _CODEBLOCKS
    system("pause");
#endif // !_CODEBLOCKS
#endif // _DEBUG

    return 0;
}

