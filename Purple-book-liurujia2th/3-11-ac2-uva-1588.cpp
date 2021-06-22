#include<stdio.h>
#include<string.h>
#define maxn 105
#include <iostream>
using namespace std;

int findmax(char* a,char *b){
    int ans1 =0   ,     flag = 0;

    for(int i = 0; i < strlen(a); i++){
        flag = 0;
        for(int j = 0; j < min(strlen(a) - i, strlen(b)); j++){
            if(a[i+j] == b[j] && b[j] == '2'){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            ans1 = max(strlen(a), strlen(b) + i);
            break;
        }
    }
    if(!ans1){
        ans1 = strlen(a) + strlen(b);
    }
    return ans1;
}
int main(){
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif // LOCAL
    char a[maxn], b[maxn];
    while(scanf("%s\n%s", a, b) == 2){
        printf("%d\n",min(findmax(a,b),findmax(b,a)));
    }
    return 0;
}