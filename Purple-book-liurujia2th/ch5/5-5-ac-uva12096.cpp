#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
#define RE

using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;
int ID(Set x)
{
    if (IDcache.count(x))
        return IDcache[x];
    Setcache.emplace_back(x);
    return IDcache[x] = Setcache.size() - 1;
}
int main()
{
     #ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    stack<int> s;
    int n, t;
    while (cin >> t)
    {
        cin >> n;
        IDcache.clear();Setcache.clear();
        while (n--)
        {
            string op;
            cin >> op;
            if (op[0] == 'P')
                s.push(ID(Set()));
            else if (op[0] == 'D')
                s.push(s.top());
            else
            {
                Set x1 = Setcache[s.top()];
                s.pop();
                Set x2 = Setcache[s.top()];
                s.pop();
                Set x;
                if (op[0] == 'U')
                    set_union(ALL(x1), ALL(x2), INS(x));
                if (op[0] == 'I')
                    set_intersection(ALL(x1), ALL(x2), INS(x));
                if (op[0] == 'A')
                {
                    x = x2;
                    x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << Setcache[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
}