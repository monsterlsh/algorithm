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
    map<vector<size_t>,string> res;
    while(cin>>str && str!="#"){
        fill(nums.begin(),nums.begin()+54,0);
        for(size_t i=0;i<str.size();nums[str[i]-(islower(str[i])?'a':'A')]++,i++);
        auto it =res.find(nums);
        //cout<<"size:"<<res.size()<<endl;
        if(it!=res.end())res.erase(it);
        else res[nums]=str;
    }
    vector<string>out;
    for(auto it=res.begin();it!=res.end();out.emplace_back(it->second),it++);
    sort(out.begin(),out.end());
    for(string str:out)cout<<str<<endl;
}