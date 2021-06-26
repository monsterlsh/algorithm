#include<iostream>
using namespace std;
int n ;
//ac
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%d",&n);
    getchar();
    while(n--){
        char c;
        int sum=0,pre=0;
        while(scanf("%c",&c)!=EOF && c !='\n'){
            if(c=='O'){
                sum += ++pre;
            }else pre=0;
        }
        printf("%d\n",sum);
        
    }
}