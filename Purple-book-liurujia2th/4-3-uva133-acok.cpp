
/**
 * https://vjudge.net/problem/UVA-133
 * 
 * ShuoHao Lin
 */

#include <iostream>
#include <cstring>
using namespace std;
#define RE
size_t arr[20];
//size_t res[21];
size_t n, k, m,dex, fir = 0, sec = n - 1;

size_t stepk(size_t now, bool flag)
{
    size_t i = now, j = 0;
    while (flag && j<k)
    {
        while (arr[i] == 0)
            i = (i + 1) % n;
        j++;
        if(j<k)
        i = (i + 1) % n;
    }
    while (!flag && j<m)
    {
        while (arr[i] == 0)
            i = (i + n - 1) % n;
        j++;
        if(j<m)
        i = (i + n - 1) % n;
    }
    return i;
}

int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

    while (scanf("%zd%zd%zd", &n, &k, &m) && n && k && m)
    {
        memset(arr, 0, sizeof(arr));
        //memset(res, 0, sizeof(res));
        dex = 0;
        fir = 0, sec = n-1;
        for (; dex < n; dex++)
            arr[dex] = dex+1;
        dex = 0;
        while (dex <n)
        {
            fir = stepk(fir, true);
            sec = stepk(sec, false);
            if(fir==sec) {
                dex++;
                printf("%3zd%s", arr[fir],dex==n?"\n":",");
            }
            else  {
                dex+=2;
                printf("%3zd%3zd%s", arr[fir],arr[sec],dex==n?"\n":",");
            }
            arr[fir ] = 0;
            arr[sec] = 0;
            fir = (fir+1)%n;
            sec = (sec + n-1)%n;
        }
        
    }
}
