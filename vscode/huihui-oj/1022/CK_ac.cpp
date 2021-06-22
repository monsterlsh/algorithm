#include<stdio.h>
#include<algorithm>
 
using namespace std;
 
int main()
{
     freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, i, j, flag, k;
    int a[1005];
    while(scanf("%d", &n), n != 0){
        flag = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        for(i = n-1; i >= 2; i--){
            for(j = i-1; j >= 1; j--){
                for(k = j-1; k >= 0; k--){
                    if(a[i]-a[j] == a[k]){
                        printf("%d\n", a[i]);
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(!flag)
            printf("no solution\n");
    }
    return 0;
}