#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[500], s2[500];
int len1, len2;
void solve();
int main()
{
    while (scanf("%s %s", s1, s2) == 2) {
        len1 = strlen(s1);
        len2 = strlen(s2);
        solve();
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
    }
    return 0;
}

void solve()
{
    int i;
    for (i = 0; i < len1; i++) {
        int j = 0;
        while (s1[i + j] + s2[j] < '2' + '2' && s2[j]) {j++;}
        if (j == len2) break;
    }
    int result = max(len1, len2 + i);
    for (i = 0; i < len2; i++) {
        int j = 0;
        while (s2[i + j] + s1[j] < '2' + '2' && s1[j]) {j++;}
        if (j == len1) break;
    }
    result = min(result, max(len2, len1 + i));
    printf("%d\n", result);
}