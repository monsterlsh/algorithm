#include <cstdio>
#include <cmath>
typedef long long LL;
int main()
{
    LL n;
    while (~scanf("%lld", &n))
    {
        //（2n！)/{(n+1)(n!)^2}
        LL i, ans = 1 * pow(2, (n + 1) / 2), j = 1;
        for (i = 2 * n - 1; i > n; i -= 2)
            ans = ans * i / j++;
        printf("%lld\n", ans / (n + 1));
    }
    return 0;
}
