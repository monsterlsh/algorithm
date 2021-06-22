#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <climits>
using namespace std;
int alls[100000] = {0},maxs=0;
unordered_set<int> ss;

void fn(int n){
    int pre = ss.size(),aft=0;
    do
    {
        if(n>maxs) maxs=n;
        ss.emplace(n);
        aft=ss.size();
        if(aft==pre)break;
        pre = aft;
        cout<<n<<endl;
        n = n%2==1?n>>1:(3*n+1);
    } while (n>1);
    
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    for(int i=3;i<=100;i++){
        fn(i);
        cout<<"nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn"<<endl;
    }
    cout<<maxs<<endl;
}
