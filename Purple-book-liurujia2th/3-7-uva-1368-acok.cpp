#include <vector>
#include <iostream>
using namespace std;
#define RE
#define maxn 1010
char arr[55][maxn];
struct agct
{
    size_t a, g, c, t, mx;
    char who;
};
void fin(char ch, vector<agct> &diff, int j)
{

    switch (ch)
    {
    case 'A':
        diff[j].a++;
        if (diff[j].a >= diff[j].mx)
        {
            diff[j].who = ch;
            diff[j].mx = diff[j].a;
        }
        break;
    case 'T':
        diff[j].t++;
        if (diff[j].t > diff[j].mx )
        {
            diff[j].who = ch;
            diff[j].mx = diff[j].t;
        }
        break;
    case 'C':
        diff[j].c++;
        if (diff[j].c > diff[j].mx || (diff[j].c == diff[j].mx && diff[j].who!='A'))
        {
            diff[j].who = ch;
            diff[j].mx = diff[j].c;
        }
        break;
    case 'G':
        diff[j].g++;
        if (diff[j].g > diff[j].mx || (diff[j].c == diff[j].mx && diff[j].who!='A'&& diff[j].who!='C'))
        {
            diff[j].who = ch;
            diff[j].mx = diff[j].g;
        }
        break;
    }
}
//wrong
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    size_t t, m, n, resnum = 0;

    string res = "";
    scanf("%zd", &t);
    while (t--)
    {
        resnum = 0;
        res="";
        scanf("%zd %zd", &m, &n);
        getchar();
        vector<agct> diff(n);
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                arr[i][j] = getchar();
                fin(arr[i][j], diff, j);
                if (i == m - 1)
                {
                    res.push_back(diff[j].who);
                    resnum += m - diff[j].mx;
                }
            }
            getchar();
        }
        printf("%s\n%zd\n", res.c_str(), resnum);
    }
}
