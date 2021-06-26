#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str, str2;
        int occur[1010][105] = {0};
        int m, n, wrong;
        cin >> m >> n;
        wrong = m * n;
        while (m--)
        {
            cin >> str;
            for (unsigned i = 0;i != str.size();++i)
                ++occur[i][str[i]];
        }
        for (unsigned i = 0; i != str.size(); ++i)
        {
            int ma[2] = {'A',occur[i]['A']};
            for (unsigned j = 0; j != 105; ++j)
                if (occur[i][j] > ma[1])
                {
                    ma[0] = j;
                    ma[1] = occur[i][j];
                }
            wrong -= occur[i][ma[0]];
            str2 += ma[0];
        }
        cout << str2 << endl << wrong << endl;
    }
    return 0;
}