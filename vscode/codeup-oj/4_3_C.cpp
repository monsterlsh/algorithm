#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
class Solution{
    private: int n,k;
            vector<int>bags;
            int counts,sums;
            vector<bool>flagbag;
            vector<int>tests;
            int testidx;
    public: 
        void init(){
            n=40;
            bags.clear();
            while( scanf("%d",&k)!=EOF){
                testidx=0;
                tests.resize(k);
                fill(tests.begin(),tests.end(),0);
               
                counts=0;
                sums=0;
                bags.resize(k);
                flagbag.resize(k);
                fill(flagbag.begin(),flagbag.end(),0);
               
                for(int i=0;i<k;i++){
                    scanf("%d",&bags[i]);
                }
                backtrace(0);
                printf("%d\n",counts);
            }
        }
        void backtrace(int idx){
            if(sums==n){
                for(auto i:tests) printf("%d ",i);
                printf("\n");
                counts++;
                return;
            }
            for(int i=idx;i<k;i++){
                if(!flagbag[i]){
                    flagbag[i]=1;
                    sums+=bags[i];
                    tests[testidx++]=i+1;
                    backtrace(i+1);
                    tests[--testidx]=0;
                    sums-=bags[i];
                    flagbag[i]=0;
                }
            }
        }
        
       

};
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    Solution a;
    a.init();
}