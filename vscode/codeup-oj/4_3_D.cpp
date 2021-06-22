//http://codeup.hustoj.com/problem.php?cid=100000583&pid=3
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
class Solution{
    private:vector<vector<int>>res;  
            vector<int>tmp;
            vector<int>p;
            vector<bool>table;
    public:
    int n;
        void backtreace(int index){
            if(index==n+1){
                res.emplace_back(tmp);
                return ;
            }
            for(int i=1;i<=n;i++){
                if(test(i,index)){
                    tmp.emplace_back(i);
                    table[i]=1;
                    p[index]=i;
                    backtreace(index+1);
                    //p[index]=0;
                    table[i]=0;
                    tmp.pop_back();
                }
            }
        }
        bool test(int col,int row){
            if(table[col])return false;
            for(int pre = 1;pre<row;pre++){
                if(abs(row-pre) == abs(col-p[pre])) return false;
            }
            return true;
        }
        void init(){
            
            table.resize(n+1);
            p.resize(n+1);
        }
        void print(int index){
            if(index >=res.size())return ;
            for(int i=0;i<res[index].size();i++){
                cout<<res[index][i];
            }
            
             printf("\n");
        }
};
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    Solution ans;
    ans.n=8;
    ans.init();
    ans.backtreace(1);
    int n,k;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        ans.print(k-1);
    }
}