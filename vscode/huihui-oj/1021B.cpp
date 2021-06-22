#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int stacks[21]={0};

void fn();
void fn(){
    stacks[0]=1;
    stacks[1]=1;
    stacks[2]=2;
    for(int i = 3;i<=20;i++){
        for(int j=0;j<i;j++){
            stacks[i] += stacks[j]*stacks[i-j-1];
        }
        //if(i%2==1)stacks[i]+=stacks[i/2]*stacks[i/2];
    }
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    fn();
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",stacks[n]);
    }
}