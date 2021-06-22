#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string themax(vector<string>&s){
    string res = "";
    if(s.empty())return res;
    sort(s.begin(),s.end());
    for(int i=s.size()-1;i>=0;i--){
        res += s[i];
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    vector<string>s(n);
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        s[i]=tmp;
    }
    cout<<themax(s)<<endl;
}