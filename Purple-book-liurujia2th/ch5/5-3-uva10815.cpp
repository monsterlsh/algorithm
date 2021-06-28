#include<iostream>
#include<algorithm>
#include<string>
#include<cctype>
#include<map>
using namespace std;
#define RE
int main(){
    #ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    string str,key;
    map<string,bool> res;
    while(cin>>str){
    size_t i=0;
    key = "";
    while(i++<str.size()){
        if(isalpha(str[i-1]))key+= str[i-1];
        key[key.size()-1]=tolower(key[key.size()-1]);
    }
    res[key]=1;
    }
    for(auto it=res.begin();it!=res.end();it++)
        printf("%s\n",it->first.c_str());
}