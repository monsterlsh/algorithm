//http://codeup.hustoj.com/problem.php?cid=100000575&pid=3
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF ){
        int odd,even,tmp;
        while(n--){
            scanf("%d",&tmp);
            if(tmp&1==1)odd++;
            else even++;
            
        }
        if(odd>=even)cout<<"YES\n";
        else cout<<"NO\n";
    }
}