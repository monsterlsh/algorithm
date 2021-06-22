#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string>res;
    vector<bool>v;
    vector<string> permutation(string s) {
        v.resize(s.length());
        fill(v.begin(),v.end(),0);
        string tmp ="";
         for(int j = 0;j<s.length();j++){
            v[j]=1;
            tmp += s[j];
            backtrace(s,tmp);
            v[j]=0;
            tmp.erase(tmp.length()-1,1);
         }
    }
    void backtrace(string & s,string & tmp){
        if(tmp.length()==s.length()){
            res.emplace_back(tmp);
            return;
        }
        for(int j = 0;j<s.length();j++){
            if(!v[j]){
            v[j]=1;
            tmp += s[j];
            backtrace(s,tmp);
            v[j]=0;
            tmp.erase(tmp.length()-1,1);
            }
            
        }
    }
};