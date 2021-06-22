#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int times(string & str){
    int hour = stoi(str.substr(0,2));
    int minus = stoi(str.substr(2,2));
    int  second  = stoi(str.substr(6,2));
    return hour*3600+minus*60+second;
}
vector<pair<int,int>>peop;
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    return a.first < b.first;
}
int main(){
    
    cin>>n;
    while(n--){
        string str1,str2;
        cin>>str1>>str2;
        pair<int,int> a;
        a.first = times(str1);
        a.second=times(str2);
        peop.emplace_back(a);
    }
    sort(peop.begin(),peop.end(),cmp);
    int sum=0,end =0 ,maxsum=-1;
    for(int j=0;j<peop.size();j++){
            sum = 0;
        for(int i=j;i<peop.size();i++){
            if(peop[i].first>=end){
            end = peop[i].second;
            sum++;
            if(sum>maxsum)maxsum = sum;
         }
    }
    }
    
    cout<<maxsum<<endl;
}