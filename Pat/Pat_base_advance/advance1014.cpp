#include<iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k, q;
    //int customers[1002];
    int yellow[1002][1002];
    int windows[1002]={0};
    int behind[1002]={0};
    int res[1002]={0};
    int w = 1, y = 1, b = 1, yw = 1;
    int next = 1, front = 1;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (w <= n)
        {
            windows[w++] = tmp;
        }
        else if (y <= m && yw <= n)
        {
            yellow[yw][y++] = tmp;
        }
        else if (y > m && yw < n)
        {
            yw++;
            y = 1;
            yellow[yw][y] = tmp;
        }
        else
            {
                behind[b++] = tmp;
                
            }
        
    }
    int index[1002];
    fill(index, index + 1002, 1);
    bool timeok = true;
    while (front <= k && timeok)
    {
        int min = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (windows[i] > 0 && windows[i] < min)
                min = windows[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (windows[i] > 0)
                windows[i] -= min;
            else continue;
          
             if (windows[i] == 0 )
            {
                if((next>b&&yellow[i][(index[i] %( m + 1))]!=0)||next<=b){
                     windows[i] = yellow[i][(index[i] % (m + 1))];
                     yellow[i][(index[i] %( m + 1))] = behind[next++];
                     index[i]++;
                }
               
                res[front] = res[front - 1] + min;
                if (res[front] > 540)
                {
                    timeok = false;
                    break;
                }
                front++;
            }
        }
        min = INT_MAX;
    }

    for (int i = 0; i < q; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(tmp>k || tmp<=0){
            printf("Sorry\n");
            continue;
        }
        tmp = res[tmp];
        if(tmp>540 || tmp==0)
        {
            printf("Sorry\n");
            continue;
        }
        int hour = 8+tmp/60;
        int mins= tmp%60;
        if(hour<10)printf("0%d:",hour);
        else printf("%d:",hour);
        if(mins<10)printf("0%d\n",mins);
        else printf("%d\n",mins);
        
    }
}