#include<iostream>
#include<algorithm>
#include<cctype>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
#define RE
int main(){
    #ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    vector<size_t> nums(54,0);
    string str;
    map<vector<size_t>,pair<string,bool>> res;
    while(cin>>str && str!="#"){
        fill(nums.begin(),nums.begin()+54,0);
        for(size_t i=0;i<str.size();nums[str[i]-(islower(str[i])?'a':'A')]++,i++);
        auto it =res.find(nums);
        //cout<<"size:"<<res.size()<<endl;
        if(it!=res.end())res[nums].second=0;
        else res[nums]=make_pair(str,1);
    }
    vector<string>out;
    for(auto it=res.begin();it!=res.end();it++)if(it->second.second)out.emplace_back(it->second.first);
    sort(out.begin(),out.end());
    for(string str:out)cout<<str<<endl;
}