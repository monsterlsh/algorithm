#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
unsigned n;
unsigned debt=0;
void backTrace(vector<unsigned>gamblers,int windex,
                    unsigned & sum,unsigned num,
                    vector<unsigned>&resindex,unsigned x){
    if(num>=3){
        for(unsigned i=0;i<n;i++){
             if(gamblers[i]==sum && debt<sum) debt = sum;
        }
        int i = resindex.back();
        resindex.pop_back();
        sum -= gamblers[i];
        backTrace(gamblers,windex,sum,num-1,resindex,i+1);
    }
    if(num==2 || num==1){
        if(x<n){
            sum += gamblers[x];
            resindex.emplace_back(x);
            backTrace(gamblers,windex,sum,num+1,resindex,x+1);
        }
        else{
            unsigned i = resindex.back();
            resindex.pop_back();
            sum -= gamblers[i];
            backTrace(gamblers,windex,sum,num-1,resindex,i+1);
        }
    }
    if(num==0){
        if(x<n){
                sum += gamblers[x];
                resindex.emplace_back(x);
                backTrace(gamblers,windex,sum,num+1,resindex,x+1);
        }else return;
    }
    
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    //fill(debt,debt+3*32768+4,false);
    while(scanf("%d",&n) && n){
        vector<unsigned>gamblers(n);
      
        for(unsigned i=0;i<n;i++){
            scanf("%d",&gamblers[i]);
        }
        vector<unsigned>resindex;
        unsigned sum = 0;
        backTrace(gamblers,0,sum,0,resindex,0);
        if(debt==0) printf("no solution\n");
        else printf("%d\n",debt);
        debt = 0;
    }


}