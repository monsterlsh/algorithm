#include <iostream>
#include <vector>
#include<cstring>
#include<unordered_set>
using namespace std;

typedef pair<int, int> pa;
vector<int> mks(1002);
int lists[100002]={0};
vector<unordered_set<int>> incompatible(100002);
int main()
{

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, m, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        incompatible[x].insert(y);
        incompatible[y].insert(x);
       // incompatible[y]=x;    
    }
    while (m--)
    {
        memset(lists,0,sizeof(int)*100002);
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &mks[i]);
            lists[mks[i]] = 1;
        }
        bool flag = true;
        for (int i = 0; i < k && flag; i++)
        {
            if (!incompatible[mks[i]].empty() )
            {
                for(unordered_set<int>::iterator it = incompatible[mks[i]].begin();it!=incompatible[mks[i]].end();it++){
                    if(lists[*it]) {flag = false;break;}
                }
               
            }
            if(!flag)break;
        }

        printf("%s",flag?"Yes\n":"No\n");
    }
}
