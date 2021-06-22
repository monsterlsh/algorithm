#pragma GCC optimize(3, "Ofast", "inline")
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define all(x) (x).begin(), (x).end()
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        string str;
        for (size_t i = 1; i <= n; i++)
        {
            str += to_string(i);
        }
        for (size_t i = '0'; i < '9'; i++)
        {
            cout << count(all(str), i) << " ";
        }
        cout << count(all(str), '9') << endl;
    }
    return 0;
}