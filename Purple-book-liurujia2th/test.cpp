#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
//#define RE
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
vector<size_t>nums={1,2,3,};
vector<size_t>num1={1,2,3};
size_t a[]={1,2,3};
size_t b[]={1,2,3};
map<vector<size_t>,size_t> resv;
map<size_t *,size_t>resarr;
resv[nums]=1;
//nums[0]=99;
resv[num1]=2;
resarr[a]=1;
a[0]=10000;
resarr[a]=2;
for(auto it=resv.begin();it!=resv.end();it++){
    cout<<" key ";
    for(auto is=it->first.begin();is!=it->first.end();is++){
        cout<<" "<<*is<<" ";
    }
    cout<<" value "<<it->second<<" ";
}
for(auto it=resarr.begin();it!=resarr.end();it++){
    cout<<" key " << it->first;
    cout<<" value "<<it->second<<" ";
}
}
