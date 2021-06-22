#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int> s;
int n, m, k;
struct vertices
{
    int in;
    int out;
    vector<int> ous;
    bool visited = false;
} lists[1001];
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        lists[x].out++;
        lists[x].ous.emplace_back(y);
        lists[y].in++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (lists[i].in == 0)
            s.emplace_back(i);
    }
    scanf("%d", &k);
    int indx = 1;
    vector<int> res;
    while (indx <= k)
    {
        vector<int> queries(n);
        vector<vertices> tmp;
        for (int i = 1; i <= n; i++)
        {
            tmp.emplace_back(lists[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &queries[i]);
        }
        bool isok = false;
        for (int sindx = 0; sindx < s.size()&&!isok ; sindx++)
        {
            int first = s[sindx];
            //cout<<"first: "<<first<<"\n";
            int queryindex = 0;
            cout<<endl;
            if (first == queries[queryindex])
            {
                while (queryindex < queries.size() && first != -1)
                {
                   // cout << "first: " << queries[queryindex] << " ";
                    

                    tmp[first - 1].visited = true;
                    for (int i = 0; i < tmp[first - 1].ous.size(); i++)
                    {
                        tmp[tmp[first - 1].ous[i] - 1].in--;
                    }
                    first = -1;
                    for (int i = 0; i < tmp.size(); i++)
                    {
                        if (!tmp[i].visited && tmp[i].in == 0 && queries[queryindex] == i + 1)
                        {
                            first = i + 1;
                            cout<<first<<" ";
                            break;
                        }
                    }
                    queryindex++;
                }
                if(first!=-1 && queryindex == queries.size()) isok = true;
            }//if
        } //s
       // cout<<isok<<endl;
        if (!isok) res.emplace_back(indx);
        indx++;
    }
    for (int i = 0; i < res.size(); i++)
    {
        printf("%d%s", res[i], i != res.size() - 1 ? " " : "\n");
    }
}
